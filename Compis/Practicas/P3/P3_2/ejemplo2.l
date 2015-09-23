%{
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "valor.h"
%}
letra [a-zA-Z]
digito [0-9]
%option yylineno
%%
{letra}+    {yylval.sval=( char *) realloc ( yylval.sval , yyleng * sizeof ( char )) ; strcpy ( yylval.sval , yytext ); return ID;}
{digito}+   { yylval.ival = atoi ( yytext );  return ENTERO;}
{digito}*"."{digito}+[Ff]  { yylval.dval = atof ( yytext );   return REAL;}
{digito}*"."{digito}+   { yylval.dval = atof ( yytext ) ;  return DOUBLE;}

%%
int yywrap(){
return 1;
}
int main ( int argc , char ** argv ){
    if( argc > 1) {
        FILE * file ;
        file = fopen ( argv [1] , "r") ;
        if (! file ) {
            fprintf (stderr , "No se puede abrir el archivo %s \n", argv[1]);
            exit (1) ;
        }
        yyin = file ;
    }
    int res=yylex ();
    while(res){
        printf("<%d>",res);
        res=yylex ();
    }
    fclose ( yyin ) ;
    return 0;
}
