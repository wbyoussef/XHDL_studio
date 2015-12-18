#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#endif


#include "ninja_checker.h"
#include "Xhdl_tcl_interface.h"
#include "XhdlClasses.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <regex.h>
//#include <regex>

#include <stdio.h>
#include <string.h>

void test (void)
{
};


bool are_equal_strings (const char* s1, const char* s2)
{
  if ( simplify_white_spaces(string(s1)) ==  simplify_white_spaces ( string (s2) ) )
    {
      return  true;
    } else
      {
	return false;
      }
  
}

bool check_string_regexmatch (const char* regexpression, const char* string_to_match)
{
  ///
#ifdef WIN32
  return match (regexpression, string_to_match);
  /// if(query_match(string_to_test.c_str(), string_to_test.c_str() + strlen(string_to_test.c_str()), what, expression))
  ///  return true;
  /// else
  ///   return false;
#else 
  // regex expression (regexpression);
  string string_to_test = string_to_match;

  // cmatch what;

  int result;
  regmatch_t match;
  regex_t compiled;
  // compile the regular expression
  result = regcomp (&compiled, regexpression, REG_EXTENDED | REG_ICASE | REG_NOSUB);
  if (result)
    {
      char errorstring[128];
      regerror (result, &compiled, errorstring, sizeof(errorstring));
      printf ("regexp error: %s\n", errorstring);
      regfree (&compiled);
      return (false);
    }
  result = regexec (&compiled, string_to_test.c_str(), 1, &match, 0);
  regfree (&compiled);
  if (result == 0)
    return (true);
  else
    return (false);
  
  
#endif
}

int nb_occurences (const char* str1, const char* str2)
{
  int nb_occ = 0;
  //tokenize str2
  vector<string> words_list ;
  Tokenize (str2, words_list);
  for (int i = 0; i< words_list.size(); i++)
    {
      if (are_equal_strings (str1,words_list[i].c_str()))
        nb_occ ++; 
    }
  // count nb_occ
  return nb_occ;
}




check_result_t* ip_check_duplicated_signals (XhdlIp* ip)
{
  string *signal_list = new string (get_all_signals (ip));
  string *out_rep  = new string ("");
  vector<string> signals;
  Tokenize (*signal_list, signals);
  check_result_t* out_check = new check_result_t;
  
  out_check->passed = true;
  
  for (int i =0; i< signals.size(); i++)
    {
      for (int j = i+1 ; j< signals.size(); j++)
	{
	  if (signals [i] == signals [j])
	    {
	      *out_rep += "Error:";
	      *out_rep += signals [j] ;
	      *out_rep += " is duplicated with ";
	      *out_rep += signals [i] ;
	      *out_rep += " \n ";
	    } 
	}
    }
  out_check->report = new string (*out_rep);
  return out_check;
};



check_result_t* ip_check_duplicated_processes (XhdlIp* ip, const char* arch_name)
{
  string *signal_list = new string (get_all_processes (ip,arch_name));
  string *out_rep  = new string ("");
  vector<string> processes;
  Tokenize (*signal_list, processes);
  check_result_t* out_check = new check_result_t;
  
  out_check->passed = true;
  
  for (int i =0; i< processes.size(); i++)
    {
      for (int j = i+1 ; j< processes.size(); j++)
	{
	  if (processes [i] == processes [j])
	    {
	      *out_rep += "Error:";
	      *out_rep += processes [j] ;
	      *out_rep += " is duplicated with ";
	      *out_rep += processes [i] ;
	      *out_rep += " \n ";
	    } 
	}
    }
  out_check->report = new string (*out_rep);
  return out_check;
};



const char * report_ip_check_duplicated_signals (XhdlIp* ip)
{
  return (ip_check_duplicated_signals(ip))->report->c_str(); 
};


bool check_label_name ( const char * sig_name )
{
  string tmp;
  tmp = sig_name;
  tmp = simplify_white_spaces (tmp); 
  if ( check_string_regexmatch ("[a-z,A-Z]+", tmp.c_str() ))
    return true;
  else 
    return false; 
};

check_result_t* ip_check_label_names ( XhdlIp *ip , const char *arch_name)
{
  check_result_t* out_check = new check_result_t;
  out_check->passed = true;
  int err_nbr = 0 ;
  string *outrep = new string ( "" );
  vector <string> labels ;
  vector <string>::const_iterator iter ;
  string *label_list = new string (get_all_labels ( ip , arch_name ));
  std :: cout << "collected labels :" << *label_list<< "\n" ;
  Tokenize( *label_list , labels );
  std :: cout << "labels list.size() = " << labels.size () << "\n" ;
  for ( iter = labels.begin() ; iter != labels.end() ; iter++ )
    {
      if ( !check_label_name ( (*iter).c_str() ) ) 
	{
	  *outrep += (*iter) + " " ;
	  err_nbr ++ ;
	}
    }
  std :: cout << "error number = " << err_nbr << "\n" ;
  if ( err_nbr == 0 )
    out_check->report = new string ("labels name checked succeffully\n");
  else
    {
      string *tmp_string = new string ("");
      if ( err_nbr == 1 )
	*tmp_string =  string ("invalid label : ");
      else
	*tmp_string =  string ( "invalid labels : ");
      *tmp_string += *outrep ;
      *outrep = *tmp_string ;
    }
  std :: cout << "returning result = report = " << *outrep <<  "\n\n";
  out_check->report = outrep ;
  return out_check;     
  
}

const char* report_ip_check_label_names (XhdlIp *ip , const char * arch_name)
{ 
  return ( ip_check_label_names  ( ip , arch_name )-> report->c_str() ) ;
}

bool is_valid_type ( XhdlIp *ip , const char *arch_name  , const char * type )
{
  /* vector <XhdlEnumType*>::const_iterator e_iter ;
     vector <XhdlEnumType*> enum_list = get_enum_types ( ip , arch_name );
     vector <string> type_list;
     
     for ( e_iter = enum_list.begin () ; e_iter != enum_list.end () ; e_iter ++ )
     type_list.push_back ( (*e_iter)->name );
     type_list.push_back ( "integer");
     type_list.push_back ( "float"); 
     regmatch_t pmatch[1];
     regex_t preg;
     vector<string>::const_iterator iter;
     string *tmp_pattern;
     for ( iter = type_list.begin () ; iter != type_list.end () ; iter ++ )
     {
     string sig_type = string ( type );
     string::size_type lastPos = sig_type.find_first_not_of(" ", 0);    
     string::size_type pos     = sig_type.find_first_of(" ", lastPos);   
     sig_type = (sig_type.substr(lastPos, pos - lastPos)).c_str();
     type = sig_type.c_str () ;
     tmp_pattern = new string() ;
     *tmp_pattern = string("^") + (*iter) + string("$") ;
     if ( regcomp (&preg, tmp_pattern->c_str() ,  REG_ICASE) == 0 )       
     if ( regexec ( &preg , type , 1 , pmatch , 0) == 0 ) 
     return true;
     }
     
     
  */      
  return false;
  
  
}

check_result_t* ip_check_signals_type( XhdlIp *ip , const char* arch_name )
{
  
  check_result_t* out_check = new check_result_t;
  out_check->passed = true;
  int err_nbr = 0 ;
  string *outrep = new string ( "" );
  vector <XhdlSignal*>::const_iterator iter ;
  vector <XhdlSignal*> sig_list;
  
  sig_list = get_signals ( ip , arch_name );
  for ( iter = sig_list.begin () ; iter != sig_list.end () ; iter ++ )
    { 
      if ( ! (*iter)->type.empty() && !is_valid_type ( ip , arch_name , (*iter)->type.c_str() )  )
	{
	  *outrep += (*iter)->type ;
	  *outrep += " in signal "  ;
	  *outrep += (*iter)->name + "\n" ;
	  err_nbr++;
	}
    }
  
  if ( err_nbr == 0 )
    {
      out_check->report = new string ("\ntypes check passed succefully");
      return out_check ;
    }
  
  string *tmp_string ;
  if ( err_nbr == 1 )
    tmp_string = new string ( "invalid type : \n " );
  else 
    tmp_string = new string ( "invalid types : \n" );
  
  *tmp_string += *outrep;
  *outrep = *tmp_string ;
  
  out_check->report = outrep;
  return out_check;
}

const char * report_ip_check_signals_type( XhdlIp *ip , const char* arch_name )
{
  return ( ip_check_signals_type ( ip , arch_name )->report->c_str() );
}



bool is_duplicated ( XhdlIp *ip , const char* arch_name ,const char* instance1)
{
    ///
    return true;
    /*
  int err_nbr = 0 ;  
  string *name_list = new string ();
  *name_list = get_all_labels ( ip, arch_name );
  vector <string> label_list;
  Tokenize ( *name_list , label_list );
  //elliminate white spaces
  string tmp_instance = string ( instance1 ); 
  instance1 = simplify_white_spaces ( tmp_instance ).c_str () ;
  regmatch_t pmatch[1];
  regex_t preg;
  string *tmp_pattern ;
  vector <string>::const_iterator iter ;
  for ( iter = label_list.begin () ; iter != label_list.end () ; iter++ )
    {
      tmp_pattern = new string() ;
      *tmp_pattern = string("^") + simplify_white_spaces(*iter) + string("$") ;
      if ( regcomp (&preg, tmp_pattern->c_str() ,  REG_ICASE) == 0 )       
	if ( regexec ( &preg , instance1 , 1 , pmatch , 0) == 0 ) 
	  err_nbr++;
    }
  
  return ( err_nbr > 1  ) ;
  */
}



check_result_t* ip_check_duplicated_instances (XhdlIp *ip , const char * arch_name )
{
  check_result_t* out_check = new check_result_t () ;
  out_check->passed = true;
  int err_nbr = 0 ;
  
  string *outrep = new string ();
  string *label_string = new string ();
  // get all labels 
  *label_string = get_all_labels ( ip , arch_name );
  *label_string = string ( remove_duplicateds ( label_string->c_str()) ) ;
  vector <string> label_list ;
  vector <string>::const_iterator iter ;
  Tokenize ( *label_string , label_list );
  for ( iter = label_list.begin () ; iter != label_list.end () ; iter++ )
    if ( is_duplicated ( ip , arch_name , (*iter).c_str() ) )
      {
	*outrep += (*iter) + " " ;
	err_nbr ++ ;
      }
  
  if ( !err_nbr ) 
    {
      out_check->report = new string ("duplicated instance check passed succefully");
      return out_check ;
    }
  string *tmp_string ;
  if ( err_nbr == 1 )
    tmp_string = new string ( "These label is duplicated : \n");
  else if ( err_nbr > 1 )
    tmp_string = new string ( "Those labels are duplicated : \n");
  
  *tmp_string += *outrep ;
  *outrep = *tmp_string ;
  
  out_check->report = outrep ;
  return out_check ; 
}


const char * report_ip_check_duplicated_instances ( XhdlIp *ip , const char * arch_name )
{
  return ( ip_check_duplicated_instances ( ip , arch_name )->report->c_str() ) ;
}


check_result_t* ip_check_unknown_signals (XhdlIp *ip , const char * arch_name )
{
  check_result_t* out_check = new check_result_t();
  out_check->passed = true;
  string *outrep  = new string ("");
  int err_nbr = 0;
  string *signal_string = new string ();
  *signal_string = string (get_all_static_inout ( ip , arch_name ));
  *signal_string += string (get_all_process_inout ( ip , arch_name )) ;
  *signal_string = string ( remove_duplicateds( signal_string->c_str() )) ;
  
  vector <string>::const_iterator iter;
  vector <string> signal_list ;
  Tokenize ( *signal_string , signal_list );
  
  for ( iter = signal_list.begin () ; iter != signal_list.end () ; iter++ )
    {
      if ( !does_inout_exist ( ip , (*iter).c_str() ) &&  !does_signal_exist ( ip , arch_name , (*iter).c_str() ) ) 
	{
	  *outrep += (*iter) + " " ;
	  err_nbr ++ ;
	}
    }
  
  if ( !err_nbr )
    {
      out_check->report = new string ( "unknown signals check passed succefully");
      return out_check;
    }
  
  string *tmp_string ; 
  if ( err_nbr == 1 ) 
    tmp_string = new string ( "unknown signal: \n");
  else
    tmp_string = new string ( " unknown signals :\n");
  
  *tmp_string += *outrep;
  *outrep = *tmp_string;
  out_check->report = outrep;
  return out_check;
}


const char * report_ip_check_unknown_signals ( XhdlIp *ip , const char * arch_name )
{
  return ( ip_check_unknown_signals ( ip , arch_name )->report->c_str () ) ;
} 



check_result_t* ip_check_entity (XhdlIp *ip )
{
  check_result_t* out_check = new check_result_t();
  out_check->passed = true;
  string *outrep  = new string ("");
  
  // check entity name 
  if (!(check_label_name(((ip->entity)->name).c_str()) ))
    {
      out_check->passed = false;
      *outrep =  "ERROR : Invalid entity name : ";
      *outrep += ip->entity->name;
      out_check->report = outrep;
      return out_check;
    }
  //loop for checking signals 1 by one
  vector <XhdlSignal*>::const_iterator iter;
  for ( iter = (ip->entity->list_bus).begin()  ; iter != (ip->entity->list_bus).end () ; iter ++ ) 
    {
      //---> check signal name  
      check_result_t* tmp_check = check_io_signal_structure (*iter);
      if(!(tmp_check->passed))
	{
	  return tmp_check; 
	}
      //---> check signal duplication in entity (entity name, signals, parameters and other signals)
      // get all labels (parameters, other ios, )!
      
      //---> check signal duplication in all archs (loop)
    }
  
  
  
  *outrep =  "SUCCESS : entity test passed succefully";
  out_check->report = outrep;
  return out_check;
}

const char * report_ip_check_entity ( XhdlIp *ip)
{
  return ( ((ip_check_entity (ip))->report)->c_str () ) ;
  //return ""; 
}



check_result_t* check_io_signal_structure (const XhdlSignal *signal )
{
  check_result_t* out_check = new check_result_t();
  out_check->passed = true;
  string *outrep  = new string ("");
  
  // check name
  if (!(check_label_name((signal->name).c_str()) ))
    {
      out_check->passed = false;
      *outrep =  "ERROR : Invalid signal name : ";
      *outrep += signal->name;
      out_check->report = outrep;
      return out_check;
    }
  
  // check parameters
  if ((signal->is_bit == false) && ((signal->is_clock)||(signal->is_reset)))
    {
      out_check->passed = false;
      *outrep =  "ERROR : Signal  ";
      *outrep += signal->name;
      *outrep +=  "is not a bit and is used as a system signal.  ";
      out_check->report = outrep;
      return out_check;
    }
  
  out_check->report = outrep;
  return out_check;
  
}
// check whether a string matches a regular expression
bool match(const char *string,const char *pattern)
{
	int status;
        regex_t re;
#ifdef REGEX
	if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0)
	{
		return(false);
	}

	status = regexec(&re, string, (size_t) 0, NULL, 0);
	regfree(&re);
	if (status != 0)
	{
		return(false);
	}
	return(true);
#endif
return false;
}



