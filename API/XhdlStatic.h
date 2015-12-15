// Xhdl_static.h: interface for the Xhdl_static class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLSTATIC_H
#define XHDLSTATIC_H


#include "XmlReader.h"
#include "XhdlAffectation.h"
#include<string>
#include<vector>
using namespace std;
class XhdlBody;
class XhdlStatic  
{

	

public:
	XhdlStatic();
	XhdlStatic(XhdlBody* parent);
	virtual ~XhdlStatic();
	XhdlAffectation *aff;
	int type;

	void fillObject(XmlReader *xr);
    

private :
	XhdlBody* parent_body;



};

#endif 
