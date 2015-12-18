//
// C++ Implementation: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "Xhdl_gen_xml_lib.h"
#include "Xhdl_tcl_interface.h"
#include <fstream>
#include <sstream>
#include "ninja_defines.h"
#include "xhdl_instruction.h"
#include "XhdlEntity.h" 
#include "XhdlAffectation.h"


using namespace std;

XhdlIp *local_ip ;
string itostring (int int_tmp)
{
	//! buffer to convert int 
  char * char_tmp= new char;
  sprintf (char_tmp , "%d",int_tmp );
  return string (char_tmp);
}



string ip_gen_xml (XhdlIp* ip)
{
  local_ip = ip ;
  string out_xml; 
  // out_xml ="<!--This code is generated using ninja application-->\n";
  out_xml +="<!DOCTYPE IP SYSTEM \"dtd.dtd\">\n";
  out_xml += "<IP>\n";
  out_xml += documentation_gen_xml(ip->documentation);
  out_xml += version_gen_xml(ip->version);
  //ip->
  out_xml += entity_gen_xml  (ip->entity);
  out_xml += package_gen_xml (ip->package);
  vector<XhdlArch*>::const_iterator iter;
  out_xml +="<list_arch>\n";
  for (iter=ip->list_arch.begin(); iter != ip->list_arch.end(); iter++)
    {
      out_xml += get_architecture_xml (&(*(*iter)));
    }
  out_xml +="</list_arch>\n";
  out_xml += proj_man_gen_xml(ip->project_man);
  out_xml += "</IP>\n";
  return out_xml;
} 



string entity_gen_xml (XhdlEntity * entity)
{
  string out_xml;
  out_xml += "<entity name=\"";
  out_xml += entity->name;
  out_xml += "\">\n";
  
  out_xml += "<list_params>";
  vector<string>::const_iterator string_iter;
  for (string_iter=(entity->list_params).begin(); string_iter != (entity->list_params).end(); string_iter++)
    {
      out_xml += "<param>";
      out_xml += *string_iter;
      out_xml += "</param>\n";
    }
  out_xml += "</list_params>";
  
  vector<XhdlSignal*>::const_iterator iter;
  /// Iterate through list and output each element.
  out_xml +="<list_bus>";
  for (iter=(entity->list_bus).begin(); iter != (entity->list_bus).end(); iter++)
    {
      out_xml += get_signal_xml (&(*(*iter)));
    }
  out_xml += "</list_bus>\n";
  out_xml += "</entity>\n\n\n";
  return out_xml;
}



string get_architecture_xml (const XhdlArch * architecture)
{
  string out_xml ;
  out_xml += "<arch ";
  
  // name
  out_xml += "name=\"" + architecture->name ;
  out_xml += "\">\n";
  
  // type
  out_xml += "<type>" +architecture->type + "</type>\n";
  
  //list_enum list_enumtype
  out_xml += "<list_enumtype>";
  vector<XhdlEnumType*>::const_iterator enum_iter;
  /// Iterate through list and output each element.
  for (enum_iter=(architecture->list_enumtype).begin(); enum_iter != (architecture->list_enumtype).end(); enum_iter++)
    {
      out_xml += enum_type_gen_xml( (&(*(*enum_iter))));
    }       
  out_xml += "</list_enumtype>\n";
  
  // list_bus
  out_xml += "<list_bus>";      
  vector<XhdlSignal*>::const_iterator iter;
  /// Iterate through list and output each element.
  for (iter=(architecture->xml_signals).begin(); iter != (architecture->xml_signals).end(); iter++)
    {
      out_xml += get_signal_xml (&(*(*iter)));
    }
  out_xml += "</list_bus>\n";     
  
  //body
  out_xml += body_get_xml (architecture->body);
  
  out_xml += "</arch>\n";
  //out_xml +="<!-- Architecture ended-->\n";
  return out_xml;
}



string body_get_xml (const XhdlBody* body )
{
  string out_xml= "<body>\n\n\n";
  
  /// MAPS
  out_xml+="<list_maps>";
  vector<XhdlPortMap*>::const_iterator map_iter;
  /// Iterate through list and output each element.
  for (map_iter=(body->list_maps).begin(); map_iter != (body->list_maps).end(); map_iter++)
    {
      out_xml += map_get_xml (&(*(*map_iter)));
    }
  out_xml+="</list_maps>\n\n";
  
  /// stat
  out_xml+="<list_stat>";
  vector<XhdlStatic*>::const_iterator stat_iter;
  /// Iterate through list and output each element.
  for (stat_iter=(body->list_stat).begin(); stat_iter != (body->list_stat).end(); stat_iter++)
    {
      out_xml += stat_get_xml (&(*(*stat_iter)));
    }
  out_xml+="</list_stat>\n\n";
  
  /// process
  out_xml+="<list_process>";
  vector<XhdlProcess*>::const_iterator process_iter;
  /// Iterate through list and output each element.
  for (process_iter=(body->list_process).begin(); process_iter != (body->list_process).end(); process_iter++)
    {
      out_xml += process_get_xml (&(*(*process_iter)));
    }
  out_xml+="</list_process>\n\n";
  
  /// plain 
  out_xml+="<list_plain>";
  vector<XhdlPlain*>::const_iterator plain_iter;
  /// Iterate through list and output each element.
  for (plain_iter=(body->list_plain).begin(); plain_iter != (body->list_plain).end(); plain_iter++)
    {
      out_xml += plain_get_xml (&(*(*plain_iter)));
    }
  out_xml+="</list_plain>\n\n";
  
  
  
  out_xml+="\n</body>\n";
  return out_xml;
}



string map_get_xml (XhdlPortMap *port_map)
{
  string out_xml= "<port_map>\n";
  out_xml += string("<label>") + port_map->label + string ("</label>\n");
  out_xml += string("<component_name>") + port_map->component_name + string ("</component_name>\n");      
  out_xml += "<list_connect>\n";
  
  XhdlPortMap::connect x;
  vector<XhdlPortMap::connect>::const_iterator connect_iter;
  /// Iterate through list and output each element.
  for (connect_iter=(port_map->list_connect).begin(); connect_iter != (port_map->list_connect).end(); connect_iter++)
    {
      //out_xml += map_get_xml (&(*(*map_iter)));
      out_xml += string ("<connect> \n <formal>") ;
      out_xml += (&(*connect_iter))->formal;
      out_xml += string ("</formal> \n <actual>") ;
      out_xml += (&(*connect_iter))->actual;
      out_xml += string ("</actual> \n </connect>\n") ;
    }
  
  out_xml += "</list_connect>\n";
  out_xml+="</port_map>\n"; 
  return out_xml;
}



string stat_get_xml (XhdlStatic *stat_assgn)
{//TODO
  string out_xml= "<static>\n";
  //stat_assgn
  if (stat_assgn->type == XHDLSTATIC_AFFECT)
    out_xml += affect_get_xml(stat_assgn->aff);
  out_xml+="</static>\n";
  return out_xml;
}




string affect_get_xml (XhdlAffectation *affect)
{//TODO 
  //
  string out_xml= "<affect>\n";
  out_xml += string ("<output>") + affect->output +string ("</output>\n");
  out_xml += default_expression_get_xml (affect->default_expr) ; 
  
  vector<XhdlAffectation::cond_expr*>::const_iterator iter;
  /// Iterate through list and output each element.
  for (iter=(affect->cond_expressions).begin(); iter != (affect->cond_expressions).end(); iter++)
    {
      out_xml += "<cond_expr> ";
      out_xml += expression_get_xml ((*iter)->expr) ; 
      out_xml += expression_get_xml ((*iter)->condition,"cond") ; 
      out_xml += "</cond_expr> \n";
    }
  
  out_xml += "</affect>\n";
  return out_xml;
}



string default_expression_get_xml (const XhdlExpression* expression)
{
  string rout_xml = "<default_expr>\n";
  rout_xml += expression_get_xml (expression);
  rout_xml += "</default_expr>\n";
  return rout_xml;
  
}


string op_gen_xml(string op)
{
  string op_xml;
  if ( op == "&")
    {
      op_xml="&#38;"; 
    }
  else if ( op == "<")
    {
      op_xml="&#60;"; 
    }
  else if ( op == ">")
    {
      op_xml="&#62;"; 
    }
  else if ( op == "<=")
    {
      op_xml="&#60;="; 
    }
  else if ( op ==">=")
    {
      op_xml="&#62;="; 
    }
  else
    {
      op_xml=op; 
    }
  
  return op_xml;
}




string expression_get_xml (const XhdlExpression* expression, const char* tag )
{
  string rout_xml = " <";
  rout_xml += tag;
  rout_xml += ">\n";
  switch (expression->type)
    {
    case XHDLEXPRESSION_TYPE_SIG_NAME :
      rout_xml += string ("<sig_name>") + expression->sig_name +string ("</sig_name>\n")        ;break;
      
    case XHDLEXPRESSION_TYPE_LITTERAL :
      rout_xml += string ("<litteral>") + expression->litteral +string ("</litteral>\n")        ;break;
      
    case XHDLEXPRESSION_TYPE_NUMBER :
      rout_xml += string ("<number>") + expression->number +string ("</number>\n")      ;break;
      
    case XHDLEXPRESSION_TYPE_OP_EXPR :
      rout_xml += string ("<op>") + op_gen_xml(expression->op) +string ("</op>\n")  ;
      rout_xml += expression_get_xml(expression->expr1);break;
      
    case XHDLEXPRESSION_TYPE_EXPR :
      //rout_xml += "<expr>";
      rout_xml += expression_get_xml (expression->expr2);
      rout_xml += string ("<op>") + op_gen_xml(expression->op) +string ("</op>\n")  ;
      rout_xml += expression_get_xml (expression->expr3);
      //rout_xml += "</expr>";
      ;break;
      
    }
  rout_xml += "</";
  rout_xml += tag;
  rout_xml += ">\n";
  
  return rout_xml;
}



string describe_expression (const XhdlExpression *expression_tmp)
{
  string return_log;
  return_log += string ("TYPE :") + itostring(expression_tmp->type) + string ("\n");
  return_log += string ("OP :") + expression_tmp->op + string ("\n");
  return_log += string ("SIG_NAME :") + expression_tmp->sig_name + string ("\n");
  return_log += string ("LITTERAL :") + expression_tmp->litteral + string ("\n");
  return_log += string ("Number :") + expression_tmp->number + string ("\n");
  
  if (expression_tmp->type == XHDLEXPRESSION_TYPE_OP_EXPR)
    return_log += string ("expr1 :") + describe_expression(expression_tmp->expr1) + string ("\n");
  if (expression_tmp->type == XHDLEXPRESSION_TYPE_EXPR)
    {
      return_log += string ("expr2 :") + describe_expression(expression_tmp->expr2) + string ("\n");
      return_log += string ("expr3 :") + describe_expression(expression_tmp->expr3) + string ("\n");
    }
  
  
  return return_log;
  
}



string process_get_xml (XhdlProcess* process)
{//TODO
  
  
  
  string  out_xml= "<process>\n";
  
  out_xml += string ("<comment>") + process->comment + string (" </comment>\n")  ;
  out_xml += string ("<label>")   + process->label   + string ("</label>\n")  ;
  out_xml += string("<sens_list>");
  vector<string>::const_iterator sens_iter;
  /// Iterate through list and output each element.
  for (sens_iter=(process->sens_list).begin(); sens_iter != (process->sens_list).end(); sens_iter++)
    {
      out_xml +=  string ("<sig_name>") + *sens_iter + string ("</sig_name>\n")  ;
    }
  out_xml += string("</sens_list>\n");
  
  out_xml += string("<list_intsructions>");
  vector<xhdl_instruction *>::const_iterator seq_iter;
  /// Iterate through list and output each element.
  for (seq_iter=(process->instructions).begin(); seq_iter != (process->instructions).end(); seq_iter++)
    {
      
      out_xml += instruction_get_xml (&(*(*seq_iter)));
    }
  out_xml += string("</list_intsructions>\n");
  
  out_xml +="</process>\n";
  return  out_xml;
}



string instruction_get_xml (const xhdl_instruction *instruction)
{
  string out_xml;
  out_xml += string ("<instruction>\n");
  //if (instruction->type == XHDL_INSTRUCTION_TYPE_SIMPLE )
  {
    out_xml += string ("<sig_name>")+ instruction->output +string ("</sig_name>\n");
    out_xml += simple_instruction_get_xml (instruction->simple_instruction);
  }
  out_xml += string ("</instruction>\n");
  return out_xml;
}



string simple_instruction_get_xml (const xhdl_simple_instruction *simple_instruction)
{
  string out_xml;
  out_xml += string ("<simple_instruction>\n");
  //out_xml += simple_instruction->signal;
  if (simple_instruction->type == XHDL_SIMPLE_INSTRUCTION_COMBINED )
    {
      out_xml += simple_instruction_get_xml(simple_instruction->combined_instruction->simple_instruction1);
      out_xml += string("<op>") + op_gen_xml(simple_instruction->combined_instruction->op) + string("</op>\n");
      out_xml += simple_instruction_get_xml(simple_instruction->combined_instruction->simple_instruction2);
    }else if (simple_instruction->type == XHDL_SIMPLE_INSTRUCTION_NULL )
      {
	out_xml += string("<null>") + simple_instruction->null + string("</null>\n");
      }else if (simple_instruction->type == XHDL_SIMPLE_INSTRUCTION_NUMBER )
	{
	  out_xml += string("<number>") + simple_instruction->number + string("</number>\n");
	}else if (simple_instruction->type == XHDL_SIMPLE_INSTRUCTION_SIGNAL )
	  {
	    out_xml += string("<sig_name>") + simple_instruction->signal + string("</sig_name>\n");
	  }
  
  out_xml += string ("</simple_instruction>\n");
  return out_xml;
}



string sequential_get_xml (XhdlSequential *sequence_item)
{
  string out_xml;
  out_xml += string ("<sequential>\n");
  // if sequence_item->type == 
  if (sequence_item->type == XHDLSEQUENCE_TYPE_AFFECT )
    {
      out_xml += affect_get_xml(sequence_item->aff);	
    }
  
  if (sequence_item->type == XHDLSEQUENCE_TYPE_IF )
    {
      //out_xml += affect_get_xml(sequence_item->aff);	
    }
  
  if (sequence_item->type == XHDLSEQUENCE_TYPE_AFFECT )
    {
      //out_xml += affect_get_xml(sequence_item->aff);	
    }
  
  out_xml += string ("</sequential>\n");
  return out_xml;
}



string plain_get_xml (XhdlPlain* plain)
{//TODO
  string  out_xml= "<body>\n";
  out_xml +="</body>\n";
  return  out_xml;
}



string enum_type_gen_xml (XhdlEnumType * enum_type)
{
  string out_xml= "<enumtype name=\"";
  out_xml+=  enum_type->name;
  out_xml += "\">\n";
  out_xml += "<enumlist>\n";
  //enum_type->enumlist
  vector<string>::const_iterator iter;
  /// Iterate through list and output each element.
  for (iter=(enum_type->enumlist).begin(); iter != (enum_type->enumlist).end(); iter++)
    {
      out_xml += string("<id>") + *iter  + string("</id>\n");
    }
  out_xml += "</enumlist>\n";
  
  out_xml+="</enumtype>\n";
  return out_xml; //TODO
}



string documentation_gen_xml (string document)
{
  string out_xml= "<documentation>";
  out_xml += document;
  out_xml += "</documentation>\n\n";
  return out_xml;
}



string version_gen_xml (string version)
{
  string out_xml= "<version>";
  out_xml += version;
  out_xml += "</version>\n\n";
  return out_xml;
}



string package_gen_xml (XhdlPackage *package)
{
  string out_xml;
  out_xml += "<package name=\"";
  out_xml += package->name;
  out_xml += "\">\n";
  vector<XhdlSignal*>::const_iterator iter;
  /// Iterate through list and output each element.
  out_xml +="<list_bus>";
  for (iter=(package->list_bus).begin(); iter != (package->list_bus).end(); iter++)
    {
      out_xml += get_signal_xml (&(*(*iter)));
    }
  out_xml += "</list_bus>\n";
  out_xml += "</package>\n\n";
  return out_xml;
}



string get_signal_xml       (const XhdlSignal * signal        )
{
  string out_xml ="";
  out_xml += "<signal ";
  out_xml += "name=\"" + signal->name ;
  out_xml += "\">\n";
  
  if (signal->type != string(""))
    {
      out_xml += string ("<stype>") ;
      out_xml += signal->type;
      out_xml += string ("</stype>\n") ;
    } 
  
  out_xml += string ("<direction>") ;
  out_xml += signal->direction;
  out_xml += string ("</direction>\n") ;
  
  out_xml += string     ("<high_val>") ;
  out_xml += itostring  (signal->high_val ) ;
  out_xml += string ("</high_val>\n") ;
  
  out_xml += string ("<low_val>") ;
  out_xml += itostring  (signal->low_val) ;
  out_xml += string ("</low_val>\n") ;
  
  out_xml += string ("<is_bit>") ;
  out_xml += (signal->is_bit)? "TRUE":"FALSE";
  out_xml += string ("</is_bit>\n") ;
  
  out_xml += string ("<is_reset>") ;
  out_xml += (signal->is_reset)? "TRUE":"FALSE";
  out_xml += string ("</is_reset>\n") ;
  
  out_xml += string ("<is_clock>") ;
  out_xml += (signal->is_clock)? "TRUE":"FALSE";
  out_xml += string ("</is_clock>\n") ;
  
  out_xml += string ("<initial_val>") ;
  out_xml += signal->initial_val;
  out_xml += string ("</initial_val>\n") ;
  
  out_xml += string ("<is_flipflop>") ;
  out_xml += (signal->is_flipflop)? "TRUE":"FALSE";
  out_xml += string ("</is_flipflop>\n") ;
  
  out_xml += string ("<reference>") ;
  out_xml += signal->reference;
  out_xml += string ("</reference>\n") ;
  
  out_xml += string ("<comment>") ;
  out_xml += signal->comment;
  out_xml += string ("</comment>\n") ;
  
  out_xml += "</signal>\n";
  return out_xml;
  
}


string get_signal_name (XhdlIp* ip,  const char* arch_name, string sig_name , int use)
{
  XhdlSignal* tmp_signal= get_signal(ip,arch_name, sig_name.c_str());
  if (tmp_signal != NULL)
    {
      if (!tmp_signal->is_flipflop)
	{
	  return sig_name;
	} else 
	  
	  {
	    if ( use == INPUT )
	      return string ( simplify_white_spaces ( sig_name ) + "_reg" ) ;
	    
	    if ( use == OUTPUT )
	      return string ( simplify_white_spaces ( sig_name ) + "_next" ) ;
	  }
    }
  return sig_name;
  /* vector <XhdlArch*>::const_iterator arch_it ;
     vector <XhdlSignal*>::const_iterator sig_it ;
     bool flipflop_found = false ;
     
     for ( arch_it = local_ip->list_arch.begin() ; arch_it != local_ip->list_arch.end () && !flipflop_found ; arch_it ++ )
     for ( sig_it = (*arch_it)->ff_list.begin () ; sig_it != (*arch_it)->ff_list.end () && !flipflop_found ; sig_it ++ )
     if ( (*sig_it)->name == sig_name ) 
     flipflop_found = true ;
     
     if ( !flipflop_found )
     return sig_name ;
     
     
     if ( use == INPUT )
     return string ( simplify_white_spaces ( sig_name ) + "_reg" ) ;
     
     if ( use == OUTPUT )
     return string ( simplify_white_spaces ( sig_name ) + "_next" ) ;
  */
}


string proj_man_gen_xml ( string project_man)
{
  string out_xml= "<project_man>";
  out_xml += project_man;
  out_xml += "</project_man>\n";
  return out_xml;
}



const char * get_string (string string_tmp)
{
  return string_tmp.c_str();
} 



string new_string (const char * char_tmp)
{
  return string(char_tmp);
} 




/*!
  This functions stores a string variable into a file 
  \param string_tmp :  string to store
  \param file_name :  file where to store string_tmp
  \return True if is success, false if failed (not implemented yet)!
*/

bool save_string_to_file (string string_tmp, const char * file_name )
{
  ofstream out_file (file_name);
  out_file << string_tmp.c_str()<< endl;
  out_file.close();
  return true;
}



/*!
  This functions stores a const char* variable into a file 
  \param string_tmp :  string to store
  \param file_name :  file where to store string_tmp
  \return True if is success, false if failed (not implemented yet)!
*/

bool save_chars_to_file (const char*  chars_tmp, const char * file_name )
{
  ofstream out_file (file_name);
  out_file << chars_tmp<< endl;
  out_file.close();
  return true;
}


