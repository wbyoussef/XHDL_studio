
// standard libs 
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Xhdl classes 
#include "XhdlClasses.h"


// linked variables 

// enables debugging parser 
extern int yydebug;
// input and output standard stream 
extern FILE *yyin, *yyout;
// parser ip output 
extern XhdlIp* conv_main_ip; 


int yyparse (void);
void yyerror (char* s);

extern int MVL_LINNUM;

// output trace file 
FILE* trace_file; 

int  main (int argc,char** argv)
{
  /*
    if ( check_string_regexmatch ("Hello","hello"))
    {
    cout <<  "gooood ...\n";
    }
    else 
    {
    cout <<  "Oh noooo ...\n";
    }
  */
  
  // program constants 
  char* infilename;
  trace_file = fopen("c:\\x.log","w"); 
  yydebug = 1;  
  
  // checks first program argument (input file)
  if (argc>1){
    infilename=(char*)malloc(sizeof(char)*strlen(argv[1])+1);
    strcpy(infilename, argv[1]);
    if ((yyin=fopen(argv[1],"r"))==NULL){
      yyerror("unable to open inputfile");
    }    
    argc--;
    argv++;
  }else{
    infilename=" ";
  }
  
  // second program argument (output filename)
  if (argc>1){
    if ((yyout=fopen(argv[1],"w"))==NULL){
      yyerror("could not open outputfile\n");
    }
  }
  
  // start parser 
  yyparse();
  
  // close trace_file 
  fclose (trace_file);
  fclose (yyin);
  fclose (yyout);
  
  // generate xml file 
  //   ip_gen_xml (conv_main_ip);
  //   if (argc>1){
  //     if ((yyout=fopen(argv[1],"w"))==NULL){
  //       yyerror("could not open output XML file\n");
  //     }
  //   }
  save_string_to_file (ip_gen_xml (conv_main_ip), "c:\\x.xml"); 
  
  // generae vhdl file 
  get_ip_vhdl (conv_main_ip);
  scanf ("sdfsdf"); 
  
}





void yyerror (char* s)
{
  printf ("Error :  %s", s); 
}

