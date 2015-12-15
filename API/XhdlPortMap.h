// XhdlPortMap.h: interface for the XhdlPortMap class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLPORTMAP_H
#define XHDLPORTMAP_H

#include "XmlReader.h"
#include<vector>
#include<string>
using namespace std;



class XhdlBody;

class XhdlPortMap  
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

private :
    // localisation 
	XhdlBody  * parent ;


};

#endif 
