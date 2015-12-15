// XhdlPortMap.cpp: implementation of the XhdlPortMap class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlPortMap.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlPortMap::XhdlPortMap(XhdlBody  *body)
{
  parent = body;
}

//////////////////////////////////////////////////////////////////////
// fill current object
//////////////////////////////////////////////////////////////////////

void XhdlPortMap::fillObject ( XmlReader *xr)
{
  xr->moveTofirstChild();
  // label
  if ( xr->getTagName() == "label" )
    {
      xr->moveTofirstChild();
      label = xr->getTextData();
      xr->moveToParent();
    }
  
  //	component name
  xr->moveToNextSibling();
  if ( xr->getTagName() == "component_name" )
    {
      xr->moveTofirstChild();
      component_name = xr->getTextData();
      
      xr->moveToParent();
    }
  //list of connections
  xr->moveToNextSibling();
  string f = xr->getTagName();
  if ( xr->getTagName() == "list_connect" )
    {
      xr->moveTofirstChild();
      connect temp;
      while (xr->getTagName() == "connect" )
	{
	  xr->moveTofirstChild();
	  if (xr->getTagName() == "formal")
	    {
	      xr->moveTofirstChild();
	      temp.formal = xr->getTextData();
	      xr->moveToParent();
	    }
	  xr->moveToNextSibling();
	  if (xr->getTagName() == "actual")
	    {
	      xr->moveTofirstChild();
	      temp.actual = xr->getTextData();
	      xr->moveToParent();
	    }
	  xr->moveToParent();
	  xr->moveToNextSibling();
	  list_connect.push_back(temp);
	}
    }
}

XhdlPortMap::~XhdlPortMap()
{
  
}
