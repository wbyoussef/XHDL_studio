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

#define XHDLSTATIC_AFFECT 1 			// static assgn type is affect

#define XHDLEXPRESSION_TYPE_SIG_NAME	1       //expression is signal name
#define XHDLEXPRESSION_TYPE_LITTERAL	2	//expression is
#define XHDLEXPRESSION_TYPE_NUMBER	3	//expression is
#define XHDLEXPRESSION_TYPE_OP_EXPR	10	//expression is
#define XHDLEXPRESSION_TYPE_EXPR	20	//expression is

#define XHDLSEQUENCE_TYPE_AFFECT	1	//expression is
#define XHDLSEQUENCE_TYPE_IF		2	//expression is
#define XHDLSEQUENCE_TYPE_CASE		3	//expression is
#define XHDLSEQUENCE_TYPE_RANGE_LITT	41	//expression is
#define XHDLSEQUENCE_TYPE_RANGE		42		//expression is

#define XHDL_INSTRUCTION_TYPE_SIMPLE    0
#define XHDL_INSTRUCTION_TYPE_IF	1

#define XHDL_SIMPLE_INSTRUCTION_COMBINED	0
#define XHDL_SIMPLE_INSTRUCTION_SIGNAL		1
#define XHDL_SIMPLE_INSTRUCTION_NUMBER		2
#define XHDL_SIMPLE_INSTRUCTION_NULL		3
