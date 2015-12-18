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


#ifndef XHDL_INSTRUCTION_H
#define XHDL_INSTRUCTION_H

#include "XmlReader.h"
#include "xhdl_simple_instruction.h"
#include "xhdl_if_statement.h"

/**
@author walid
*/
#include <string>
#include <vector>
using namespace std;
class XhdlProcess ;
class xhdl_if_statement;


class xhdl_instruction : public xhdl_atom
{
public:
	XhdlProcess* get_parent_process();
    xhdl_instruction (XhdlProcess* parent);
    xhdl_instruction (xhdl_if_statement* parent);
    ~xhdl_instruction();
	void fillObject(XmlReader *xr);
     
	int type;     // 0- simple_instruction
                      // 1- if_statement
		      // 2- constant
		      // 3- signal
		      // 4- number
/*	string output; 
	xhdl_instruction * instr1;
	xhdl_instruction * instr2;
*/
	string output;
	xhdl_simple_instruction *simple_instruction;
	xhdl_if_statement* if_statement;
	

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    XhdlProcess* parent_process;
    xhdl_if_statement* parent_if_statement;
	bool is_root;
private :
    string CLASS_TAG;
};

#endif
