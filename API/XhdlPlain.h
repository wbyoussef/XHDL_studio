// Xhdl_plain.h: interface for the Xhdl_plain class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLPLAIN_H
#define XHDLPLAIN_H

// #include<qdom.h>

#include<string>
using namespace std;
class XhdlBody;


class XhdlPlain  
{
public:
	XhdlPlain(XhdlBody  *body);
	virtual ~XhdlPlain();

	// data 
	string language;
	string *text;

private :
    // localisation 
	XhdlBody  * parent ;
};

#endif 
