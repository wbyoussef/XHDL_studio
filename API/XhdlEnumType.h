// XhdlEnumType.h: interface for the XhdlEnumType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLENUMTYPE_H
#define XHDLENUMTYPE_H

#include "XmlReader.h"
#include "xhdl_atom.h"

#include <string>
#include <vector>

using namespace std;

class XhdlEnumType   : public xhdl_atom
{

public:
	XhdlEnumType();
	virtual ~XhdlEnumType();
	void fillObject ( XmlReader *xr ) ;

	string name ; // name of the enumerated type 
	vector <string> enumlist ; //list of possible occurence


    string getFull_name() const;
    void setFull_name(const string &value);

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    string full_name;
private :
    string CLASS_TAG;
};

#endif 
