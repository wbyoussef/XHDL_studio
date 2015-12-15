// XhdlEnumType.cpp: implementation of the XhdlEnumType class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlEnumType.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlEnumType::XhdlEnumType()
{
  
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

XhdlEnumType::~XhdlEnumType()
{
  
}
