// XhdlChecker_Process.h: interface for the XhdlChecker_Process class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLCHECKER_PROCESS
#define XHDLCHECKER_PROCESS

#include "XhdlIp.h"
#include "XhdlArch.h"
#include "XhdlBody.h"
class XhdlChecker_Process  
{
public:
	XhdlChecker_Process();
	virtual ~XhdlChecker_Process();
	bool check_senlist_exist (XhdlIp *ip ,XhdlArch *ar, XhdlProcess *p);
	string error_log;

};

#endif 
