// XhdlChecker_Entity.h: interface for the XhdlChecker_Entity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLCHECKER_ENTITY_H
#define XHDLCHECKER_ENTITY_H

#include "XhdlEntity.h"

class XhdlChecker_Entity  
{
public:
	XhdlChecker_Entity();
	virtual ~XhdlChecker_Entity();
	
	bool check (XhdlEntity *ent);
	string error_log;

private:
	bool check_sig(XhdlEntity *ent);
};

#endif 
