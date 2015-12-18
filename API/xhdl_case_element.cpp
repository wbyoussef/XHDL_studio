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
#include "xhdl_case_element.h"

xhdl_case_element::xhdl_case_element()
{
    this->setCLASS_TAG("xhdl_case_element");
  
}


xhdl_case_element::~xhdl_case_element()
{
}
string xhdl_case_element::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void xhdl_case_element::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}



