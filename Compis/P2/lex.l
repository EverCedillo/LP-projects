%{
	#include <stdio.h>
	#include "clases.h"
	#include <stdlib.h>
	# include <string.h>
%}

%option noyywrap yylineno

digito [0-9]
letra [a-zA-Z_]
entero {digito}+
real {digito}*"."{digito}+ 
%%

if			{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );
			pos+=yyleng;
			return _IF;}
while		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );pos+=yyleng;
			return _WHILE;}
float		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );pos+=yyleng;
			return _FLOAT;}
double		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _DOUBLE;}
char		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _CHAR;}
bool		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _BOOL;}
int			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _INT;}
else		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _ELSE;}
true		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _TRUE;}
false		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return _FALSE;}
"+=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MAS_IGU;}
"-=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return RES_IGU;}
"*=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MUL_IGU;}
"/=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return DIV_IGU;}
"%=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MOD_IGU;}
"+" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MAS;}
"-" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return RES;}
"*" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MUL;}
"%"  		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MOD;}
"/" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return DIV;}
"=="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return IGU_IGU;}
"!="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return DIF;}
">="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MAY_IGU;}
"<=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MEN_IGU;}
"<"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MEN;}
">"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return MAY;}
"="			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return IGU;}
";"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return PYC;}
"," 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return COM;}
"{"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return LLA;}
"}"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return LLC;}
"("			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return PAA;}
")"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;
			return PAC;}
{letra}+({letra}|{digito})* 	{yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
								strcpy ( yylval .sval , yytext );pos+=yyleng;
								return ID;}

{real}[fF]  {yylval.dval = atof(yytext);pos+=yyleng;
			return NUM;}
{real} 		{yylval.dval = atof(yytext);pos+=yyleng;
			return NUM;}
{entero}	{yylval.ival = atoi(yytext);pos+=yyleng;
			return NUM;}
\'{digito}\'|\'{letra}\' 	{yylval.cval = yytext[0];pos+=yyleng;
							return CAR;}
[ t]		{pos+=yyleng;}
\n			{pos=0;}
.	{printf("\nError en linea %d", yylineno);pos+=yyleng;}



%%

// /*
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
        printf("\n<%d>(%d,%d)%s",res,yylineno,pos,yytext);
        res=yylex ();
    }
    fclose ( yyin ) ;
    return 0;
}
// */



