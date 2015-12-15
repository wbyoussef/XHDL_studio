// XhdlChecker.h: interface for the XhdlChecker class.
//
//////////////////////////////////////////////////////////////////////


#if !definedXHDLCHECKER_H
#define XHDLCHECKER_H

#include "XhdlIp.h"
#include "XhdlChecker_Arch.h"



class XhdlChecker  
{
public:
	XhdlChecker();
	char* checkIp( XhdlIp *ip);
	virtual ~XhdlChecker();
	string error_log;

};

#endif 
