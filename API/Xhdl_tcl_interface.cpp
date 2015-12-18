// $Id: Xhdl_tcl_interface.cpp,v 1.1.1.1 2009-08-24 21:31:55 walid Exp $
// $Name:  $
// $ProjectName$

/**
 * @file Xhdl_tcl_interface.cpp
 *
 * _file_description_first_sentence_will_be_the_brief_description_
 *
 */


#include <stdio.h>
#include <stdarg.h>
#include "XhdlClasses.h"


#include <iostream>

#include <cassert>


using namespace std;
bool use_ieee_libs; 
bool use_folders; 


XhdlIp* main_ip;

// usefule functions
void Tokenize(const string& str, vector<string>& tokens,const string& delimiters);
const char* int_to_char (int x);

const char* remove_duplicateds (const char* data)
{
  vector <string> words_list ;
  string *word_to_parse = new string (data);
  string *return_data = new string("");  
  Tokenize ( *word_to_parse, words_list );
  
  
  
  vector <string> cleaned_words_list ;
  bool is_unique = true;
  for (int i = 0; i< words_list.size(); i++)
    {
      is_unique = true;
      for (int j = i+1; j< words_list.size(); j++)
	{
	  if (words_list[i] == words_list [j])
	    {
	      is_unique = false;
	    }
	}
      if (is_unique)
	{
	  *return_data += words_list[i];
	  *return_data += " ";
	} else 
	  {
	  }
    }
  
  
  return return_data->c_str();
}


string simplify_white_spaces ( string str ) 
{
  string *tmp_string = new string ( );
  string::size_type lastPos = str.find_first_not_of(" ", 0);    
  string::size_type pos     = str.find_first_of(" ", lastPos);   
  *tmp_string = (str.substr(lastPos, pos - lastPos));
  
  return *tmp_string ;
  
}





string open_folder (const char* folder_name) 
{ 
  string return_string;
  if (use_folders)
    {
      return_string = "--{{{ ";
      return_string += folder_name ;
      return_string += "\n" ;
    }
  return return_string;
}


string close_folder (const char* folder_name) 
{ 
  string return_string;
  if (use_folders)
    {
      return_string = "--}}} ";
      return_string += folder_name ;
      return_string += "\n" ;
    }
  return return_string;
}


void do_use_ieee_libs (){use_ieee_libs = true;}
void do_not_use_ieee_libs (){use_ieee_libs = false;}
bool are_ieee_libs_used () {return use_ieee_libs;}


void do_use_folders (){use_folders = true;}
void do_not_use_folders (){use_folders = false;}
bool are_folders_used () {return use_folders;}



void Tokenize(const string& str, vector<string>& tokens,const string& delimiters)
{
  // Skip delimiters at beginning.
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  string::size_type pos     = str.find_first_of(delimiters, lastPos);
  
  while (string::npos != pos || string::npos != lastPos)
    {
      // Found a token, add it to the vector.
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      // Skip delimiters.  Note the "not_of"
      lastPos = str.find_first_not_of(delimiters, pos);
      // Find next "non-delimiter"
      pos = str.find_first_of(delimiters, lastPos);
    }
}



const char* int_to_char (int x)
{
  char* tmp_char = new char();
  sprintf (tmp_char , "%d", x);
  return tmp_char;
}



XhdlIp* create_ip (char* name)
{
  XhdlIp *tmp_ip = new XhdlIp();
  ip_set_name (tmp_ip, name);
  tmp_ip->package->name = name; 
  return tmp_ip;
};



void ip_set_name (XhdlIp* ip, char* name)
{
  ip->entity->name = string (name);
}



const char* ip_get_name (const XhdlIp* ip)
{
  return ((ip->entity->name).c_str());
}



check_result_t * validate_xml_vs_dtd (const char* xml_name, const char* dtd_name) {
  xmlDocPtr xmldoc;
  xmlDtdPtr dtd;
  xmlValidCtxtPtr ctxt; 
  int valid;
  check_result_t* return_check_result = new check_result_t;
  string * tmp_report = new string;
  
  xmldoc = xmlParseFile (xml_name);  
  if (!xmldoc) { }
  
  const xmlChar * x = reinterpret_cast<const xmlChar*> (dtd_name) ;
  dtd = xmlParseDTD(NULL, x);
  
  if (!dtd) { }
  
  ctxt = xmlNewValidCtxt();
  if(!ctxt) { }
  
  valid = xmlValidateDtd(ctxt, xmldoc, dtd);
  
  return_check_result->passed = (valid == 1);
  
  *tmp_report += "Document validity : ";
  
  if (return_check_result->passed) 
    *tmp_report += "PASSED";
  else 
    *tmp_report += "FAILED";
  
  return_check_result->report = new string; 
  *(return_check_result->report) = *tmp_report;
  
  return return_check_result;
  
}



XhdlEntity* create_entity (char* name)
{
  XhdlEntity* tmp_entity = new XhdlEntity();
  tmp_entity->name = string (name);
  return tmp_entity;
}




const char * ip_get_documentation (const XhdlIp* ip )
{
  return ((ip->documentation).c_str());
};



void ip_set_documentation (XhdlIp* ip, const char * doc )
{
  ip->documentation = string (doc);       
};



XhdlEntity* ip_get_entity (XhdlIp* ip)
{
  return (ip->entity);
}



XhdlEntity* ip_set_entity (XhdlIp* ip, XhdlEntity* entity)
{
  XhdlEntity* old_entity = ip_get_entity(ip);
  ip->entity = entity;
  return old_entity;
}



bool ip_open_valid_xml_file (XhdlIp* ip,const  char *  filename, const char *  dtd_file)
{
  if (!((validate_xml_vs_dtd (filename, dtd_file))->passed))
    return false;
  ip->openXmlDoc(string (filename));
  ip->setIp();
  return true;
}



bool ip_open_xml_file (XhdlIp* ip, char *  filename)
{
  //if (validate_xml_vs_dtd (filename, "dtd.dtd"))
  //  return false;
  ip->openXmlDoc(string (filename));
  if ( ip->fileOpened == true)
    ip->setIp();
  else 
    return false;
  return true;
}



void ip_open_stream (XhdlIp* ip, const char * stream)
{
  ip->openXmlStream(const_cast <char *> (stream));
  ip->setIp();
}



const char* ip_describe_entity (XhdlIp* ip)
{
  string return_val ="";
  XhdlEntity* entity = ip_get_entity (ip);
  return_val = string (entity_describe(entity));
  return "";
}



const char* entity_describe (const XhdlEntity* entity)
{
  string return_val ="";
  return_val += string("IP name : ") + entity->name +  string(" ;\n");
  //return_val += string("IP name : ") + entity-> +  string(" ;\n");
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(entity->list_bus).begin(); iter != (entity->list_bus).end(); iter++)
    {
      // if ((&(*(*iter)))->name == signal->name)
      // return true;
    }
  return return_val.c_str();
}



bool entity_find_signal(XhdlEntity* entity, XhdlSignal* signal)
{
  vector<XhdlSignal*>::const_iterator iter;
  /// Iterate through list and output each element.
  for (iter=(entity->list_bus).begin(); iter != (entity->list_bus).end(); iter++)
    {
      if ((&(*(*iter)))->name == signal->name)
	return true;
    }
  return false;
}



bool entity_add_signal(XhdlEntity* entity, XhdlSignal* signal)
{
  if (entity_find_signal(entity,signal) )
    return false;
  (entity->list_bus).push_back(signal);
  return true;
}


const char* get_clocks (XhdlIp* ip)
{
  string *return_clocks = new string ("") ;
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      if ((&(*(*iter)))->is_clock)
	{
	  *return_clocks += (&(*(*iter)))->name;
	  *return_clocks += " ";
	} 
    }
  
  return return_clocks->c_str();
}    

const char* get_resets (XhdlIp* ip)
{
  string return_resets = "" ;
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      if ((&(*(*iter)))->is_reset)
	{
	  return_resets += (&(*(*iter)))->name;
	  return_resets += " ";
	} 
    }
  
  return return_resets.c_str();
}    


const char* get_normal_signals (XhdlIp* ip)
{
  string return_normal_signals = "" ;
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      if (!((&(*(*iter)))->is_clock) && !((&(*(*iter)))->is_reset))
	{
	  return_normal_signals += (&(*(*iter)))->name;
	  return_normal_signals += " ";
	} 
    }
  
  return return_normal_signals.c_str();
}    



/**
 * 
 * @param ip 
 * @return list of ip signals 
 */
const char* get_all_signals (XhdlIp* ip)
{
  string *return_all_signals = new string("") ;
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      *return_all_signals += (&(*(*iter)))->name;
      *return_all_signals += " ";
    }
  
  return return_all_signals->c_str();
}    



/**
 * 
 * @param ip 
 * @return list of ip params 
 */
const char* get_all_params (XhdlIp* ip)
{
  string *return_all_params = new string("") ;
  vector<string>::const_iterator iter;
  for (iter=(ip->entity->list_params).begin(); iter != (ip->entity->list_params).end(); iter++)
    {
      *return_all_params += *iter;
      *return_all_params += " ";
    }
  
  return return_all_params->c_str();
}    



/**
 * 
 * @param ip  
 * @param arch_name
 * @return list of architecture signals 
 */
const char* get_all_arch_signals (XhdlIp* ip , const char* arch_name)
{
  string *return_all_signals = new string ("");
  if ( ! does_arch_exist ( ip , arch_name ) ) 
    return return_all_signals->c_str();
  
  XhdlArch *arch = get_arch ( ip , arch_name );  
  vector <XhdlSignal*>::const_iterator iter ; 
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    {
      *return_all_signals += (*iter)->name ;
      *return_all_signals += " ";
    }
  
  return return_all_signals->c_str();
}



XhdlSignal* get_signal (XhdlIp* ip, const char* signal_name)
{
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      if (((&(*(*iter)))->name) == string (signal_name))
	{
	  return  (&(*(*iter)));
	  //return_resets += " ";
	} 
    }
  return NULL;
  //  return return_resets.c_str();
}    

vector <XhdlSignal*> get_signals (XhdlIp* ip, const char* arch_name )
{
  XhdlArch *arch = get_arch ( ip , arch_name );
  vector <XhdlSignal*>::const_iterator iter ;
  vector <XhdlSignal*> sig_list ;
  sig_list = ip->entity->list_bus;
  
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    sig_list.push_back ( (*iter ) );
  
  return sig_list ;
}      

vector<XhdlEnumType*> get_enum_types (XhdlIp* ip, const char* arch_name)
{ 
  XhdlArch *a = get_arch ( ip , arch_name );
  return a->list_enumtype;
}




bool does_inout_exist (XhdlIp* ip, const char* signal_name)
{
  vector<XhdlSignal*>::const_iterator iter;
  for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
    {
      if ( simplify_white_spaces((&(*(*iter)))->name) ==  simplify_white_spaces ( string (signal_name) ) )
	{
	  return  true;
	} 
    }
  return false;
}    



bool does_param_exist (XhdlIp* ip, const char* signal_name)
{
  vector<string>::const_iterator iter;
  for (iter=(ip->entity->list_params).begin(); iter != (ip->entity->list_params).end(); iter++)
    {
      if ( simplify_white_spaces(*iter) ==  simplify_white_spaces ( string (signal_name) ) )
	{
	  return  true;
	} 
    }
  return false;
}    


bool does_signal_exist (XhdlIp* ip, const char * arch_name ,const char* signal_name) 
{
  if ( ! does_arch_exist ( ip , arch_name ) )
    return false ;
  XhdlArch *arch = get_arch ( ip , arch_name );
  vector <XhdlSignal*>::const_iterator iter;
  string *sig_name = new string ( simplify_white_spaces ( string ( signal_name ) ) );
  
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    if ( simplify_white_spaces (*sig_name) == simplify_white_spaces ( (*iter)->name  ) ) 
      return true;
  
  return false;
}


XhdlSignal* get_signal (XhdlIp* ip, const char * arch_name ,const char* signal_name) 
{
  if ( ! does_arch_exist ( ip , arch_name ) )
    return NULL ;
  XhdlArch *arch = get_arch ( ip , arch_name );
  vector <XhdlSignal*>::const_iterator iter;
  string *sig_name = new string ( simplify_white_spaces ( string ( signal_name ) ) );
  
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    if ( simplify_white_spaces (*sig_name) == simplify_white_spaces ( (*iter)->name  ) ) 
      return (*iter);
  
  return get_signal (ip,signal_name);
  
  //return NULL;
}


XhdlArch* get_arch (XhdlIp* ip, const char* arch_name)
{
  vector<XhdlArch*>::const_iterator iter;
  for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
      if (((*iter)->name) == arch_name)
	{
	  return  *iter;
	} 
    }
  return NULL;
}    

XhdlPortMap* get_map (XhdlIp* ip, const char* arch_name,const char* map_name)
{
  XhdlArch * arch ;
  if (does_arch_exist (ip,arch_name)) 
    arch = get_arch(ip, arch_name);
  else
    return NULL;
  
  if (does_map_exist(ip,arch_name,map_name))
    {
      vector<XhdlPortMap*>::const_iterator iter;
      for (iter=(arch->body->list_maps).begin(); iter != (arch->body->list_maps).end(); iter++)
        {
     	  if ((&(*(*iter)))->label == map_name) 
	    return *iter;
        };
      
    } else 
      {
	return NULL;
      }
  
  
  
  /*
    vector<XhdlArch*>::const_iterator iter;
    for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
    if (((*iter)->name) == arch_name)
    {
    return  *iter;
    } 
    }*/
  return NULL;
}    

XhdlIp* include_map (XhdlIp* ip, const char* arch_name,const char* map_name)
{
  // TODO : add search paths
  string file_name = string (map_name) + string (".xml");
  XhdlIp *tmp_ip = new XhdlIp ();
  
  
  if (ip_open_xml_file(tmp_ip, const_cast <char *>  (file_name.c_str())))
    return tmp_ip;
  else 
    return NULL;
}    
bool does_arch_exist (XhdlIp* ip, const char* arch_name)
{
  vector<XhdlArch*>::const_iterator iter;
  for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
      if (((&(*(*iter)))->name) == arch_name)
	{
	  return  true;
	} 
    }
  return false;
}    

bool does_map_exist (XhdlIp* ip, const char* arch_name, const char* map_name)
{
  if (does_arch_exist(ip, arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlPortMap*>::const_iterator iter;
      for (iter=(arch->body->list_maps).begin(); iter != (arch->body->list_maps).end(); iter++)
	{
	  if ((&(*(*iter)))->label == map_name) 
	    return true;
	};
    }
  return false;
}    

bool does_stat_exist (XhdlIp* ip, const char* arch_name, const char* stat_name)
{
  if (does_arch_exist(ip, arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlStatic*>::const_iterator iter;
      for (iter=(arch->body->list_stat).begin(); iter != (arch->body->list_stat).end(); iter++)
	{
	  if ((&(*(*iter)))->aff->output == stat_name) 
	    return true;
	};
    }
  return false;
}    

const char* get_archs (XhdlIp* ip)
{
  string *return_archs = new string("") ;
  vector<XhdlArch*>::const_iterator iter;
  for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
      *return_archs += (&(*(*iter)))->name;
      *return_archs += " ";
    }
  
  return return_archs->c_str();
}    


const char* get_sub_blocks (XhdlIp* ip, const char* arch_name)
{
  XhdlArch* arch;
  if (does_arch_exist (ip, arch_name))
    arch = get_arch(ip, arch_name);
  string* out_rep = new string ("");
  //*out_rep += 
  vector<XhdlPortMap*>::const_iterator iter_maps;
  for (iter_maps=(arch->body->list_maps).begin(); iter_maps != (arch->body->list_maps).end(); iter_maps++)
    {
      *out_rep += (*iter_maps)->component_name; 
      *out_rep += " "; 
    };
  return out_rep->c_str();
}



bool rename_inout (XhdlIp* ip, const char* old_name, const char* new_name)
{
  if (!does_inout_exist (ip, old_name))
    return false;
  else 
    {
      XhdlSignal* tmp_signal = get_signal (ip, old_name);
      tmp_signal->name = new_name;
      return true;
    }
}




bool set_inout_params (XhdlIp* ip, const char* old_name
		       ,const char* name
		       ,const char* direction
		       ,int high_val
		       ,int low_val
		       ,bool is_bit
		       ,bool is_reset
		       ,bool is_clock
		       ,const char* reset
		       ,const char* clock
		       ,const char* reference
		       ,const char* comment
                       )
{
  if (!does_inout_exist (ip, old_name))
    return false;
  else 
    {
      XhdlSignal* tmp_signal = get_signal (ip, old_name);
      tmp_signal->set_params (  name
                                ,""
                                ,direction
                                ,high_val
                                ,low_val
                                ,is_bit
                                ,is_reset
                                ,is_clock
                                ,""
                                ,false
                                ,reset
                                ,clock
                                ,reference
                                ,comment
				);
      return true;
    }
};



const char* get_inout_comment (XhdlIp* ip, const char* signal_name)
{
  if (!does_inout_exist (ip, signal_name))
    return "ERROR : signal not found";
  else 
    {
      XhdlSignal* tmp_signal = get_signal (ip, signal_name);
      return tmp_signal->comment.c_str();
    }
  
}



bool set_inout_comment (XhdlIp* ip, const char* signal_name, const char* new_comment)
{
  if (!does_inout_exist (ip, signal_name))
    return false;
  else 
    {
      XhdlSignal* tmp_signal = get_signal (ip, signal_name);
      tmp_signal->comment = string (new_comment);
      return true;
    }
  
}



bool remove_inout (XhdlIp* ip, const char* signal_name)
{
  if (!does_inout_exist (ip, signal_name))
    return false;
  else 
    {
      vector<XhdlSignal*>::iterator iter;
      for (iter=(ip->entity->list_bus).begin(); iter != (ip->entity->list_bus).end(); iter++)
	{
	  if (((&(*(*iter)))->name) == signal_name)
	    {
	      (ip->entity->list_bus).erase(iter);
	      break;
	    }
	}
      
      return true;
    }
  
}



bool add_inout (XhdlIp* ip
		,const char* name
		,const char* direction
		,int high_val
		,int low_val
		,bool is_bit
		,bool is_reset
		,bool is_clock
		,const char* reset
		,const char* clock
		,const char* reference
		,const char* comment
		)
{
  if (does_inout_exist (ip, name))
    return false;
  else 
    {
      XhdlSignal* tmp_signal = new XhdlSignal(ip);
      tmp_signal->set_params (  name
                                ,""
                                ,direction
                                ,high_val
                                ,low_val
                                ,is_bit
                                ,is_reset
                                ,is_clock
                                ,""
                                ,false
                                ,reset
                                ,clock
                                ,reference
                                ,comment
				);
      ip->entity->list_bus.push_back(tmp_signal);
      return true;
    }
};



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all processes 
 */
const char* get_all_processes (XhdlIp* ip, const char* arch_name)
{
  string *return_all_processes = new string ("" );
  if (does_arch_exist(ip, arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlProcess*>::const_iterator iter;
      for (iter=(arch->body->list_process).begin(); iter != (arch->body->list_process).end(); iter++)
	{
	  *return_all_processes += (&(*(*iter)))->label;
          *return_all_processes += " ";
	};
    }
  return return_all_processes->c_str();
}    



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all mapes 
 */
const char* get_all_maps (XhdlIp* ip, const char* arch_name)
{
  string *return_all_maps = new string ("") ;
  if (does_arch_exist(ip, arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlPortMap*>::const_iterator iter;
      for (iter=(arch->body->list_maps).begin(); iter != (arch->body->list_maps).end(); iter++)
	{
	  *return_all_maps += (&(*(*iter)))->label;
	  *return_all_maps += " ";
	};
    }
  return return_all_maps->c_str();
}    



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all mapes 
 */
const char* get_all_local_signals (XhdlIp* ip, const char* arch_name)
{
  string return_all_local_signals = "" ;
  if (does_arch_exist(ip, arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlSignal*>::const_iterator iter;
      for (iter=(arch->list_bus).begin(); iter != (arch->list_bus).end(); iter++)
	{
	  return_all_local_signals += (&(*(*iter)))->name;
	  return_all_local_signals += " ";
	};
    }
  return return_all_local_signals.c_str();
}    



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all labels 
 */
const char* get_all_labels (XhdlIp* ip, const char* arch_name)
{ 
  // all labels : processes, maps, inout, internal signals. 
  std::string *return_all_labels = new std::string () ;
  *return_all_labels = "";
  std::string *all_signals = new std::string();
  *return_all_labels+= string(get_all_signals (ip));
  *return_all_labels += string (get_all_processes (ip, arch_name));
  *return_all_labels += string (get_all_maps ( ip , arch_name )) ;
  *return_all_labels += string (get_all_arch_signals ( ip , arch_name )); 
  /*if (does_arch_exist(ip, arch_name))
    {
    XhdlArch* arch = get_arch (ip,arch_name);
    vector<XhdlProcess*>::const_iterator iter;
    for (iter=(arch->body->list_process).begin(); iter != (arch->body->list_process).end(); iter++)
    {
    return_all_labels += (&(*(*iter)))->label;
    return_all_labels += " ";
    };
    }*/
  return return_all_labels->c_str();
}    



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all processes 
 */
const char* get_process_outputs (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  string return_process_outputs = "" ;
  if (does_arch_exist(ip,arch_name))
    {
      if (does_process_exist (ip, arch_name, process_name))
	{
	  XhdlProcess* tmp_process = get_process (ip, arch_name, process_name);
	  vector<xhdl_instruction*>::const_iterator iter;
	  for (iter=(tmp_process->instructions).begin(); iter != (tmp_process->instructions).end(); iter++)
	    {
	      return_process_outputs += (*iter)->output ;
	      return_process_outputs += " ";
	    }
	  
	  
	}
    }    
  return remove_duplicateds( return_process_outputs.c_str());
}    



/**
 * 
 * @param ip 
 * @param arch_name 
 * @return list of all processes 
 */
const char* get_process_inputs (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  string return_process_inputs = "" ;
  if (does_arch_exist(ip,arch_name))
    {
      if (does_process_exist (ip, arch_name, process_name))
	{
	  XhdlProcess* tmp_process = get_process (ip, arch_name, process_name);
	  vector<xhdl_instruction*>::const_iterator iter;
	  for (iter=(tmp_process->instructions).begin(); iter != (tmp_process->instructions).end(); iter++)
	    {
	      //return_process_inputs += (*iter)->input ;
	      return_process_inputs += get_xhdl_instruction_inputs (*iter);
	    }
	  
	  
	}
    }    
  return remove_duplicateds( return_process_inputs.c_str());
}    


void clean_process_sens_list (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  string return_process_inputs = "" ;
  if (does_arch_exist(ip,arch_name))
    {
      if (does_process_exist (ip, arch_name, process_name))
	{
	  XhdlProcess* tmp_process = get_process (ip, arch_name, process_name);
	  tmp_process->sens_list.clear();
	  Tokenize ( get_process_inputs (ip,arch_name,process_name), tmp_process->sens_list, " ");
	}
    }
  
}

XhdlStatic* get_stat (XhdlIp* ip, const char* arch_name,const char* stat_name)
{
  XhdlArch * arch ;
  if (does_arch_exist (ip,arch_name)) 
    arch = get_arch(ip, arch_name);
  else
    return NULL;
  XhdlStatic* x;
  
  if (does_stat_exist(ip,arch_name,stat_name))
    {
      vector<XhdlStatic*>::const_iterator iter;
      for (iter=(arch->body->list_stat).begin(); iter != (arch->body->list_stat).end(); iter++)
        {
     	  if ((&(*(*iter)))->aff->output == stat_name) 
	    return *iter;
        };
      
    } else 
      {
	return NULL;
      }
  
  
  
  /*
    vector<XhdlArch*>::const_iterator iter;
    for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
    if (((*iter)->name) == arch_name)
    {
    return  *iter;
    } 
    }*/
  return NULL;
}    

const char* get_all_static_inout (XhdlIp* ip, const char* arch_name)
{
  string *return_all_static_inout = new string ("");
  
  if ( !does_arch_exist ( ip , arch_name ) ) 
    return return_all_static_inout->c_str ();
  
  XhdlArch *arch = get_arch ( ip , arch_name ) ;
  int index = 0 ;
  vector <XhdlStatic*>::const_iterator s_it;
  for ( s_it = arch->body->list_stat.begin() ; s_it != arch->body->list_stat.end () ; s_it ++ )
    { 
      *return_all_static_inout += string ( get_static_inputs ( ip , arch_name , index ) ) ;
      *return_all_static_inout += string ( get_static_outputs ( ip , arch_name , index ) );
      index ++ ;    
    }
  
  return return_all_static_inout->c_str ();  
}

const char* get_all_process_inout (XhdlIp* ip, const char* arch_name)
{
  string *return_all_static_inout = new string ("");
  
  if ( !does_arch_exist ( ip , arch_name ) ) 
    return return_all_static_inout->c_str ();
  
  XhdlArch *arch = get_arch ( ip , arch_name ) ;
  vector <XhdlProcess*>::const_iterator p_it;
  for ( p_it = arch->body->list_process.begin() ; p_it != arch->body->list_process.end () ; p_it ++ )
    { 
      *return_all_static_inout += string ( get_process_inputs ( ip , arch_name , (*p_it)->label.c_str() ) ) ;
      *return_all_static_inout += string ( get_process_outputs ( ip , arch_name , (*p_it)->label.c_str() ) );
    }
  
  return return_all_static_inout->c_str ();  
}


bool does_process_exist (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  if (does_arch_exist(ip,arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlProcess*>::const_iterator iter;
      for (iter=(arch->body->list_process).begin(); iter != (arch->body->list_process).end(); iter++)
	{
	  if ((*iter)->label == string (process_name))
            return true;
	};
      return false;
    } else
      {
	return false;
      }
  
  
}



XhdlProcess* get_process (XhdlIp* ip, const char* arch_name, const char* process_name)
{
  if (does_arch_exist(ip,arch_name))
    {
      XhdlArch* arch = get_arch (ip,arch_name);
      vector<XhdlProcess*>::const_iterator iter;
      for (iter=(arch->body->list_process).begin(); iter != (arch->body->list_process).end(); iter++)
	{
	  if ((*iter)->label == string (process_name))
	    return (*iter);
	};
      return NULL;
    } else
      {
	return NULL;
      }
  
  
}



const char* get_xhdl_instruction_inputs  (xhdl_instruction* instruction)
{
  string * return_inputs = new string();
  
  switch (instruction->type) 
    {
    case XHDL_INSTRUCTION_TYPE_SIMPLE : 
      *return_inputs += get_xhdl_simple_instruction_inputs (instruction->simple_instruction);
      break;
      
    case XHDL_INSTRUCTION_TYPE_IF : 
      break;
    }
  
  return return_inputs->c_str();
}




const char* get_xhdl_simple_instruction_inputs  (xhdl_simple_instruction* simple_instruction)
{
  string * return_inputs = new string();
  switch (simple_instruction->type) 
    {
    case XHDL_SIMPLE_INSTRUCTION_COMBINED : 
      *return_inputs += get_xhdl_simple_instruction_inputs ((simple_instruction->combined_instruction)->simple_instruction1);
      *return_inputs += " ";
      *return_inputs += get_xhdl_simple_instruction_inputs ((simple_instruction->combined_instruction)->simple_instruction2);
      *return_inputs += " ";
      //*return_inputs += "combined\n";
      break;
      
    case XHDL_SIMPLE_INSTRUCTION_SIGNAL : 
      *return_inputs += simple_instruction->signal;
      *return_inputs += " ";
      //*return_inputs += "signal\n";
      break;
      
    case XHDL_SIMPLE_INSTRUCTION_NUMBER : 
      //*return_inputs += "number\n";
      break;
      
    case XHDL_SIMPLE_INSTRUCTION_NULL : 
      //*return_inputs += "null\n";
      break;
    }
  return return_inputs->c_str();
}



int get_statics_count (XhdlIp* ip, const char* arch_name)
{
  
  string return_process_outputs = "" ;
  if (does_arch_exist(ip,arch_name))
    {
      return (get_arch (ip,arch_name)->list_bus).size();
    } return -1;
}



XhdlSignal* get_statics (XhdlIp* ip, const char* arch_name, int stat_index)
{
  if (stat_index < get_statics_count (ip, arch_name))
    {
      return (get_arch (ip,arch_name)->list_bus) [stat_index];
    } else
      {
	return NULL;  
      }
}



const char* get_static_outputs ( XhdlIp *ip , const char* arch_name , int index )
{
  if ( index < 0 )
    return "index should be positif " ;
  if ( !does_arch_exist ( ip , arch_name ) )
    return "architecture does not exists";
  XhdlArch *a = get_arch ( ip ,arch_name );  
  if ( index >= a->body->list_stat.size () )
    return "index out of range";
  
  XhdlStatic *st ;
  st = a->body->list_stat[index];     
  if ( st->type == XHDLSTATIC_AFFECT )
    return st->aff->output.c_str();
  
  return ""; 
}



const char* get_static_inputs (XhdlIp *ip , const char* arch_name , int index )
{
  
  
  if ( index < 0 )
    return "index should be positif " ;
  if ( !does_arch_exist ( ip , arch_name ) )
    return "architecture does not exists";
  XhdlArch *a = get_arch ( ip ,arch_name );  
  if ( index >= a->body->list_stat.size () )
    return "index out of range";
  
  XhdlStatic *st ;
  st = a->body->list_stat[index];     
  if ( st->type == XHDLSTATIC_AFFECT )
    return get_affectation_inputs ( st->aff );
  
  
  return "" ;
} 



const char* get_static_inputs (XhdlIp *ip , const char* arch_name , const char* output_name )
{
  
  
  /// BOOKMARK  
  XhdlArch *a = get_arch ( ip ,arch_name );  
  vector<XhdlStatic*>::const_iterator iter;
  for (iter=(a->body->list_stat).begin(); iter != (a->body->list_stat).end(); iter++)
    {
      if (((*iter)->aff->output) == output_name)
	{
	  return get_affectation_inputs ( (*iter)->aff );
	}
    }
  
  return "" ;
} 



const char* get_affectation_inputs ( XhdlAffectation *aff)
{
  string *rslt = new string ("") ;
  *rslt = get_expression_inputs ( aff->default_expr); 
  vector <XhdlAffectation::cond_expr*>::const_iterator iter;
  for ( iter = aff->cond_expressions.begin() ; iter != aff->cond_expressions.end() ; iter ++)
    {
      *rslt = *rslt  + get_expression_inputs ( (*iter)->expr);
      *rslt = *rslt + " " + get_expression_inputs ( (*iter)->condition );     
    }
  
  return  rslt->c_str();
  
}  



const char* get_expression_inputs ( XhdlExpression *expr)
{
  
  string *result = new string( "" );
  switch ( expr->type ) {
  case XHDLEXPRESSION_TYPE_SIG_NAME:  {
    return expr->sig_name.c_str();
  }				 
  case XHDLEXPRESSION_TYPE_OP_EXPR :  {
    *result = *result + get_expression_inputs ( expr->expr1)+ " " ;
    break ;
  }
  case XHDLEXPRESSION_TYPE_EXPR    :  {
    *result = *result + get_expression_inputs ( expr->expr2)+" "  ;
    *result = *result + get_expression_inputs ( expr->expr3) + " ";
    break;
  }
  default : 			    {
    return "";
  }
  }
  //return result.c_str();
  return result->c_str();
  
}



const char* get_component_inputs ( XhdlIp *ip , const char * component_name )
{
  string result ;
  vector <XhdlSignal*>::const_iterator iter ;
  for ( iter = ip->entity->list_bus.begin() ; iter != ip->entity->list_bus.end () ; iter++)
    {
      if ( ((*iter)->direction.find ( "in" , 0 ) != string::npos )|
           ((*iter)->direction.find ( "In" , 0 ) != string::npos )|
	   ((*iter)->direction.find ( "iN" , 0 ) != string::npos )|
	   ((*iter)->direction.find ( "IN" , 0 ) != string::npos ))
	result = result + (*iter)->name + " " ;    
    }
  
  return result.c_str();
  
}






const char* get_component_outputs ( XhdlIp *ip , const char * component_name )
{
  string result ;
  vector <XhdlSignal*>::const_iterator iter ;
  for ( iter = ip->entity->list_bus.begin() ; iter != ip->entity->list_bus.end () ; iter++)
    {
      if ( ((*iter)->direction.find ( "out" , 0 ) != string::npos )|
           ((*iter)->direction.find ( "Out" , 0 ) != string::npos )|
	   ((*iter)->direction.find ( "OUt" , 0 ) != string::npos )|
	   ((*iter)->direction.find ( "OUT" , 0 ) != string::npos )|
	   ((*iter)->direction.find ( "oUT" , 0 ) != string::npos ))
	result = result + (*iter)->name + " " ;    
    }
  
  return result.c_str(); 
}



void ip_clear_params (XhdlIp *ip)
{
  (ip->entity->list_params).clear();
}



bool ip_add_parameter (XhdlIp *ip, const char * param_name)
{
  
  (ip->entity->list_params).push_back (string (param_name));
  return true;
}





bool does_ip_exists ( XhdlIp *ip )
{
  if ( ip != NULL )
    return true;
  return false ;
  
}





const char* get_ip_vhdl (XhdlIp* ip)
{
  string *out_rtl =new string();
  *out_rtl += get_entity_vhdl (ip->entity);
  vector<XhdlArch*>::const_iterator iter;
  for (iter=(ip->list_arch).begin(); iter != (ip->list_arch).end(); iter++)
    {
      *out_rtl += get_arch_vhdl (ip , *iter);
    }
  
  return out_rtl->c_str();
  
}



const char * get_entity_vhdl (XhdlEntity* entity)
{
  bool first_signal = true;
  string* out_rtl = new string();
  *out_rtl += "\n\n";
  *out_rtl += get_libs_vhdl((entity->parent));
  *out_rtl += "\n\n";
  
  *out_rtl += open_folder ("entity");
  *out_rtl += "\n ENTITY " ;
  *out_rtl += entity->name;
  *out_rtl += " IS\n ";
  vector<string>::const_iterator string_iter;
  for (string_iter=(entity->list_params).begin(); string_iter != (entity->list_params).end(); string_iter++)
    {
      if (!first_signal)
	{
	  *out_rtl += "\t;";
	  
	}
      else 
	{
	  *out_rtl += "\nGENERIC (\n"; 
	  *out_rtl += "\t ";
	  first_signal = false;
	}
      *out_rtl += *string_iter;
      *out_rtl += "\t: INTEGER \n";
    }
  
  if (!first_signal) // if there has some generic parameters
    *out_rtl += "\n\t);\n"; 
  
  /// TODO : un comment this condition 
  /// if ((entity->list_bus.begin()) )
  if (1 )
    {
      *out_rtl += "PORT ( \n";
      first_signal = true;
      vector<XhdlSignal*>::const_iterator iter;
      for (iter=(entity->list_bus).begin(); iter != (entity->list_bus).end(); iter++)
	{
	  // generate clocks 
	  // get_clocks (entity->parent) ;
	  // generate resets
	  // generate normal signals 
	  // if ((&(*(*iter)))->name == signal->name)
	  // return true;
	  if (!first_signal)
	    *out_rtl += "\t;";
	  else 
	    *out_rtl += "\t ";
	  *out_rtl += get_entity_signal_vhdl ((&(*(*iter))));
	  *out_rtl += "\n";
	  first_signal = false;
	}
      
      *out_rtl += ");\n";
    }
  *out_rtl += "END ";
  *out_rtl += entity->name;
  *out_rtl += ";\n";
  *out_rtl += close_folder ("entity");
  return out_rtl->c_str();
  
}



/*  const char * get_component_vhdl (XhdlEntity* entity)
    {
    bool first_signal = true;
    string* out_rtl = new string();
    
    *out_rtl += open_folder ("component");
    *out_rtl += "COMPONENT " ;
    
    *out_rtl += entity->name;
    *out_rtl += " IS";
    vector<string>::const_iterator string_iter;
    for (string_iter=(entity->list_params).begin(); string_iter != (entity->list_params).end(); string_iter++)
    {
    if (!first_signal)
    {
    *out_rtl += "\t;";
    
    }
    else 
    {
    *out_rtl += "\nGENERIC (\n"; 
    *out_rtl += "\t ";
    first_signal = false;
    }
    *out_rtl += *string_iter;
    *out_rtl += "\t: INTEGER \n";
    }
    
    if (!first_signal) // if there has some generic parameters
    *out_rtl += "\t);"; 
    
    *out_rtl += "\nPORT ( \n";
    first_signal = true;
    vector<XhdlSignal*>::const_iterator iter;
    for (iter=(entity->list_bus).begin(); iter != (entity->list_bus).end(); iter++)
    {
    // generate clocks 
    // get_clocks (entity->parent) ;
    // generate resets
    // generate normal signals 
    // if ((&(*(*iter)))->name == signal->name)
    // return true;
    if (!first_signal)
    *out_rtl += "\t;";
    else 
    *out_rtl += "\t ";
    *out_rtl += get_entity_signal_vhdl ((&(*(*iter))));
    *out_rtl += "\n";
    first_signal = false;
    }
    
    *out_rtl += "\t);\nEND ";
    *out_rtl += "COMPONENT";
    *out_rtl += ";\n";
    *out_rtl += close_folder ("component");
    return out_rtl->c_str();
    
    }
*/



const char* get_libs_vhdl (XhdlIp* ip)
{
  string* out_rtl = new string();
  *out_rtl += open_folder ("libs");
  *out_rtl += "\nLIBRARY ieee;\n";    
  *out_rtl += "USE ieee.std_logic_1164.ALL;\n";
  *out_rtl += "USE ieee.std_logic_arith.ALL;\n";
  // *out_rtl += ip->entity->name;
  *out_rtl += close_folder("libs");
  return out_rtl->c_str();
}



const char* get_entity_signal_vhdl (XhdlSignal* signal)
{
  string* out_rtl = new string();
  *out_rtl += signal->name; 
  *out_rtl += " : "; 
  *out_rtl += signal->direction; 
  *out_rtl += " "; 
  if (signal->is_bit )
    {
      *out_rtl += "STD_LOGIC  ";
    } else
      {
	*out_rtl += "STD_LOGIC_VECTOR ( ";
	*out_rtl += int_to_char (signal->high_val);
	*out_rtl += " DOWNTO ";
	*out_rtl += int_to_char(signal->low_val);
	*out_rtl += " )";
      }
  return out_rtl->c_str();
}



const char * get_arch_vhdl (XhdlIp *ip , XhdlArch* arch)
{
  string* out_rtl = new string();
  *out_rtl += get_libs_vhdl(arch->parent);
  *out_rtl += "ARCHITECTURE "; 
  *out_rtl += arch->name;
  *out_rtl += " OF ";
  *out_rtl += ((((arch)->parent)->entity)->name);
  *out_rtl += " IS \n\n";
  
  vector<XhdlSignal*>::const_iterator iter;
  
  for (iter=(arch->list_bus).begin(); iter != (arch->list_bus).end(); iter++)
    {
      *out_rtl += get_arch_signal_vhdl ((&(*(*iter))));
      *out_rtl += "\n";
    }
  
  *out_rtl += get_body_vhdl (ip , arch , arch->body);
  *out_rtl += arch->name + ";";
  return out_rtl->c_str();
  
}



const char* get_arch_signal_vhdl (XhdlSignal* signal)
{  // Todo add defined types here !
  if (!signal->is_flipflop)
    {
      string* out_rtl = new string();
      *out_rtl += "SIGNAL "; 
      *out_rtl += signal->name; 
      *out_rtl += ": "; 
      //     if (signal->type == string (""))
      //	  {
      if (signal->is_bit )
	{
          *out_rtl += "STD_LOGIC  ";
	} else
	  {
	    *out_rtl += "STD_LOGIC_VECTOR ( ";
	    *out_rtl += int_to_char (signal->high_val);
	    *out_rtl += " DOWNTO ";
	    *out_rtl += int_to_char(signal->low_val);
	    *out_rtl += " )";
	  }
      /*	  } else
		  {
		  *out_rtl += signal->type;
		  }
      */    *out_rtl += " ; --  ";
      *out_rtl += signal->comment;
      *out_rtl += "";
      return out_rtl->c_str();
    } else 
      {
        string* out_rtl = new string();
	
	XhdlSignal* reg_sig = new XhdlSignal(signal, string("_reg"));
	reg_sig->is_flipflop = false;
	XhdlSignal* next_sig = new XhdlSignal(signal, string( "_next"));
	next_sig->is_flipflop = false;
	
	*out_rtl += string (get_arch_signal_vhdl(next_sig));
	*out_rtl += "\n";
	*out_rtl += string (get_arch_signal_vhdl(reg_sig));
	return out_rtl->c_str();
      }
}



const char * get_body_vhdl (XhdlIp *ip, XhdlArch *arch , XhdlBody* body)
{
  string* out_rtl = new string();
  *out_rtl += "\n\nBEGIN \n";
  //  gen processes 
  //  gen maps XhdlPortMap* 
  
  vector<XhdlPortMap*>::const_iterator iter_maps;
  for (iter_maps=(body->list_maps).begin(); iter_maps != (body->list_maps).end(); iter_maps++)
    {
      *out_rtl += get_portmap_vhdl(*iter_maps);
    };
  
  // gen statics 
  vector<XhdlStatic*>::const_iterator iter_stat;
  for (iter_stat=(body->list_stat).begin(); iter_stat != (body->list_stat).end(); iter_stat++)
    {
      *out_rtl += get_static_assign_vhdl(*iter_stat);
    }
  
  //gen process
  vector<XhdlProcess*>::const_iterator iter_process;
  for ( iter_process = (body->list_process).begin () ; iter_process != (body->list_process).end () ; iter_process ++ )
    {
      *out_rtl += get_process_vhdl ( *iter_process );
    }
  *out_rtl += get_sync_process_vhdl ( ip , arch ) ;
  
  *out_rtl += "\nEND ";
  return out_rtl->c_str();
  
}



const char * get_static_assign_vhdl (XhdlStatic* stat)
{
  string* out_rtl = new string();
  *out_rtl += get_affectation_vhdl (stat->aff);
  return out_rtl->c_str();
  
}


const char * get_affectation_vhdl (XhdlAffectation* aff)
{
  string* out_rtl = new string();
  *out_rtl += "\n--affect\n"    ;
  *out_rtl += aff->output;
  *out_rtl += " <= "    ;
  
  vector<XhdlAffectation::cond_expr*>::const_iterator iter;
  bool is_conditionned;
  is_conditionned = false;
  for (iter=(aff->cond_expressions).begin(); iter != (aff->cond_expressions).end(); iter++)
    {
      is_conditionned = true;
      *out_rtl += get_cond_expression_vhdl (*iter);
      *out_rtl += "\n";
    }
  if (is_conditionned)
    *out_rtl += "ELSE ";
  *out_rtl += get_expression_vhdl (aff->default_expr);
  *out_rtl += " ;\n";
  return out_rtl->c_str();
  
}


const char * get_expression_vhdl (XhdlExpression* expr)
{
  string* out_rtl = new string();
  switch (expr->type) 
    {
    case XHDLEXPRESSION_TYPE_SIG_NAME : 
      *out_rtl += expr->sig_name;
      break;
      
    case XHDLEXPRESSION_TYPE_LITTERAL :
      *out_rtl += expr->litteral;
      break; 
      
    case XHDLEXPRESSION_TYPE_NUMBER :
      *out_rtl += "\'" + expr->number + "\'";
      break;
      
    case XHDLEXPRESSION_TYPE_OP_EXPR :
      *out_rtl += expr->op;
      *out_rtl += get_expression_vhdl(expr->expr1);
      break;
      
    case XHDLEXPRESSION_TYPE_EXPR :
      *out_rtl += "( ";
      *out_rtl += get_expression_vhdl(expr->expr2);
      *out_rtl += " ";
      *out_rtl += expr->op;
      *out_rtl += " ";
      *out_rtl += get_expression_vhdl(expr->expr3);
      *out_rtl += " )";
      break;
      
    };
  return out_rtl->c_str();
} 



const char * get_cond_expression_vhdl (XhdlAffectation::cond_expr* cond_expression)
{
  string* out_rtl = new string();
  *out_rtl += "(";
  *out_rtl+= get_expression_vhdl (cond_expression->expr);
  *out_rtl += ")";
  *out_rtl += " WHEN ";
  *out_rtl += "(";
  *out_rtl+= get_expression_vhdl (cond_expression->condition);
  *out_rtl += ")";
  return out_rtl->c_str();
} 

const char* get_portmap_vhdl (XhdlPortMap*  portmap)
{
  bool first_signal = true;
  string* out_rtl = new string();
  *out_rtl += "\n";
  *out_rtl += portmap->label;
  *out_rtl += " : ";
  *out_rtl += portmap->component_name;
  *out_rtl += "\nPORT MAP(\n ";
  
  vector<XhdlPortMap::connect>::const_iterator iter;
  
  for (iter=(portmap->list_connect).begin(); iter != (portmap->list_connect).end(); iter++)
    {
      if (!first_signal)
        *out_rtl += "," ;
      *out_rtl += (*iter).formal;
      *out_rtl += " => " ;
      *out_rtl += (*iter).actual;
      *out_rtl += "\n" ;
      first_signal = false;
    }
  *out_rtl += ");\n ";
  
  return out_rtl->c_str(); 
}

//const char* get_simple_instruction_vhdl ( xhdl_simple_instruction *inst )


const char * get_simple_instruction_vhdl ( xhdl_simple_instruction *simple_inst )
{
  XhdlArch* arch = simple_inst->get_parent_instruction()->get_parent_process()->get_parent_body()->parent;
  XhdlIp* ip = arch->parent;
  string arch_name = arch->name;
  string *out_inst = new string ();
  switch ( simple_inst->type ) {
    
  case XHDL_SIMPLE_INSTRUCTION_NULL :    {
    break ;
  }
  case XHDL_SIMPLE_INSTRUCTION_NUMBER :  {
    *out_inst = simple_inst->number ;	
    break ;                                       
  }
  case XHDL_SIMPLE_INSTRUCTION_SIGNAL :  {
    *out_inst = get_signal_name (ip, arch_name.c_str(), simple_inst->signal , INPUT) ;
    break ; 
  }	
  case XHDL_SIMPLE_INSTRUCTION_COMBINED :{             
    *out_inst = string (get_simple_instruction_vhdl ( simple_inst->combined_instruction->simple_instruction1 ) );
    
    *out_inst += " " + simple_inst->combined_instruction->op + " ( " ;
    *out_inst += string (get_simple_instruction_vhdl ( simple_inst->combined_instruction->simple_instruction2 ) ) + " ) ";
    break ;
  }				     
    
  }
  
  
  
  return out_inst->c_str () ;
}




const char * get_instruction_vhdl ( xhdl_instruction *inst )
{
  XhdlArch* arch = inst->get_parent_process()->get_parent_body()->parent;
  XhdlIp* ip = arch->parent;
  string arch_name = arch->name;
  string *out_inst = new string ();
  if ( inst->type == XHDL_INSTRUCTION_TYPE_SIMPLE )
    {
      *out_inst = get_signal_name (ip, arch_name.c_str(), inst->output , OUTPUT )  + " <= " ;
      *out_inst += string (get_simple_instruction_vhdl (inst->simple_instruction ) );
    }
  
  return out_inst->c_str ();
  
}

const char * get_process_vhdl ( XhdlProcess *process )
{
  string *out_process = new string () ;
  
  *out_process = process->label + " :  PROCESS ( " ;
  
  vector <string>::const_iterator iter;
  for ( iter = process->sens_list.begin () ; iter != process->sens_list.end () ; iter ++ ) 
    if ( (iter +1 ) != process->sens_list.end () )
      *out_process += (*iter) + " , " ;
    else
      *out_process += (*iter) + " )\n" ;
  
  vector <XhdlSignal*>::const_iterator sig_it ;
  for ( sig_it = process->declarations.begin() ; sig_it != process->declarations.end () ; sig_it ++ )
    *out_process += string ( get_arch_signal_vhdl ( *sig_it ) ) + "\n" ;
  
  *out_process += "BEGIN\n";
  //process->
  
  vector <xhdl_instruction*>::const_iterator inst_it ; 
  for ( inst_it = process->instructions.begin () ; inst_it != process->instructions.end () ; inst_it ++ )
    *out_process += string (get_instruction_vhdl ( *inst_it ) ) + ";\n" ;
  ;
  
  *out_process += "\nEND PROCESS " + process->label + "; \n\n";	
  
  return out_process->c_str ();
}


const char* get_sync_process_vhdl ( XhdlIp *ip , XhdlArch *arch )
{
  string *out_process = new string ();
  *out_process = "Synchronize : PROCESS ( clk , reset ) \n" ;
  *out_process += "BEGIN \n" ;
  *out_process += "IF ( reset == \'0\' ) THEN \n" ;
  
  vector <XhdlSignal*>::const_iterator iter;
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    {
      if ((*iter)->is_flipflop)
	*out_process += simplify_white_spaces ( string ((*iter)->name) ) + "_reg <= " + (*iter)->initial_val + ";\n" ;
    }
  
  *out_process += "ELSIF ( clk \'event AND clk = \'1\' ) THEN \n " ;
  
  for ( iter = arch->list_bus.begin () ; iter != arch->list_bus.end () ; iter ++ )
    {
      if ((*iter)->is_flipflop)
	*out_process += simplify_white_spaces ( string ((*iter)->name) ) + "_reg <= " + simplify_white_spaces ( string ((*iter)->name) ) + "_next ;\n" ;
    }
  
  *out_process += "END IF ; \n" ;
  *out_process += "END PROCESS Synchronize ;\n\n" ;
  
  return out_process->c_str () ;
  
} 



const char* custom_print (const char* x)
{
  return x; 
}



const char* show_args (const char * fmt, ...)
{
  string out_string ="\n";
  
  return out_string.c_str();//y;
}


