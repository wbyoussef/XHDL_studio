//{{ <Replaced missing fold top mark>

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
#ifndef XHDL_TCL_INTERFACE_H 
#define XHDL_TCL_INTERFACE_H 

#include <string>
#include "XhdlClasses.h" 
#include "XhdlIp.h" 

class XhdlProcess;
class xhdl_instruction;
class xhdl_simple_instruction;
struct check_result_t; 
class XhdlSignal; 
class XhdlEnumType;
class XhdlPortMap; 
class XhdlStatic;
class XhdlExpression; 
class XhdlAffectation;
class XhdlBody;

#include <sstream>  // Required for stringstreams
#include "XhdlAffectation.h"

extern bool use_ieee_libs; 
extern bool use_folders; 

extern XhdlIp* main_ip;


/*! \fn void do_use_ieee_libs ();
    \brief This function sets including ieee libs in VHDL
           generation mode.
    \param 
    \return void
*/
void do_use_ieee_libs ();



/*! \fn void do_not_use_ieee_libs ();
    \brief This function un-sets including ieee libs in VHDL
           generation mode.
    \param 
    \return void
*/
void do_not_use_ieee_libs ();



void Tokenize(const string& str, vector<string>& tokens,const string& delimiters = " ");


const char* remove_duplicateds (const char* data) ;


/*! \fn string simplify_white_spaces ( string str);
    \brief elliminate white spaces from string str
    \param str : string
    \return string
*/
string simplify_white_spaces ( string str ) ;

/*! \fn bool are_ieee_libs_used () ;
    \brief This function returns wether ieee libs will be included 
    in VHDL generation mode.
    \param 
    \return true if ieee are included, false if otherwise.
*/
bool are_ieee_libs_used () ;



/*! \fn void do_use_folders ();
    \brief this functions enables using folders in VHDL generated
           code 
    \param 
    \return 
*/
void do_use_folders ();



/*! \fn void do_not_use_folders ();
    \brief 
    \brief this functions disables using folders in VHDL generated
           code 
    \param 
    \return 
*/
void do_not_use_folders ();



/*! \fn bool are_folders_used () ;
    \brief this function return a boolean value indicating wether
           generated VHDL code is generated with folders 
    \param 
    \return true if folders are used, false otherwise
*/
bool are_folders_used () ;




/*! \fn XhdlIp* create_ip (char* name);
    \brief this function creates an empty IP.
    \param name IP's name 
    \return a pointer the created IP
*/
XhdlIp* create_ip (char* name);



/*! \fn XhdlEntity* ip_get_entity (XhdlIp* ip);
    \brief returns a pointer to the IP's entity description
    \param ip : is a pointer to the IP's description
    \return a pointer to the entity
*/
XhdlEntity* ip_get_entity (XhdlIp* ip = main_ip);



/*! \fn XhdlEntity* ip_set_entity (XhdlIp* ip, XhdlEntity* entity);
    \brief 
    \param 
    \return 
*/
// XhdlEntity* ip_set_entity (XhdlIp* ip = main_ip, XhdlEntity* entity);



/*! \fn void ip_set_name (XhdlIp* ip, char* name );
    \brief 
    \param 
    \return 
*/
void ip_set_name (XhdlIp* ip = main_ip, char* name ="" );



/*! \fn check_result_t * validate_xml_vs_dtd (const char* xml_name, const char* dtd_name);
    \brief 
    \param 
    \return 
*/

check_result_t * validate_xml_vs_dtd (const char* xml_name, const char* dtd_name);



/*! \fn const char* ip_get_name (const XhdlIp* ip );
    \brief 
    \param 
    \return 
*/
const char* ip_get_name (const XhdlIp* ip= main_ip );



/*! \fn XhdlEntity* create_entity (char* name);
    \brief 
    \param 
    \return 
*/
XhdlEntity* create_entity (char* name);



/*! \fn const char * ip_get_documentation (const XhdlIp* ip );
    \brief 
    \param 
    \return 
*/
const char * ip_get_documentation (const XhdlIp* ip );



/*! \fn void ip_set_documentation (XhdlIp* ip, const char * doc );
    \brief 
    \param 
    \return 
*/
void ip_set_documentation (XhdlIp* ip, const char * doc );



/*! \fn bool ip_open_valid_xml_file (XhdlIp* ip, const char *  filename,  const char *  dtd_file);
    \brief 
    \param 
    \return 
*/
bool ip_open_valid_xml_file (XhdlIp* ip, const char *  filename,  const char *  dtd_file);



/*! \fn bool ip_open_xml_file (XhdlIp* ip, char *  filename);
    \brief 
    \param 
    \return 
*/
bool ip_open_xml_file (XhdlIp* ip, char *  filename);



/*! \fn void ip_open_stream (XhdlIp* ip, const char * stream);
    \brief 
    \param 
    \return 
*/
void ip_open_stream (XhdlIp* ip, const char * stream);




/*! \fn const char* ip_describe_entity (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* ip_describe_entity (XhdlIp* ip);



/*! \fn const char* entity_describe (const XhdlEntity* entity);
    \brief 
    \param 
    \return 
*/
const char* entity_describe (const XhdlEntity* entity);



/*! \fn bool entity_find_signal(XhdlEntity* entity, XhdlSignal* signal);
    \brief 
    \param 
    \return 
*/
bool entity_find_signal(XhdlEntity* entity, XhdlSignal* signal);



/*! \fn bool entity_add_signal(XhdlEntity* entity, XhdlSignal* signal);
    \brief 
    \param 
    \return 
*/
bool entity_add_signal(XhdlEntity* entity, XhdlSignal* signal);



/*! \fn const char* get_clocks (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_clocks (XhdlIp* ip);



/*! \fn const char* get_resets (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_resets (XhdlIp* ip);



/*! \fn const char* get_normal_signals (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_normal_signals (XhdlIp* ip);



/*! \fn const char* get_all_signals (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_all_signals (XhdlIp* ip);



/*! \fn const char* get_all_params (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_all_params (XhdlIp* ip);



/*! \fn const char* get_all_arch_signals (XhdlIp* ip , const char *arch_name);
    \brief  
    \param 
    \return 
*/
const char* get_all_arch_signals (XhdlIp* ip , const char* arch_name);



/*! \fn XhdlSignal* get_signal (XhdlIp* ip, const char* signal_name);
    \brief 
    \param 
    \return 
*/
XhdlSignal* get_signal (XhdlIp* ip, const char* signal_name);



/*! \fn vector<XhdlSignal*> get_signals (XhdlIp* ip, const char* arch_name);
    \brief 
    \param 
    \return 
*/
vector<XhdlSignal*> get_signals (XhdlIp* ip, const char* arch_name);



/*! \fn vector<XhdlEnumType*> get_enum_types (XhdlIp* ip, const char* arch_name);
    \brief return all enum types defined by user
    \param 
    \return 
*/
vector<XhdlEnumType*> get_enum_types (XhdlIp* ip, const char* arch_name);



/*! \fn bool does_inout_exist (XhdlIp* ip, const char* signal_name);
    \brief 
    \param 
    \return 
*/
bool does_inout_exist (XhdlIp* ip, const char* signal_name);



/*! \fn bool does_param_exist (XhdlIp* ip, const char* signal_name);
    \brief 
    \param 
    \return 
*/
bool does_param_exist (XhdlIp* ip, const char* signal_name);


/*! \fn bool does_signal_exist (XhdlIp* ip, const char* signal_name);
    \brief look for  sig_name in architecture
    \param 
    \return 
*/
bool does_signal_exist (XhdlIp* ip, const char * arch_name ,const char* signal_name);




/*! \fn XhdlSignal* get_signal (XhdlIp* ip, const char * arch_name ,const char* signal_name) ;
    \brief look for  sig_name in architecture
    \param 
    \return 
*/
  XhdlSignal* get_signal (XhdlIp* ip, const char * arch_name ,const char* signal_name) ;





/*! \fn XhdlPortMap* get_map (XhdlIp* ip, const char* arch_name,const char* map_name)
    \brief 
    \param 
    \return 
*/
XhdlPortMap* get_map (XhdlIp* ip, const char* arch_name,const char* map_name);



/*! \fn XhdlIp* include_map (XhdlIp* ip, const char* arch_name,const char* map_name)
    \brief 
    \param 
    \return 
*/
XhdlIp* include_map (XhdlIp* ip, const char* arch_name,const char* map_name);



/*! \fn XhdlArch* get_arch (XhdlIp* ip, const char* arch_name);
    \brief 
    \param 
    \return 
*/
XhdlArch* get_arch (XhdlIp* ip, const char* arch_name);



/*! \fn bool does_arch_exist (XhdlIp* ip, const char* arch_name);
    \brief 
    \param 
    \return 
*/
bool does_arch_exist (XhdlIp* ip, const char* arch_name);



/*! \fn does_map_exist (XhdlIp* ip, const char * arch_name, const char* map_name);
    \brief 
    \param 
    \return 
*/
bool does_map_exist (XhdlIp* ip, const char * arch_name, const char* map_name);



/*! \fn does_stat_exist (XhdlIp* ip, const char * arch_name, const char* stat_name);
    \brief 
    \param 
    \return 
*/
bool does_stat_exist (XhdlIp* ip, const char* arch_name, const char* stat_name);


/*! \fn const char* get_archs (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_archs (XhdlIp* ip);




/*! \fn const char* get_sub_blocks (XhdlIp* ip, const char* arch_name);
    \brief 
    \param 
    \return 
*/
const char* get_sub_blocks (XhdlIp* ip, const char* arch_name);



/*! \fn bool rename_inout (XhdlIp* ip, const char* old_name, const char* new_name)
    \brief 
    \param 
    \return 
*/
bool rename_inout (XhdlIp* ip, const char* old_name, const char* new_name);


 
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
                       );



const char* get_inout_comment (XhdlIp* ip, const char* signal_name);



bool set_inout_comment (XhdlIp* ip, const char* signal_name, const char* new_comment);



bool remove_inout (XhdlIp* ip, const char* signal_name);


 
bool add_inout (           XhdlIp* ip
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
                       );



/*! \fn const char* get_all_processes (XhdlIp* ip, const char* arch_name);
    \brief this function lists all processes that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
const char* get_all_processes (XhdlIp* ip, const char* arch_name);



/*! \fn const char* get_all_maps (XhdlIp* ip, const char* arch_name);
    \brief this function lists all maps that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of maps
*/
const char* get_all_maps (XhdlIp* ip, const char* arch_name);



/*! \fn const char* get_all_labels (XhdlIp* ip, const char* arch_name);
    \brief this function lists all labels that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
const char* get_all_labels (XhdlIp* ip, const char* arch_name);


/*! \fn const char* get_process_outputs (XhdlIp* ip, const char* arch_name, const char* process_name)
    \brief this function lists all processes that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
const char* get_process_outputs (XhdlIp* ip, const char* arch_name, const char* process_name);

/*! \fn const char* get_process_inputs (XhdlIp* ip, const char* arch_name, const char* process_name)
    \brief this function lists all processes that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
const char* get_process_inputs (XhdlIp* ip, const char* arch_name, const char* process_name);


/*! \fn 
    \brief 
    \param
    \param 
    \return 
*/
void clean_process_sens_list (XhdlIp* ip, const char* arch_name, const char* process_name);


  XhdlStatic* get_stat (XhdlIp* ip, const char* arch_name,const char* stat_name);


/*! \fn const char* get_all_static_inout (XhdlIp* ip, const char* arch_name)
    \brief this function lists all processes that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's static inout
*/
const char* get_all_static_inout (XhdlIp* ip, const char* arch_name);



/*! \fn const char* get_all_process_inout (XhdlIp* ip, const char* arch_name)
    \brief this function lists all processes that are implemented in <i>arch_name</i>
    of the <i>ip</i>
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's process inout
*/
const char* get_all_process_inout (XhdlIp* ip, const char* arch_name);


//added by in 7 777777777777777777777777777777777777777777777777777777777777777777777777777777
bool does_ip_exists ( XhdlIp *ip );
const char* get_expression_inputs ( XhdlExpression *expr);
const char* get_affectation_inputs ( XhdlAffectation *affect);
const char* get_static_inputs (XhdlIp *ip , const char* arch_name , int index );
const char* get_static_inputs (XhdlIp *ip , const char* arch_name , const char* output_name );
const char* get_static_outputs (XhdlIp *ip , const char* arch_name , int index );
const char* get_component_inputs ( XhdlIp *ip  , const char* component_name );
const char* get_component_outputs ( XhdlIp *ip , const char* component_name );
void ip_clear_params (XhdlIp *ip);
bool ip_add_parameter (XhdlIp *ip, const char * param_name);
//777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777



/*! \fn bool does_process_exist (XhdlIp* ip, const char* arch_name, const char* process_name)
    \brief 
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
bool does_process_exist (XhdlIp* ip, const char* arch_name, const char* process_name);



/*! \fn XhdlProcess* get_process (XhdlIp* ip, const char* arch_name, const char* process_name)
    \brief 
    \param ip : IP's name
    \param arch_name : architecture's name
    \return selected architecture's list of processes
*/
XhdlProcess* get_process (XhdlIp* ip, const char* arch_name, const char* process_name);




const char* get_xhdl_instruction_inputs  (xhdl_instruction* instruction);



const char* get_xhdl_simple_instruction_inputs  (xhdl_simple_instruction* simple_instruction);



int get_statics_count (XhdlIp* ip, const char* arch_name);


XhdlSignal* get_statics (XhdlIp* ip, const char* arch_name, int stat_index);


// VHDL generating functions 


/*! \fn const char* get_ip_vhdl (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/
const char* get_ip_vhdl (XhdlIp* ip);



/*! \fn const char* get_entity_vhdl (XhdlEntity* entity);
    \brief 
    \param 
    \return 
*/
const char* get_entity_vhdl (XhdlEntity* entity);



//const char * get_component_vhdl (XhdlEntity* entity);



/*! \fn const char* get_libs_vhdl (XhdlIp* ip);
    \brief 
    \param 
    \return 
*/

const char* get_libs_vhdl (XhdlIp* ip);



/*! \fn const char* get_entity_signal_vhdl (XhdlSignal* signal);
    \brief 
    \param 
    \return 
*/
const char* get_entity_signal_vhdl (XhdlSignal* signal);



/*! \fn const char* get_arch_vhdl (XhdlIp *ip , XhdlArch* arch);
    \brief 
    \param 
    \return 
*/
const char* get_arch_vhdl (XhdlIp *ip , XhdlArch* arch);



/*! \fn const char* get_arch_signal_vhdl (XhdlSignal* signal);
    \brief 
    \param 
    \return 
*/
const char* get_arch_signal_vhdl (XhdlSignal* signal);



/*! \fn const char* get_body_vhdl (XhdlBody* body);
    \brief 
    \param 
    \return 
*/
const char* get_body_vhdl (XhdlIp *ip , XhdlArch *arch , XhdlBody* body);



/*! \fn const char* get_static_assign_vhdl (XhdlStatic* stat);
    \brief 
    \param 
    \return 
*/
const char* get_static_assign_vhdl (XhdlStatic* stat);



/*! \fn const char* get_affectation_vhdl (XhdlAffectation* aff);
    \brief 
    \param 
    \return 
*/
const char* get_affectation_vhdl (XhdlAffectation* aff);



/*! \fn const char * get_expression_vhdl (XhdlExpression* expr);
    \brief 
    \param 
    \return 
*/
const char * get_expression_vhdl (XhdlExpression* expr);



/*! \fn const char * get_cond_expression_vhdl (XhdlAffectation::cond_expr* cond_expression);
    \brief 
    \param 
    \return 
*/
const char * get_cond_expression_vhdl (XhdlAffectation::cond_expr* cond_expression);


/*! \fn const char * get_instruction_vhdl ( xhdl_instruction *inst);
    \brief 
    \param 
    \return 
*/
const char * get_instruction_vhdl (xhdl_instruction *inst);


/*! \fn const char * get_simple_instruction_vhdl ( xhdl_simple_instruction *inst);
    \brief 
    \param 
    \return 
*/
const char * get_simple_instruction_vhdl (xhdl_simple_instruction *inst);




/*! \fn const char* get_portmap_vhdl (XhdlPortMap* portmap);
    \brief 
    \param 
    \return 
*/
const char* get_portmap_vhdl (XhdlPortMap* portmap);



/*! \fn const char* get_process_vhdl (XhdlProcess* process);
    \brief generate process vhdl
    \param process
    \return 
*/
const char* get_process_vhdl (XhdlProcess *process);


/*! \fn const char* get_sync_process_vhdl ( XhdlArch *arch );
    \brief generate synchronisation process vhdl
    \param process
    \return 
*/
const char* get_sync_process_vhdl (XhdlIp *ip , XhdlArch *arch);



/*! \fn const char* custom_print (const char* x);
    \brief 
    \param 
    \return 
*/
const char* custom_print (const char* x);



/*! \fn const char* show_args (const char* fmt, ...);
    \brief 
    \param 
    \return 
*/
const char* show_args (const char* fmt, ...);


#endif
