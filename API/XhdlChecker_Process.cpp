// XhdlChecker_Process.cpp: implementation of the XhdlChecker_Process class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlChecker_Process.h"
#include "XhdlEntity.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlChecker_Process::XhdlChecker_Process()
{
  
}

bool XhdlChecker_Process::check_senlist_exist (XhdlIp *ip , XhdlArch *ar,XhdlProcess *p)
{
  
  vector <XhdlSignal*> lsig;
  vector <string> sens_list;
  vector <string> sig_notfound;
  sens_list = p->sens_list;
  int n = sens_list.size ();
  int i;
  bool sig_found;
  
  while (n)
    {
      
      
      lsig = ip->entity->list_bus;
      i= lsig.size();
      sig_found = false;
      while ( i )
	{
	  if ( lsig.back()->name == sens_list.back() )
	    {
	      sig_found = true;
	      goto check;
	    }
	  i--;
	  lsig.pop_back(); 
	}
      
      lsig = ar->list_bus;
      i = lsig.size();
      while ( i )
	{
	  
	  if ( lsig.back()->name == sens_list.back () )
	    {
	      sig_found = true;
	      goto check;
	    }
	  
	  lsig.pop_back();
	  i--;
	  
	}
      lsig = p->declarations;
      i = lsig.size ();
      while ( i )
	{
	  if ( lsig.back()->name == sens_list.back() )
	    {
	      sig_found = true;
	      goto check;
	    }
	  
	  lsig.pop_back(); 
	  i--;
	  
	}
      
    check:	if ( !sig_found )
      sig_notfound.push_back (sens_list.back() );
      
      sens_list.pop_back(); 
      n--;
    }
  
  if ( sig_notfound.size() )
    {
      string s;
      s = "Process[" + p->label + "] sensitivity list\n";
      n = sig_notfound.size ();
      while (n)
	{
	  s = s + "\tSignal \'" + sig_notfound.back () + "\' not Found\n";
	  sig_notfound.pop_back (); 
	  n--;
	}
      error_log += s;
      return false;//error_Notfound;
      
    }
  return true;
  
  
}

XhdlChecker_Process::~XhdlChecker_Process()
{
  
}


