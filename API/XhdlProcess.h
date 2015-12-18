// XhdlProcess.h: interface for the XhdlProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLPROCESS_H
#define XHDLPROCESS_H

#include "XmlReader.h"
#include "XhdlSequential.h"
#include "XhdlSignal.h"
#include "xhdl_instruction.h"
#include <vector>
#include <string>
using namespace std;

class XhdlBody;

class XhdlProcess   : public xhdl_atom
{
public:
	XhdlProcess(XhdlBody* parent);
	virtual ~XhdlProcess();
	
	// Description 
	string comment ; 
	string label ; 

	// members 
	vector <string> sens_list ; //sensitivity list
	vector <XhdlSignal *> declarations ; 
	vector <xhdl_instruction*> instructions; 

	// functions 
	XhdlBody* get_parent_body();
	// deserialisation 
	void fillObject(XmlReader *xr);

    string getFull_name() const;
    void setFull_name(const string &value);

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

private :
    XhdlBody* parent_body;
    string full_name;
private :
    string CLASS_TAG;
};

#endif 
