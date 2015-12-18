// Xhdl_package.h: interface for the Xhdl_package class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLPACKAGE_H
#define XHDLPACKAGE_H
// #include<qdom.h>
#include "XhdlSignal.h"
#include<string>
#include<vector>
using namespace std;

class XhdlPackage   : public xhdl_atom
{
public:
	XhdlPackage();
	void fillObject (XmlReader *xr);
	virtual ~XhdlPackage();
	
public:
	string name;
	vector<XhdlSignal*> list_bus;
    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    string CLASS_TAG;
};

#endif 
