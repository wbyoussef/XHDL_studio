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
    

    string getFull_name() const;
    void setFull_name(const string &value);

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    XhdlBody* parent_body;


private :
    string full_name;
    string CLASS_TAG;
};

#endif 
