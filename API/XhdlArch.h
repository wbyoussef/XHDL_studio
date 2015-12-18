// XhdlArch.h: interface for the Xhdl_arch class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLARCH_H
#define XHDLARCH_H

#include "XhdlEnumType.h"
#include "XhdlSignal.h"
// #include "XhdlBody.h"
#include "XmlReader.h"
#include<string>
#include<vector>

using namespace std;
class XhdlIp;
class XhdlBody;
class XhdlArch   : public xhdl_atom
{
public:
    XhdlArch(XhdlIp* ip);
	virtual ~XhdlArch();

    // localisation variables !
	XhdlIp* parent ; 

	// Description
	string name;
	string type;

	// Members 
	vector<XhdlEnumType*> list_enumtype ;
	vector<XhdlSignal*> list_bus;    
    XhdlBody *body;
	vector<XhdlSignal*> xml_signals;

    // deserialisation fonction
	void fillObject(XmlReader *xr);

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
