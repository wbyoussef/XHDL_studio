// XhdlChecker_Arch.h: interface for the XhdlChecker_Arch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLCHECKER
#define XHDLCHECKER

#include "XhdlIp.h"
#include "XhdlChecker_Process.h"
#include "XhdlChecker_Entity.h"

class XhdlChecker_Arch  
{
public:
	XhdlChecker_Arch();
	bool check (XhdlArch *ar , XhdlIp *ip);
	virtual ~XhdlChecker_Arch();
	string error_log;
private:
	bool check_archName(XhdlIp *ip); //check if entity or package name already exists
	bool check_Process_senslist (XhdlIp *ip ,XhdlArch *ar ) ;	
    bool check_Entity ( XhdlEntity *ent);


};

#endif 
