// Xhdl_body.cpp: implementation of the Xhdl_body class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlBody.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlBody::XhdlBody(XhdlArch* arch)
{
  parent = arch ; 
}


/////////////////////////////////////////////////////////////////////////////////
//				fill current object										       //
//																			   //
/////////////////////////////////////////////////////////////////////////////////

void XhdlBody::fillObject(XmlReader *xr)
{
  
  xr->moveTofirstChild();
  
  // list of port mapping ?									       
  if(xr->getTagName()=="list_maps")
    {
      if (xr->moveTofirstChild())
	{
	  XmlReader *xr2= new XmlReader(xr);	
	  while ( xr2->getTagName() == "port_map" )
	    {
	      XmlReader *xr1= new XmlReader(xr2);
	      XhdlPortMap *pm  = new XhdlPortMap (this) ;
	      pm->fillObject( xr1 );
	      list_maps.push_back( pm );
	      xr2->moveToNextSibling();	
	    }
	  
	  xr->moveToParent();
	}
      xr->moveToNextSibling();
    }
  
  // list of static assignement	?							       
  if(xr->getTagName()=="list_stat")
    {
      XmlReader *xr2= new XmlReader(xr);
      xr2->moveTofirstChild();
      
      
      while(xr2->getTagName()=="static")
	{   
	  XmlReader *xr1= new XmlReader(xr2);
	  XhdlStatic *stat=new XhdlStatic;
	  stat->fillObject(xr1);
	  list_stat.push_back(stat);			
	  xr2->moveToNextSibling();
	  delete(xr1);
	}
      
      
      delete (xr2);
      xr->moveToNextSibling();
      
    }
  
  
  //				list of process ?										       
  
  
  
  if(xr->getTagName()=="list_process")
    {   
      XmlReader *xr2= new XmlReader(xr);
      
      xr2->moveTofirstChild();
      string f= xr2->getTagName();
      
      while(xr2->getTagName()=="process")
	{   
	  XmlReader *xr3= new XmlReader(xr2);
	  XhdlProcess *process=new XhdlProcess(this);
	  process->fillObject(xr3);
	  list_process.push_back(process);			
	  xr2->moveToNextSibling();
	  delete(xr3);
	}
      
      xr->moveToNextSibling();
      
    }
  
  
}

XhdlBody::~XhdlBody()
{
  
}
