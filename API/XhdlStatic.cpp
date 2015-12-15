// Xhdl_static.cpp: implementation of the Xhdl_static class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlStatic.h"
#include "ninja_defines.h"
#include "XhdlBody.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlStatic::XhdlStatic()
{
  
  
}

XhdlStatic::XhdlStatic(XhdlBody* parent)
{
  this->parent_body = parent;
  
}

void XhdlStatic::fillObject(XmlReader *xr)
{
  xr->moveTofirstChild();
  if ( xr->getTagName () == "affect")
    
    {
      aff =new XhdlAffectation ;
      aff->fillObject (xr);
      type = XHDLSTATIC_AFFECT;
      return ;
    }
}





XhdlStatic::~XhdlStatic()
{
  
}



