// XhdlEnumType.cpp: implementation of the XhdlEnumType class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlEnumType.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlEnumType::XhdlEnumType()
{
	this->setCLASS_TAG("XhdlEnumType");
  
}

void XhdlEnumType::fillObject ( XmlReader *xr )
{
  
  
  /*================name=====================**/
  
  
  name = xr ->getAttribute ("name");
  xr->moveTofirstChild ();
  
  /*==============enum list ================**/
  
  
  
  if ( xr->getTagName () == "enumlist" )
    {
      xr->moveTofirstChild ();
      
      while ( xr->getTagName () == "id" )
	{
	  xr->moveTofirstChild () ;
	  enumlist.push_back ( xr->getTextData () ) ;
	  xr->moveToParent ();
	  xr->moveToNextSibling ();
	}
      
      
    }
  
}
string XhdlEnumType::getFull_name() const
{
    return full_name;
}

void XhdlEnumType::setFull_name(const string &value)
{
    full_name = value;
}
string XhdlEnumType::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlEnumType::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}



XhdlEnumType::~XhdlEnumType()
{
    
}
