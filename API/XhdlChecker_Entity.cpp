// XhdlChecker_Entity.cpp: implementation of the XhdlChecker_Entity class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlChecker_Entity.h"
#include "XhdlClasses.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlChecker_Entity::XhdlChecker_Entity()
{
  
}

bool XhdlChecker_Entity::check (XhdlEntity *ent)
{
  
  error_log = "entity[" + ent->name + "]\n";
  return check_sig (ent);
  
  
  
}



bool XhdlChecker_Entity::check_sig ( XhdlEntity *ent)
{
  bool error_Notfound = true;
  string s="";
  vector <XhdlSignal*> lb;
  lb = ent->list_bus;
  int n = lb.size ();
  vector<XhdlSignal*>::const_iterator iter;
  
  string current;
  while ( n )
    {
      current = lb.back()->name;  
      lb.pop_back(); 
      n--;
      
      for ( iter = lb.begin() ; iter!= lb.end() ; iter++)
	if ( current == (*iter)->name )
	  {
	    error_Notfound = false;
	    s = s + "\tsignal [" + current + "] already exists \n";
	  }
      
    }
  
  error_log += s;		
  return error_Notfound;
}

XhdlChecker_Entity::~XhdlChecker_Entity()
{
  
}
