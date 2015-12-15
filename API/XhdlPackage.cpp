// Xhdl_package.cpp: implementation of the Xhdl_package class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlPackage::XhdlPackage()
{
  
}

void XhdlPackage::fillObject( XmlReader *xr)
{
  name=xr->getAttribute("name");
  xr->moveTofirstChild();
  if(xr->getTagName()=="list_bus")
    {
      xr->moveTofirstChild();
      while(xr->getTagName()=="signal")
	{ 
	  // UREGENT : link to IP !!
	  XhdlSignal *sig=new XhdlSignal(NULL);
	  XmlReader *xr1= new XmlReader(xr);
	  sig->fillObject(xr1);
	  list_bus.push_back(sig);
	  xr->moveToNextSibling();
	  delete(xr1);
	}
    }
  
  
}

XhdlPackage::~XhdlPackage()
{
  
}
