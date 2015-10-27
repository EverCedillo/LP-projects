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
			return _IF;}
while		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );
			return _WHILE;}
float		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );
			return _FLOAT;}
double		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _DOUBLE;}
char		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _CHAR;}
bool		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _BOOL;}
int			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _INT;}
else		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _ELSE;}
true		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _TRUE;}
false		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return _FALSE;}
"+=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MAS_IGU;}
"-=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return RES_IGU;}
"*=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MUL_IGU;}
"/=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return DIV_IGU;}
"%=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MOD_IGU;}
"+" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MAS;}
"-" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return RES;}
"*" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MUL;}
"%"  		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MOD;}
"/" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return DIV;}
"=="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return IGU_IGU;}
"!="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return DIF;}
">="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MAY_IGU;}
"<=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MEN_IGU;}
"<"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MEN;}
">"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return MAY;}
"="			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			return IGU;}
{letra}+({letra}|{digito})* 	{yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
								strcpy ( yylval .sval , yytext );
								return ID;}

{real}[fF]  {yylval.dval = atof(yytext);
			return NUM;}
{real} 		{yylval.dval = atof(yytext);
			return NUM;}
{entero}	{yylval.ival = atoi(yytext);
			return NUM;}


%%

 /*
int main (int argc , char ** argv ){
	printf("%d",yylex());
	return 0;
}
// */



