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

#ifndef XHDL_IF_STATEMENT_H
#define XHDL_IF_STATEMENT_H
#include <string>
#include <vector>
#include "XmlReader.h"
#include "xhdl_atom.h"

using namespace std;
class xhdl_instruction;
class XhdlExpression;
/**
@author walid
*/
class xhdl_if_statement : public xhdl_atom
{
public:
    xhdl_if_statement();

    ~xhdl_if_statement();
    void fillObject(XmlReader *xr);
    	
	XhdlExpression *condition;
	vector<xhdl_instruction*> true_instruntion;
	vector<xhdl_instruction*> false_instruntion;

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    string CLASS_TAG;
};

#endif
