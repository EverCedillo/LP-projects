%{
	#include <stdio.h>
	#include "clases.h"
	#include <string.h>
	

%}

%option noyywrap yylineno

digito [0-9]
letra [a-zA-Z_]
entero {digito}+
real {digito}*"."{digito}+ 
%%

if			{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );
			pos+=yyleng;lineno=yylineno;
			return _IF;}
while		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );pos+=yyleng;lineno=yylineno;
			return _WHILE;}
float		{yylval.sval = ( char *) realloc ( yylval.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.sval , yytext );pos+=yyleng;lineno=yylineno;
			return _FLOAT;}
double		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _DOUBLE;}
char		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _CHAR;}
bool		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _BOOL;}
int			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _INT;}
else		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _ELSE;}
true		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _TRUE;}
false		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return _FALSE;}
"+=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MAS_IGU;}
"-=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return RES_IGU;}
"*=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MUL_IGU;}
"/=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return DIV_IGU;}
"%=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MOD_IGU;}
"+" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MAS;}
"-" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return RES;}
"*" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MUL;}
"%"  		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MOD;}
"/" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return DIV;}
"=="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return IGU_IGU;}
"!="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return DIF;}
">="		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MAY_IGU;}
"<=" 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MEN_IGU;}
"<"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MEN;}
">"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return MAY;}
"="			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return IGU;}
";"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return PYC;}
"," 		{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return COM;}
"{"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return LLA;}
"}"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return LLC;}
"("			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return PAA;}
")"			{yylval . sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
			return PAC;}
{letra}+({letra}|{digito})* 	{yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
								strcpy ( yylval .sval , yytext );pos+=yyleng;lineno=yylineno;
								return ID;}
{real}[fF]  {yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			yylval.dval = atof(yytext);pos+=yyleng;lineno=yylineno;
			return NUM;}
{real} 		{yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			yylval.fval = atof(yytext);pos+=yyleng;lineno=yylineno;
			return NUM;}
{entero}	{yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
			strcpy ( yylval .sval , yytext );
			yylval.ival =atoi(yytext);pos+=yyleng;lineno=yylineno;
			return NUM;}
\'{digito}\'|\'{letra}\' 	{yylval.cval = yytext[1];pos+=yyleng;lineno=yylineno;
							return CAR;}
[ t]		{pos+=yyleng;lineno=yylineno;}
\n			{pos=0;}
.	{printf("Error lexico (simbolo desconocido) en linea %d y col %d\n", yylineno,pos);pos+=yyleng;lineno=yylineno;}



%%

parse_in(FILE*file){
	yyin=file;
}

/*
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



