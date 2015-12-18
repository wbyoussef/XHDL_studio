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
#ifndef XHDL_SIMPLE_INSTRUCTION_H
#define XHDL_SIMPLE_INSTRUCTION_H
#include "XmlReader.h"
/**
@author walid
*/

#include "xhdl_atom.h"
class xhdl_instruction;

class xhdl_simple_instruction  : public xhdl_atom
{
public:
	xhdl_instruction * get_parent_instruction();
	struct node{
		xhdl_simple_instruction *simple_instruction1;
		xhdl_simple_instruction *simple_instruction2;
		string op;
	};typedef struct node xhdl_combined_instruction;

    xhdl_simple_instruction(xhdl_instruction* instruction);
    xhdl_simple_instruction(xhdl_simple_instruction* simple_instruction);

    ~xhdl_simple_instruction();
    void fillObject(XmlReader *xr);
    
    int type;	// 0 : xhdl_combined_instruction
    		// 1 : signal
		// 2 : number
		// 3 : null
    
    xhdl_combined_instruction *combined_instruction ;
    string signal;
    string number;
    string null;
    
    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    xhdl_instruction *parent_instruction;
    xhdl_simple_instruction *parent_simple_instruction;
    bool is_root;
private :
    string CLASS_TAG;
};

#endif
