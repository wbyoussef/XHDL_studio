//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef XHDL_GEN_XML_LIB_H
#define XHDL_GEN_XML_LIB_H
#include <string>
//using namespace std;
#include "XhdlIp.h"
#include "XhdlBody.h"
#include "XhdlClasses.h"

class XhdlEnumType; 


#define INPUT 0
#define OUTPUT 1
string itostring (int int_tmp);


string ip_gen_xml (XhdlIp* ip);
string entity_gen_xml (XhdlEntity * entity);
string get_architecture_xml (const XhdlArch * architecture);
string package_gen_xml (XhdlPackage *package);
string body_get_xml (const XhdlBody* body );
string map_get_xml (XhdlPortMap *port_map);
string stat_get_xml (XhdlStatic *stat_assgn);
string affect_get_xml (XhdlAffectation *affect);
string default_expression_get_xml (const XhdlExpression* expression);
string expression_get_xml (const XhdlExpression* expression, const char* tag = "expr");
string op_gen_xml(string op);
string process_get_xml (XhdlProcess* process);
string simple_instruction_get_xml (const xhdl_simple_instruction *simple_instruction);
string instruction_get_xml (const xhdl_instruction *instruction);
string sequential_get_xml (XhdlSequential *sequence_item);

string plain_get_xml (XhdlPlain* plain);
string enum_type_gen_xml (XhdlEnumType * enum_type);

string documentation_gen_xml (string document);
string version_gen_xml (string version);
string proj_man_gen_xml ( string proj_man);


string describe_expression (const XhdlExpression * expression);

string new_string (const char * char_tmp);
string get_signal_xml       (const XhdlSignal * signal );
string get_signal_name (XhdlIp* ip, const char* arch_name, string sig_name , int use); // use == input or output
const char * get_string (string string_tmp);
bool save_string_to_file (string string_tmp, const char * file_name );
bool save_chars_to_file  (const char*  chars_tmp, const char * file_name );



#endif // XHDL_GEN_XML_LIB_H
