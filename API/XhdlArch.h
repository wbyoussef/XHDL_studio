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
class XhdlArch  
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
};

#endif
