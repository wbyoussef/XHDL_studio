//
// C++ Implementation: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "xhdlproj_man.h"

XhdlProj_man::XhdlProj_man()
{
	this->setCLASS_TAG("XhdlProj_man");
}


XhdlProj_man::~XhdlProj_man()
{
}


void XhdlProj_man::fillObject(XmlReader *xr)
{
  /*	
    name=xr->getAttribute("name");
    xr->moveTofirstChild();
    if(xr->getTagName()=="list_bus")
    {
    xr->moveTofirstChild();
    reset = new XhdlSignal;
    clk   = new XhdlSignal;
    while(xr->getTagName()=="signal")
    { 
    XhdlSignal *sig=new XhdlSignal;
    XmlReader *xr1= new XmlReader(xr);
    sig->fillObject(xr1);
    //looking for reset and clk signals
    if ((sig->is_reset) == true ) 
    reset=sig;
    else if ( (sig->is_clock) == true  )
    clk=sig;
    
    list_bus.push_back(sig);
    xr->moveToNextSibling();
    delete(xr1);
    }
    }
  */	
}
