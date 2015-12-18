// XhdlPortMap.h: interface for the XhdlPortMap class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLPORTMAP_H
#define XHDLPORTMAP_H

#include "XmlReader.h"
#include<vector>
#include<string>
using namespace std;
#include "xhdl_atom.h"



class XhdlBody;

class XhdlPortMap    : public xhdl_atom
{
public:
	XhdlPortMap(XhdlBody  *body);
	virtual ~XhdlPortMap();

	struct connection 
	{
	   string formal;
	   string actual;
	};
	typedef struct connection connect;


	// Description 
	string label;
	string component_name;

	// Members 
 	vector <connect> list_connect ; //list of connections

	// deserialization
	void fillObject( XmlReader *xr);

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    // localisation
    XhdlBody  * parent ;

private :
    string CLASS_TAG;

};

#endif 
