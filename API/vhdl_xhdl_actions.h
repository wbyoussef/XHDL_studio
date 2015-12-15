#ifndef VHDL_XHDL_ACTIONS_H
#define VHDL_XHDL_ACTIONS_H


// Libs 
#include <malloc.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

// project libs 
#include "vhdl_xhdl_actions.h" // parser actions
#include "XhdlClasses.h"	// XHDL classes 

void yyerror (char* s);	// lex function 
int yylex ( void );		// les function

// parser variables 
extern string temp_token;	// lex additional token 

extern XhdlIp* conv_main_ip; // output IP
extern XhdlExpression * output_expression; 
extern vector<XhdlExpression *> expressions ; 
extern xhdl_instruction* temp_expression; 
extern XhdlSignal* temp_signal; 

// debug variables
extern string test_string ;
extern string output_string ; 
extern string temp_target ; 
extern bool is_in_entity ;

// parser fcuntions 
void relation_BOOL_relation ( const char* bool_op) ;
void push_name (); 
void seq_stats_action ();
void signal_assign_stat_action () ; 
void target_action (); 



void entity_start_action ();

// format the extracted IP 
void format_ip (); 


#endif // VHDL_XHDL_ACTIONS_H
