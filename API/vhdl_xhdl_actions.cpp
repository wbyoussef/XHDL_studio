#include "vhdl_xhdl_actions.h"
#include "XhdlClasses.h"
#include "ninja_editor.h"


XhdlIp* conv_main_ip = new XhdlIp(); 
XhdlExpression * output_expression = new XhdlExpression (); 
vector<XhdlExpression *> expressions ; 
string test_string ;
string output_string ; 
string temp_target ; 
XhdlSignal* temp_signal; 


xhdl_instruction* temp_expression; 
XhdlArch* architecture = new XhdlArch (conv_main_ip); 
XhdlProcess* process = new XhdlProcess(architecture->body); 
bool is_in_entity ;

void relation_BOOL_relation ( const char* bool_op) 
{
  XhdlExpression* temp_expression = new XhdlExpression (); 
  XhdlExpression* temp_expression1 = expressions[expressions.size()-1];
  expressions.pop_back();
  XhdlExpression* temp_expression2 = expressions[expressions.size()-1];
  expressions.pop_back();
  
  temp_expression->type = XHDLEXPRESSION_TYPE_EXPR ; 
  temp_expression->expr2 = temp_expression2;
  temp_expression->expr3 = temp_expression1;
  temp_expression->op = bool_op ; 
  expressions.push_back (temp_expression);
  /**/
}


void push_name ()
{
  XhdlExpression* temp_expression = new XhdlExpression (); 
  temp_expression->type = XHDLEXPRESSION_TYPE_SIG_NAME ; 
  temp_expression->sig_name = temp_token ; 
  expressions.push_back (temp_expression);
  
}


void seq_stats_action ()
{
  //
  //	printf ("\n seq_stats_action \n"); 
  temp_expression = new xhdl_instruction (process) ; 
}

void signal_assign_stat_action () 
{
  //	printf ("\n signal_assign_stat_action \n"); 
}


void target_action ()
{
  temp_target = temp_token; 
}



void entity_start_action ()
{
  //	printf ("\n entity_start_action \n"); 
  conv_main_ip->entity->name = temp_token; 
  is_in_entity = true ; 
  temp_signal = new XhdlSignal (conv_main_ip);
}


// format the extracted IP 
void format_ip ()
{
  // if no rtl architrecture is there, add it 
  if ( !does_arch_exist ( conv_main_ip , "rtl"  ) )
    {
      add_arch ( conv_main_ip , "rtl"  ); 
    }
  // convert std_logic_vector => later 
  // set package architecture 
  conv_main_ip->package->name = conv_main_ip->entity->name ;
  
  
}
