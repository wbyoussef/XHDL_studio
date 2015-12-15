%{
  /************** VHDL scanner in LEX format **********
   *
   * Version 0.2 Wed Aug 11, 1993
   *
   * This scanner is derived from a scanner of the ALLIANCE CAD toolset,
   * release 1.1. That toolset was written from:
   *   MASI/CAO-VLSI CAD Team
   *   Laboratoire MASI/CAO-VLSI
   *   Tour 55-65, 2eme etage, Porte 13
   *   Universite Pierre et Marie Curie (PARIS VI)
   *   4, place Jussieu 75252 PARIS Cedex 05, FRANCE
   * The ALLIANCE CAD Toolset can be obtained from ftp site : ftp-masi.ibp.fr    
   *
   * This scanner is avail at: ftp.cs.utwente.nl in pub/src/VHDL/Grammar
   * A corresponding Yacc grammar is available at the same site
   *
   * author of this derived scanner version:
   * Thomas Dettmer
   * Dortmund University
   * Dept. of Computer Scienc, LS1
   * PB 500 500
   * D-44221 Dortmund (Germany)
   * Phone: +49-231-755-6464
   * e-mail: dettmer@ls1.informatik.uni-dortmund.de
   *
   * Please report discovered bugs, critics, suggestions
   * and changes you make to dettmer@ls1.informatik.uni-dortmund.de
   * a list of those that reported repaired (hopefully) errors can be found
   * at the end
   *
   ****************************************************************
   * 
   * This file is intended not to be used for commercial purposes
   * without permission of the University of Dortmund
   *
   * NOTE THAT THERE IS NO WARRANTY FOR CORRECTNES, COMPLETENESS, SUPPORT
   * OR ANYTHING ELSE.
   *******************************************************/
  
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <search.h>
#include<string>
#include<vector>
using namespace std;

#include "vhdl.yacc_tab.cpp.h"

string temp_token;
vector <string> tokens_stack ;

extern FILE* trace_file; 
  
#ifdef BASE_REPRESENTATION
#ifdef ECHO
#undef ECHO
#endif
#define ECHO echo(yytext)
  static void echo(char* s)
  {
    char  loc[YYLMAX];
    int   l;
    l=strlen(s);
    loc[l]='\0';
    while(l--) loc[l]=toupper(*(s+l));  
    //fprintf(yyout, "%s", loc);
  }
#endif
  static void display (char* s)
  {
	fprintf(yyout, "%s", s);
  }

  // update token 
  static void pass_token (char* s) {
    // 
	temp_token = s; 
    yylval.ds_Id.name = s ;
	fprintf (trace_file,"\ntoken : |%s| \n ", s);
    
  }
  int yycolumno=0;
  
  
#define MVL_LG_MC 15
#define MVL_NB_MC 81
  
  int MVL_LINNUM=1;
  
int isatty ( int x)
{
	return 1; 
}
  
%}

upper_case_letter 	  [A-Z]
digit 			  [0-9]
special_character   	  [\#\&\'\(\)\*\+\,\-\.\/\:\;\<\=\>\_\|]
space_character 	  [ \t]
format_effector		  [\t\v\r\l\f]
end_of_line		  \n
lower_case_letter 	  [a-z]
other_special_character   [\!\$\@\?\[\\\]\^\`\{\}\~]

graphic_character	  ({basic_graphic_character}|{lower_case_letter}|{other_special_character})
basic_graphic_character	  ({upper_case_letter}|{digit}|{special_character}|{space_character})
letter		   	  ({upper_case_letter}|{lower_case_letter})
letter_or_digit	   	  ({letter}|{digit})
decimal_literal	   	  {integer}(\.{integer})?({exponent})?
integer		   	  {digit}(_?{digit})*
exponent	   	  ([eE][-+]?{integer})
base		   	  {integer}
based_integer	   	  {extended_digit}(_?{extended_digit})*
extended_digit	   	  ({digit}|[a-fA-F])
base_specifier	  	  (B|b|O|o|X|x)
%%
{space_character}	{
  /* nothing */
#ifndef BASE_REPRESENTATION			
  // pass_token (yytext)  ; /*return(t_Space);*/
#endif
}
\&	{  ; return(t_Ampersand);}
\'	{  ; return(t_Apostrophe);}
\(	{  ; return(t_LeftParen);}
\)	{  ; return(t_RightParen);}
"**"	{  ; return(t_DoubleStar);}
\*	{  ; return(t_Star);}
\+	{  ;;return(t_Plus);}
\,	{  ; return(t_Comma);}
\-	{  ; return(t_Minus);}
":="	{  ; return(t_VarAsgn);}
\:	{  ; return(t_Colon);}
\;	{  ; return(t_Semicolon);}
"<="	{  ; return(t_LESym);}
">="	{  ; return(t_GESym);}
\<	{  ; return(t_LTSym);}
\>	{  ; return(t_GTSym);}
=	{  ; return(t_EQSym);}
\/=	{  ; return(t_NESym);}
"=>"	{  ; return(t_Arrow);}
"<>"	{  ; return(t_Box);}
\|	{  ; return(t_Bar);}
!	{  ; return(t_Bar);}
\.	{  ; return(t_Dot);}
\/	{  ; return(t_Slash);}


or	{  ; return(t_OR);}
abs		{  ; return(t_ABS);}
access		{  ; return(t_ACCESS);}
after		{  ; return(t_AFTER);}
alias		{  ; return(t_ALIAS);}
all		{  ; return(t_ALL);}
and		{  ; return(t_AND);}
architecture	{  ; return(t_ARCHITECTURE);}
array		{  ; return(t_ARRAY);}
assert		{  ; return(t_ASSERT);}
attribute	{  ; return(t_ATTRIBUTE);}
begin		{  ; return(t_BEGIN);}
block		{  ; return(t_BLOCK);}
body		{  ; return(t_BODY);}
buffer		{  ; return(t_BUFFER);}
bus		{  ; return(t_BUS);}
case		{  ; return(t_CASE);}
component	{  ; return(t_COMPONENT);}
configuration	{  ; return(t_CONFIGURATION);}
constant		{  ; return(t_CONSTANT);}
disconnect	{  ; return(t_DISCONNECT);}
downto		{  ; return(t_DOWNTO);}
else		{  ; return(t_ELSE);}
elsif		{  ; return(t_ELSIF);}
end		{  ; return(t_END);}
entity		{  ; return(t_ENTITY);}
exit		{  ; return(t_EXIT);}
file		{  ; return(t_FILE);}
for		{  ; return(t_FOR);}
function		{  ; return(t_FUNCTION);}
generate		{  ; return(t_GENERATE);}
generic		{  ; return(t_GENERIC);}
guarded		{  ; return(t_GUARDED);}
if		{  ; return(t_IF);}
in		{  ; return(t_IN);}
inout		{  ; return(t_INOUT);}
is		{  ; return(t_IS);}
label		{  ; return(t_LABEL);}
library		{  ; return(t_LIBRARY);}
linkage		{  ; return(t_LINKAGE);}
loop		{  ; return(t_LOOP);}
map		{  ; return(t_MAP);}
mod		{  ; return(t_MOD);}
nand		{  ; return(t_NAND);}
new		{  ; return(t_NEW);}
next		{  ; return(t_NEXT);}
nor		{  ; return(t_NOR);}
not		{  ; return(t_NOT);}
null		{  ; return(t_NULL);}
of		{  ; return(t_OF);}
on		{  ; return(t_ON);}
open		{  ; return(t_OPEN);}
others		{  ; return(t_OTHERS);}
out		{  ; return(t_OUT);}
package		{  ; return(t_PACKAGE);}
port		{  ; return(t_PORT);}
procedure	{  ; return(t_PROCEDURE);}
process		
{
  // declare process
  temp_process = new 
  ; 
  return(t_PROCESS);
}
range		{  ; return(t_RANGE);}
record		{  ; return(t_RECORD);}
register		{  ; return(t_REGISTER);}
rem		{  ; return(t_REM);}
report		{  ; return(t_REPORT);}
return		{  ; return(t_RETURN);}
select		{  ; return(t_SELECT);}
severity		{  ; return(t_SEVERITY);}
signal		{  ; return(t_SIGNAL);}
subtype		{  ; return(t_SUBTYPE);}
then		{  ; return(t_THEN);}
to		{  ; return(t_TO);}
transport	{  ; return(t_TRANSPORT);}
type		{  ; return(t_TYPE);}
units		{  ; return(t_UNITS);}
until		{  ; return(t_UNTIL);}
use		{  ; return(t_USE);}
variable		{  ; return(t_VARIABLE);}
wait		{  ; return(t_WAIT);}
when		{  ; return(t_WHEN);}
while		{  ; return(t_WHILE);}
with		{  ; return(t_WITH);}
xor		{  ; return(t_XOR);}



{letter}(_?{letter_or_digit})* 	{

        pass_token (yytext); return ( t_Identifier );
}

({decimal_literal})|({base}#{based_integer}(\.{based_integer})?#({exponent})?)|({base}:{based_integer}(\.{based_integer})?:({exponent})?)		{
    ;pass_token (yytext)
    ; return ( t_AbstractLit );
}

'({graphic_character}|\"|\%)' 	{
    ; return ( t_CharacterLit );
}

(\"({graphic_character}|(\"\")|\%)*\")|(\%({graphic_character}|(\%\%)|\")*\%) {
    ; return ( t_StringLit );
}

{base_specifier}(\"{extended_digit}(_?{extended_digit})*\"|\%{extended_digit}(_?{extended_digit})*\%) 							{
    ; return ( t_BitStringLit );
}

\n	{
  /* end of line */
  MVL_LINNUM++;
  /* tobuf( "\n%4d\t", MVL_LINNUM);*/
  yycolumno=0;
  /*return(t_NEWLINE);*/
}

\-\-.*$ 								{
  /* comment */
#ifndef BASE_REPRESENTATION
    ;
#endif
  /*return(t_COMMENT);*/
}
.									{
   ; /*return (t_UNKNOWN);*/
}
%%
/************************************************************
 * J.Gaisler reported:
 * 	MVL_NB_MC should be set to 81 - done
 * The original of this stuff was an illegal and wrong pointer
 *************************************************************/

int yywrap()
	{
	return 1;
	}
