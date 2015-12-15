// XhdlChecker_Arch.cpp: implementation of the XhdlChecker_Arch class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlChecker_Arch.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlChecker_Arch::XhdlChecker_Arch()
{
  
}

bool XhdlChecker_Arch::check ( XhdlArch *ar , XhdlIp *ip)
{
  bool error_Notfound = true;
  string s="Architecture:[" + ar->name + "]->";
  error_log = s;
  error_Notfound = error_Notfound & check_Entity (ip->entity);
  error_Notfound = error_Notfound & check_Process_senslist ( ip , ar ) ;	
  error_Notfound = error_Notfound & check_archName(  ip );
  
  return error_Notfound;
  
}

bool XhdlChecker_Arch::check_archName (XhdlIp *ip)
{
  
  bool error_Notfound = true;
  string s ="";
  s = "Entity or Package " ;
  //TODO
  return  error_Notfound ;
  
  
}

bool XhdlChecker_Arch::check_Process_senslist ( XhdlIp *ip , XhdlArch *ar)
{
  bool error_Notfound = true;
  vector<XhdlProcess*> lp;
  lp = ar->body->list_process;
  int n =lp.size ();
  XhdlChecker_Process *pch ;
  while ( n )
    {
      pch = new XhdlChecker_Process;
      if (!pch->check_senlist_exist(ip,ar,lp.back()) )
	{
	  error_log = error_log + pch->error_log;
	  error_Notfound = false;
	}
      lp.pop_back (); 
      n --;
    }
  
  return error_Notfound;
  
  
}

bool XhdlChecker_Arch::check_Entity ( XhdlEntity *ent)
{
  
  XhdlChecker_Entity *entch = new XhdlChecker_Entity;
  
  if ( ! entch->check (ent) )
    {
      error_log += entch->error_log;
      return false;
    }
  return true;
  
  
  
}


XhdlChecker_Arch::~XhdlChecker_Arch()
{
  
}
