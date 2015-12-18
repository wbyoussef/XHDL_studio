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
	this->setCLASS_TAG("XhdlStatic");
  
  
}

XhdlStatic::XhdlStatic(XhdlBody* parent)
{
  this->parent_body = parent;
  this->setCLASS_TAG("XhdlStatic");
  
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
string XhdlStatic::getFull_name() const
{
    return full_name;
}

void XhdlStatic::setFull_name(const string &value)
{
    full_name = value;
}
string XhdlStatic::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlStatic::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}







XhdlStatic::~XhdlStatic()
{
    
}



