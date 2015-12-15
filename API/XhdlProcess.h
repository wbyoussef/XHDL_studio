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

class XhdlProcess  
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

private :
	XhdlBody* parent_body;
};

#endif 
