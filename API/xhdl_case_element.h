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
#ifndef XHDL_CASE_ELEMENT_H
#define XHDL_CASE_ELEMENT_H
#include "xhdl_instruction.h"

#include <vector>
using namespace std;

/**
@author walid
*/
class xhdl_case_element : public xhdl_atom
{
public:
    xhdl_case_element();
    ~xhdl_case_element();
    
    vector<xhdl_instruction*> instructions;
    int value;
   
    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    string CLASS_TAG;
};

#endif
