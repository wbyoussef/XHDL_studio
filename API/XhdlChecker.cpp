// XhdlChecker.cpp: implementation of the XhdlChecker class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlChecker.h"
#include "string.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlChecker::XhdlChecker()
{
  
}

char* XhdlChecker::checkIp ( XhdlIp *ip)
{
  
  bool error_Notfound = true;
  
  string s="IP->";
  
  XhdlChecker_Arch *check_arch = new XhdlChecker_Arch;
  
  vector <XhdlArch*> la ;
  la = ip->list_arch ;
  int n = la.size();
  while ( n )
    {
      if (!check_arch->check(la.back() , ip ))
	{
	  s += check_arch->error_log;
	  error_Notfound = false;
	}
      la.pop_back(); 
      n--;
    }
  if ( error_Notfound )
    return "ip checked succefully ";
  
  char r[1000];
  
  strcpy ( r , s.c_str() );
  return r;
  
}

XhdlChecker::~XhdlChecker()
{
  
  
}
