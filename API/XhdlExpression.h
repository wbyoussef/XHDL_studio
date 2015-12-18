// XhdlExpression.h: interface for the XhdlExpression class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLEXPRESSION_H
#define XHDLEXPRESSION_H

#include "XmlReader.h"
#include <string>
#include <vector>
using namespace std;
#include "xhdl_atom.h"

class XhdlExpression   : public xhdl_atom
{
public:
	XhdlExpression();
	virtual ~XhdlExpression();
	void fillObject (XmlReader *xr);

	string sig_name ;
	string number ;
	string litteral ; 
	string op ;
	XhdlExpression *expr1 ; // op , expr1
        XhdlExpression *expr2 ; // expr2 , op , expr3
	XhdlExpression *expr3 ; // TODO : merge expression into expr1, expr2
	int type ; 
    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    string CLASS_TAG;

};

#endif 
