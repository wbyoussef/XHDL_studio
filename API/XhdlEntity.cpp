
#include "XhdlEntity.h"
#include "XhdlClasses.h"

// default constructor
XhdlEntity::XhdlEntity()
{
  name="";
  clk = NULL;
  this->setCLASS_TAG("XhdlEntity");
}

// constructor 
XhdlEntity::XhdlEntity(XhdlIp* ip)
{
  parent = ip; 
  clk = NULL;
  this->setCLASS_TAG("XhdlEntity");
}

// load entity from an XML reader 
void XhdlEntity::fillObject(XmlReader *xr)
{
  name=xr->getAttribute("name"); 
  xr->moveTofirstChild();
  
  if(xr->getTagName()=="list_params")
    {
      xr->moveTofirstChild();
      if (xr->getTagName()=="param")
	{
	  while(xr->getTagName()=="param")
	    {
	      xr->moveTofirstChild();                    
	      list_params.push_back(string(xr->getTextData()));
	      xr->moveToParent();
	      xr->moveToNextSibling();
	    }
	  xr->moveToParent (); 
	}
      xr->moveToNextSibling ();           
    }
  
  if(xr->getTagName()=="list_bus")
    {
      xr->moveTofirstChild();
      reset = new XhdlSignal (this->parent);
      clk   = new XhdlSignal (this->parent);
      while(xr->getTagName()=="signal")
	{ 
	  XhdlSignal *sig=new XhdlSignal(this->parent);
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
  
}
string XhdlEntity::getFull_name() const
{
    return full_name;
}

void XhdlEntity::setFull_name(const string &value)
{
    full_name = value;
}
string XhdlEntity::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlEntity::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}





// destructor
XhdlEntity::~XhdlEntity()
{
}


