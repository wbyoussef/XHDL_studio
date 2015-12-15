#ifndef NINJA_CHECKER_H
#define NINJA_CHECKER_H
/* 
Avaialble checkers 

   * check duplicated names : done 
   * check good signal_names : done 
   * check duplicated process names : done 
   * check duplicated instances : done 
   * check signal types : done
   * check uknown signals done



Avalaible linters :


*/

#include "XhdlIp.h"

class XhdlSignal; 

//#include "regex.h"
// {{{ checker output type

struct check_result_t {
  bool passed;
  string* report;  
};

// }}}

void test (void);
bool are_equal_strings (const char* s1, const char* s2);
bool check_string_regexmatch (const char* regexpression, const char* string_to_match);
int nb_occurences (const char* str1, const char* str2);

// {{{  const char* ip_check_duplicated_signals (XhdlIp* ip);

/*! \fn const char* ip_check_duplicated_signals (XhdlIp* ip);
    \brief 
    \param ip : is a pointer to the checked IP
    \return check report
*/
check_result_t* ip_check_duplicated_signals (XhdlIp* ip);
const char * report_ip_check_duplicated_signals (XhdlIp* ip);

// }}}

// {{{  const char* ip_check_duplicated_processes (XhdlIp* ip, const char* arch_name);

/*! \fn const char* ip_check_duplicated_processes (XhdlIp* ip, const char* arch_name);
    \brief 
    \param ip : is a pointer to the checked IP
    \return check report
*/
check_result_t* ip_check_duplicated_processes (XhdlIp* ip, const char* arch_name);

// }}}


// {{{  const char *ip_check_label_names ( const char *sig_name );
/*! \fn const char *ip_check_label_names ( XhdlIp *ip , const char * arch_name );
    \brief check is labels have a valid name
    \param ip : is a pointer to the checked IP
    \param arch_name : is the name of the checked architecture
    \return check report
*/
bool check_label_name ( const char *sig_name );
check_result_t* ip_check_label_names ( XhdlIp *ip , const char* arch_name );
const char* report_ip_check_label_names (XhdlIp *ip , const char * arch_name);
// }}}


// {{{  const char *ip_check_signals_type ( const char *sig_name );
/*! \fn const char *ip_check_label_names ( XhdlIp *ip , const char * arch_name );
    \brief check is labels have a valid name
    \param ip : is a pointer to the checked IP
    \param arch_name : is the name of the checked architecture
    \return check report
*/
 bool is_valid_type (  XhdlIp *ip , const char* arch_name , const char * type );
 check_result_t* ip_check_signals_type( XhdlIp *ip , const char* arch_name );
 const char * report_ip_check_signals_type( XhdlIp *ip , const char* arch_name );

// }}}

// {{{  const char *ip_check_duplicated_instances ( const char *sig_name );
/*! \fn const char *ip_check_duplicated_instances ( XhdlIp *ip , const char * arch_name );
    \brief check duplicated instances
    \param ip : is a pointer to the checked IP
    \param arch_name : is the name of the checked architecture
    \return check report
*/
 bool is_duplicated ( XhdlIp *ip , const char* arch_name ,const char* instance1 );
 check_result_t* ip_check_duplicated_instances (XhdlIp *ip , const char * arch_name );
 const char * report_ip_check_duplicated_instances ( XhdlIp *ip , const char * arch_name );

// }}}

// {{{  const char *ip_check_unknown_signals ( XhdlIp *ip , const char *sig_name );
/*! \fn const char *ip_check_unknown_signals ( XhdlIp *ip , const char * arch_name );
    \brief check used signals
    \param ip : is a pointer to the checked IP
    \param arch_name : is the name of the checked architecture
    \return check report
*/
 
 check_result_t* ip_check_unknown_signals (XhdlIp *ip , const char * arch_name );
 const char * report_ip_check_unknown_signals ( XhdlIp *ip , const char * arch_name );

// }}}


 check_result_t* ip_check_entity (XhdlIp *ip );
 const char * report_ip_check_entity ( XhdlIp *ip);
check_result_t* check_io_signal_structure (const XhdlSignal *signal );

// }}}

//
bool match(const char *string,const  char *pattern);

// check whether a string matches a regular expression
bool match(const char *string,const char *pattern);

#endif
