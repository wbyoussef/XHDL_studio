// Xhdl_plain.h: interface for the Xhdl_plain class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLPLAIN_H
#define XHDLPLAIN_H

// #include<qdom.h>

#include<string>
#include "xhdl_atom.h"
using namespace std;
class XhdlBody;


class XhdlPlain   : public xhdl_atom
{
public:
	XhdlPlain(XhdlBody  *body);
	virtual ~XhdlPlain();

	// data 
	string language;
	string *text;

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    // localisation
    XhdlBody  * parent ;

private :
    string CLASS_TAG;
};

#endif 
