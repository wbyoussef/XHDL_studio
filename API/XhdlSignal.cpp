// Xhdl_signal.cpp: implementation of the Xhdl_signal class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlClasses.h"


// {{{ XhdlSignal::XhdlSignal()
/*
  XhdlSignal::XhdlSignal()
  {
  name         = ""    ;
  high_val     = 0     ;
  low_val      = 0     ;
  is_bit       = true  ;
  initial_val  = ""    ;
  is_flipflop  = false ;
  reference    = ""    ;
  comment      = ""    ;
  type         = ""    ;
  is_clock     = false ;
  is_reset     = false ;
  direction    = ""    ;
  reset        = ""    ;
  clock        = ""    ; 
  }
*/
// }}}


// {{{ XhdlSignal::XhdlSignal(XhdlIp *ip)

XhdlSignal::XhdlSignal(XhdlIp *ip)
{
  parent       = ip    ;
  name         = ""    ;
  high_val     = 0     ;
  low_val      = 0     ;
  is_bit       = true  ;
  initial_val  = ""    ;
  is_flipflop  = false ;
  reference    = ""    ;
  comment      = ""    ;
  type         = ""    ;
  is_clock     = false ;
  is_reset     = false ;
}

// }}}


// {{{ XhdlSignal::XhdlSignal(const XhdlSignal *sig , string ext )

XhdlSignal::XhdlSignal(const XhdlSignal *sig , string ext )
{
  
  name = sig ->name + ext ;
  high_val = sig->high_val ;
  low_val = sig->low_val;
  is_bit = sig ->is_bit ;
  initial_val = sig->initial_val;
  is_flipflop = false;
  reference = sig->reference ;
  comment = sig->comment ;
  type = sig->type;
  is_clock = sig->is_clock;
  is_reset = sig->is_reset;
  
  
}

// }}}

// {{{ XhdlSignal::~XhdlSignal()

XhdlSignal::~XhdlSignal()
{
  
}

// }}}

// {{{ void XhdlSignal::fillObject(XmlReader *xr)

void XhdlSignal::fillObject(XmlReader *xr)
{
  
  name=xr->getAttribute("name");
  xr->moveTofirstChild();
  
  /*=============type?===========================================**/
  string f = xr->getTagName ();
  if(xr->getTagName()=="stype")
    {
      if (xr->moveTofirstChild()){
	type=xr->getTextData();
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="direction")
    {
      if (xr->moveTofirstChild()){
	direction=xr->getTextData();
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="high_val")
    {
      if (xr->moveTofirstChild()){
	high_val=atoi((xr->getTextData()).c_str());
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="low_val")
    {
      
      if (xr->moveTofirstChild()) {
	low_val=atoi((xr->getTextData()).c_str());
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="is_bit")
    {
      
      if (xr->moveTofirstChild()) {
	is_bit = (xr->getTextData()== "TRUE")?true:false;
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  if(xr->getTagName()=="is_reset")
    {
      if (xr->moveTofirstChild()) {
	is_reset=(xr->getTextData()== "TRUE")?true:false;
	xr->moveToParent();
      }
      xr->moveToNextSibling();        
    }
  
  if(xr->getTagName()=="is_clock")
    {
      
      if (xr->moveTofirstChild()) {
        
	is_clock = (xr->getTextData()== "TRUE")?true:false;
	xr->moveToParent();
      }        
      xr->moveToNextSibling();        
    }
  
  if(xr->getTagName()=="initial_val")
    {
      if (xr->moveTofirstChild()) {
	initial_val=xr->getTextData();
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="is_flipflop")
    {
      if (xr->moveTofirstChild()) {
	is_flipflop = (xr->getTextData()== "TRUE")?true:false;
	xr->moveToParent();
      }
      xr->moveToNextSibling();        
    }
  
  if(xr->getTagName()=="reset")
    {
      if (xr->moveTofirstChild()) {
	reset=xr->getTextData();
	xr->moveToParent();
      }
      xr->moveToNextSibling();
    }
  
  if(xr->getTagName()=="clock")
    {
      if (xr->moveTofirstChild()) {
	clock=xr->getTextData();
	xr->moveToParent();
      }
      xr->moveToNextSibling();
      
    }
  
  if(xr->getTagName()=="reference")
    {
      if (xr->moveTofirstChild())
	{
	  reference=xr->getTextData();
	  xr->moveToParent();
	}
      xr->moveToNextSibling();
    }
  
  
  
  /*==============commentaire?=============================================**/
  
  
  if(xr->getTagName()=="comment")
    {
      
      xr->moveTofirstChild();
      
      comment=xr->getTextData();
      xr->moveToParent();
      
      
    }
  
  
  
  
}

// }}}

// {{{ void XhdlSignal::set_params ( ...... )

void XhdlSignal::set_params ( string name
			      ,string type
			      ,string direction
			      ,int high_val
			      ,int low_val
			      ,bool is_bit
			      ,bool is_reset
			      ,bool is_clock
			      ,string initial_val
			      ,bool is_flipflop
			      ,string reset
			      ,string clock
			      ,string reference
			      ,string comment
			      )
  
{
  
  this->name = name ;
  this->type = type ;
  this->direction = direction ;
  this->high_val = high_val ;
  this->low_val = low_val ;
  this->is_bit = is_bit ;
  this->is_reset = is_reset ;
  this->is_clock = is_clock ;
  this->initial_val = initial_val ;
  this->is_flipflop = is_flipflop ;
  this->reset = reset ;
  this->clock = clock ;
  this->reference = reference ;
  this->comment = comment ;
  
}

// }}}


