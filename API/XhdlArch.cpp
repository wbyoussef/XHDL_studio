// Xhdl_arch.cpp: implementation of the Xhdl_arch class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlArch.h"
#include "XhdlClasses.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlArch::XhdlArch(XhdlIp* ip)
{
  parent = ip;
  this->body = new XhdlBody (this); 
  this->setCLASS_TAG("XhdlArch");
  
  
}


void XhdlArch::fillObject(XmlReader *xr)
{
  
  name=xr->getAttribute("name");
  
  
  xr->moveTofirstChild();
  
  /*=================================type================================================**/
  
  
  if(xr->getTagName()=="type")
    {
      
      xr->moveTofirstChild();
      
      type=xr->getTextData();
      
      xr->moveToParent();
      
    }
  
  /*==================list of enumerated type ?============================================**/
  
  xr->moveToNextSibling();
  
  
  
  if(xr->getTagName()=="list_enumtype")
    {
      
      XmlReader *xr2= new XmlReader(xr);
      xr2->moveTofirstChild () ;
      
      
      
      while (xr2->getTagName () == "enumtype" )
	{
	  XmlReader *xr3 = new XmlReader(xr2) ; 
	  
	  XhdlEnumType *et = new XhdlEnumType; 
	  
	  et->fillObject ( xr3 ) ;
	  
	  list_enumtype.push_back ( et ) ;
	  
	  
	  delete (xr3);
	  xr2->moveToNextSibling () ;
	}
      
      
      delete (xr2);
      
      xr->moveToNextSibling();
      
    }
  
  /*==================list_bus ?===========================================================**/
  
  
  
  
  if(xr->getTagName()=="list_bus")
    {
      
      
      XmlReader *xr2= new XmlReader(xr);
      xr2->moveTofirstChild();
      
      while(xr2->getTagName()=="signal")
	{
	  XmlReader *xr1= new XmlReader(xr2);
	  XhdlSignal *sig=new XhdlSignal(this->parent);
	  sig->fillObject(xr1);
	  xml_signals.push_back (sig) ;
	  list_bus.push_back(sig);		  		
	  xr2->moveToNextSibling();
	  delete(xr1);
	}
      
      delete(xr2);
      
      
      xr->moveToNextSibling();
    }
  
  /*=====================body==========================================================**/
  
  if(xr->getTagName()=="body")
    {
      
      body=new XhdlBody(this);
      body->fillObject(xr);
      
    }
  
  
}
string XhdlArch::getFull_name() const
{
    return full_name;
}

void XhdlArch::setFull_name(const string &value)
{
    full_name = value;
}
string XhdlArch::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlArch::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}



XhdlArch::~XhdlArch()
{
    
}




