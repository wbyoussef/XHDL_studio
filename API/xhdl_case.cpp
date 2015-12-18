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
#include "xhdl_case.h"

xhdl_case::xhdl_case()
{
    this->setCLASS_TAG("xhdl_case");
//	vector <int> x;
//	x.clear();
}


xhdl_case::~xhdl_case()
{
}
string xhdl_case::getFull_name() const
{
    return full_name;
}

void xhdl_case::setFull_name(const string &value)
{
    full_name = value;
}
string xhdl_case::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void xhdl_case::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}




