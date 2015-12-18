// XhdlProcess.cpp: implementation of the XhdlProcess class.
//
//////////////////////////////////////////////////////////////////////
#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#endif



#include "XhdlProcess.h"
#include "XhdlBody.h"
#include "XhdlArch.h"


extern string itostring (int int_tmp);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlProcess::XhdlProcess(XhdlBody* parent)
{
  this->parent_body = parent;
  this->setCLASS_TAG("XhdlProcess");
}


void XhdlProcess::fillObject( XmlReader *xr)
{
  
  xr->moveTofirstChild();
  
  //---------------commentaire?------------------------------
  
  if ( xr->getTagName() == "comment" ) 
    {
      xr->moveTofirstChild();
      comment = xr->getTextData();
      xr->moveToParent();
      
      // xr->moveToNextSibling();
      //exit (0);
    }
  
  if ( xr->getTagName() == "comment" ) 
    {
      xr->moveToNextSibling();
    }
  //-----------------label------------------------------------
  
  
  if ( xr->getTagName() == "label" ) 
    {
      xr->moveTofirstChild();
      label = xr->getTextData();
      xr->moveToParent();
      
    }
  
  //---------------sensitivity list----------------------------
  
  xr->moveToNextSibling();
  
  if ( xr->getTagName() == "sens_list" )
    {
      
      xr->moveTofirstChild();
      
      XmlReader *xr1 = new XmlReader (xr);
      
      while ( xr1->getTagName() == "sig_name" ) 
	{
	  xr1->moveTofirstChild();
	  sens_list.push_back( xr1->getTextData() ) ;
	  
	  xr1->moveToParent();
	  xr1->moveToNextSibling();
	}
      
      xr->moveToParent();
      
    }
  
  
  //-------------declarations?-----------------------------------
  
  xr->moveToNextSibling();
  
  
  if ( xr->getTagName() == "declarations" )
    {
      
      
      
      XmlReader *xr1 = new XmlReader(xr);
      xr1->moveTofirstChild();
      while ( xr1->getTagName() == "signal" ) 
	{
	  XhdlSignal *sig=new XhdlSignal((((this->get_parent_body())->parent)->parent));
	  XmlReader *xr2= new XmlReader(xr1);
	  sig->fillObject(xr2);
	  
	  declarations.push_back (sig);
	  
	  xr1->moveToNextSibling();
	}
      
      xr->moveToNextSibling(); 
    }
  
  //-------------list of sequential statements--------------------
  
  if ( xr->getTagName() == "list_intsructions" )
    {
      
      xr->moveTofirstChild();
      
      while ( xr->getTagName() == "instruction" ) 
	{
	  xhdl_instruction *instruction =new xhdl_instruction(this);
	  XmlReader *xr4 = new XmlReader(xr);
	  instruction->fillObject (xr4);
	  instructions.push_back( instruction ) ;
	  
	  //this->label = this->label + "\n" + itostring( instructions.size()) ;
	  delete (xr4);
	  xr->moveToNextSibling();
	}
      
    }
  
}
string XhdlProcess::getFull_name() const
{
    return full_name;
}

void XhdlProcess::setFull_name(const string &value)
{
    full_name = value;
}
string XhdlProcess::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlProcess::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}







XhdlProcess::~XhdlProcess()
{
    
}




XhdlBody* XhdlProcess::get_parent_body()
{
    return parent_body;
}
