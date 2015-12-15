//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef XHDL_CASE_H
#define XHDL_CASE_H

/**
@author walid
*/
#include <string>
#include <vector>
using namespace std;
#include "xhdl_case_element.h"

class xhdl_case{
public:
    xhdl_case();

    ~xhdl_case();
     string  selector; 
     vector<xhdl_case_element*> cases;
};

#endif
