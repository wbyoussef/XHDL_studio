// Xhdl_plain.cpp: implementation of the Xhdl_plain class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlPlain.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlPlain::XhdlPlain(XhdlBody  *body)
{
  parent = body ;
  this->setCLASS_TAG("XhdlPlain");
}

XhdlPlain::~XhdlPlain()
{
  
}
string XhdlPlain::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlPlain::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}

