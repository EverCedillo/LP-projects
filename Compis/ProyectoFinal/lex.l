%{
	#include <stdio.h>
//	#include "clases.h"
	#include <string.h>
	# include "y.tab.h"
	
int pos;
int lineno;
%}

%option noyywrap yylineno

digito [0-9]
letra [a-zA-Z]
letrag [a-zA-Z_]
entero {digito}+
real {digito}*"."{digito}+ 
charset [\x20-\x21\x23-\xFE]
%%

if			{return reserved_word(yytext, yylineno, yyleng,IF);}
while		{return reserved_word(yytext, yylineno, yyleng,WHILE);}
float		{return reserved_word(yytext, yylineno, yyleng,FLOAT);}
double		{return reserved_word(yytext, yylineno, yyleng,DOUBLE);}
char		{return reserved_word(yytext, yylineno, yyleng,CHAR);}

int			{return reserved_word(yytext, yylineno, yyleng,INT);}
else		{return reserved_word(yytext, yylineno, yyleng,ELSE);}

void		{return reserved_word(yytext, yylineno, yyleng,VOID);}
for			{return reserved_word(yytext, yylineno, yyleng,FOR);}
case		{return reserved_word(yytext, yylineno, yyleng,CASE);}
switch		{return reserved_word(yytext, yylineno, yyleng,SWITCH);}
break		{return reserved_word(yytext, yylineno, yyleng,BREAK);}
do			{return reserved_word(yytext, yylineno, yyleng,DO);}
default		{return reserved_word(yytext, yylineno, yyleng,DEFAULT);}
scan		{return reserved_word(yytext, yylineno, yyleng,SCAN);}
print		{return reserved_word(yytext, yylineno, yyleng,PRINT);}
return		{return reserved_word(yytext, yylineno, yyleng,RETURN);}
struct		{return reserved_word(yytext, yylineno, yyleng,STRUCT);}



"+=" 		{return save_token(yytext,yylineno,yyleng,MAS_IGU);}
"-=" 		{return save_token(yytext,yylineno,yyleng,RES_IGU);}
"*=" 		{return save_token(yytext,yylineno,yyleng,MUL_IGU);}
"/=" 		{return save_token(yytext,yylineno,yyleng,DIV_IGU);}
"%=" 		{return save_token(yytext,yylineno,yyleng,MOD_IGU);}
"+" 		{return save_token(yytext,yylineno,yyleng,MAS);}
"-" 		{return save_token(yytext,yylineno,yyleng,RES);}
"++" 		{return save_token(yytext,yylineno,yyleng,MAS_MAS);}
"--" 		{return save_token(yytext,yylineno,yyleng,RES_RES);}
"*" 		{return save_token(yytext,yylineno,yyleng,MUL);}
"%"  		{return save_token(yytext,yylineno,yyleng,MOD);}
"/" 		{return save_token(yytext,yylineno,yyleng,DIV);}
"=="		{return save_token(yytext,yylineno,yyleng,IGU_IGU);}
"!="		{return save_token(yytext,yylineno,yyleng,DIF);}
">="		{return save_token(yytext,yylineno,yyleng,MAY_IGU);}
"<=" 		{return save_token(yytext,yylineno,yyleng,MEN_IGU);}
"<"			{return save_token(yytext,yylineno,yyleng,MEN);}
">"			{return save_token(yytext,yylineno,yyleng,MAY);}
"="			{return save_token(yytext,yylineno,yyleng,IGU);}
"||"		{return save_token(yytext,yylineno,yyleng,OR);}
"&&"		{return save_token(yytext,yylineno,yyleng,AND);}
"!"			{return save_token(yytext,yylineno,yyleng,NOT);}



";"			{return save_token(yytext,yylineno,yyleng,PYC);}
"."			{return save_token(yytext,yylineno,yyleng,PT);}
":"			{return save_token(yytext,yylineno,yyleng,DPT);}
"," 		{return save_token(yytext,yylineno,yyleng,COM);}
"{"			{return save_token(yytext,yylineno,yyleng,LLA);}
"}"			{return save_token(yytext,yylineno,yyleng,LLC);}
"("			{return save_token(yytext,yylineno,yyleng,PAA);}
")"			{return save_token(yytext,yylineno,yyleng,PAC);}
"["			{return save_token(yytext,yylineno,yyleng,COA);}
"]"			{return save_token(yytext,yylineno,yyleng,COC);}


{letrag}+({letrag}|{digito})* 	{return save_id(yytext,yylineno,yyleng,ID);}

{real}[fF]  {return save_var(yytext,yylineno,yyleng,NUM_F);}
{real} 		{return save_var(yytext,yylineno,yyleng,NUM_D);}
{entero}	{return save_var(yytext,yylineno,yyleng,NUM_I);}

\'{charset}\'			 	{return save_var(yytext,yylineno,yyleng,CAR);}
\"{charset}*\"				{return save_var(yytext,yylineno,yyleng,CAD);}
"/*"([^*]|\*+[^*/])*\*+"/" {pos+=yyleng;lineno=yylineno;}
"//"[^\n]*	{pos+=yyleng;lineno=yylineno;}

[ t]		{pos+=yyleng;lineno=yylineno;}
\n			{pos=0;}
.	{printf("Error lexico (simbolo desconocido) en linea %d y col %d\n", yylineno,pos);pos+=yyleng;lineno=yylineno;}



%%
parse_in(FILE*file){
	yyin=file;
}

int reserved_word(char * yytext, int yylineno, int yyleng,int type){

	printf("%s\n",yytext);
	yylval.y.sval = ( char *) realloc ( yylval.y.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.y.sval , yytext );
			pos+=yyleng;lineno=yylineno;
	return type;
}
int save_id(char * yytext, int yylineno, int yyleng,int type){
		printf("%s\n",yytext);
	yylval.y.sval = ( char *) realloc ( yylval.y.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.y.sval , yytext );
			pos+=yyleng;lineno=yylineno;
	return type;
}

int save_token(char * yytext, int yylineno, int yyleng,int type){
	printf("%s\n",yytext);
	yylval.y.sval = ( char *) realloc ( yylval.y.sval , yyleng * sizeof ( char ));
			strcpy ( yylval.y.sval , yytext );
			pos+=yyleng;lineno=yylineno;
	return type;
}

int save_var(char * yytext, int yylineno, int yyleng,int type){
//	yylval.sval = ( char *) realloc ( yylval .sval , yyleng * sizeof ( char ));
//	strcpy ( yylval .sval , yytext );
	pos+=yyleng;lineno=yylineno;

	switch(type){
		case NUM_F:
			yylval.y.fval = atof(yytext);
		break;
		case NUM_D:
			yylval.y.dval = atof(yytext);
		break;
		case NUM_I:
			yylval.y.ival = atoi(yytext);
		break;
		case CAR:
			yylval.y.cval = yytext[1];pos+=yyleng;lineno=yylineno;
		break;
		case CAD:
		//Already done!
		break;
				
	}
	return type;
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
        printf("<%d>",res);
        res=yylex ();
    }
    fclose ( yyin ) ;
    return 0;
}*/





