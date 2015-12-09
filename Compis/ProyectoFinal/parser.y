%{
	#include <stdio.h>

	#include <string.h>
	#include <math.h>

extern int pos;
extern int lineno;




void yyerror(char *s);
%}

%union {
	struct{
	int pos;
	int line;
    int ival;
    float fval ;
    double dval ;
    char cval;
    char * sval ;
	}y;
}




%token <y.dval> NUM_D
%token <y.ival> NUM_I
%token <y.fval> NUM_F
%token <y.cval> CAR
%token <y.sval> CAD


%token IF 
%token FLOAT 
%token DOUBLE
%token CHAR 
%token BOOL 
%token INT 
%token ELSE
%token _TRUE 
%token _FALSE 
%token MAS 
%token RES 
%token MUL 
%token MOD 
%token DIV 
%token IGU_IGU 
%token DIF 
%token MAY_IGU 
%token MEN_IGU 
%token MEN 
%token MAY 
%token IGU 
%token ID 
%token WHILE
%token MAS_IGU 
%token RES_IGU 
%token MUL_IGU 
%token DIV_IGU 
%token MOD_IGU 
%token PYC 
%token COM
%token LLA
%token LLC
%token PAA
%token PAC
%token FOR
%token SWITCH
%token CASE
%token BREAK
%token VOID
%token PRINT
%token SCAN
%token STRUCT
%token RETURN
%token DO
%token COA
%token COC
%token DEFAULT
%token OR
%token AND
%token NOT
%token MAS_MAS
%token RES_RES
%token DPT
%token PT


%right RES_RES MAS_MAS NOT
%left MUL DIV MOD
%left MAS RES
%left MEN MEN_IGU MAY MAY_IGU
%left IGU_IGU DIF
%left AND
%left OR
%right IGU MAS_IGU RES_IGU DIV_IGU MUL_IGU MOD_IGU

%start program



%%

/*Gramar Section*/

program 	:l_decl;
l_decl	 	:l_decl decl
			|decl;
decl		:decl_var
			|decl_fun
			|t_struct;
decl_var	:type l_var PYC|error;
l_var		:l_var COM l
			|l;
l			:ID arr;
arr			:COA NUM_I COC arr
			|;
type		:INT
			|BOOL
			|FLOAT
			|DOUBLE
			|CHAR
			|VOID
			|t_struct;
t_struct	:STRUCT ID LLA c_struct LLC
			|STRUCT LLA c_struct LLC
			|STRUCT ID;
c_struct	:c_struct decl_var
			|decl_var;
decl_fun	:type ID PAA params PAC bloque;
params 		:l_param
			|VOID;
l_param		:l_param COM param
			|param;
param		:type ID arrparam;
arrparam	:COA COC arrparam
			|;
bloque		:LLA decl_local l_sent LLC;
decl_local	:decl_local decl_var
			|;
l_sent		:l_sent sent
			|;
sent		:s_exp
			|s_if
			|s_while
			|s_do
			|s_switch
			|s_for
			|s_break
			|s_return
			|bloque
			|s_print	
			|s_scan;
s_exp		:exp PYC
			|PYC;
s_if		:IF PAA exp PAC sent s_else;
s_else		:ELSE sent
			|;
s_while		:WHILE PAA exp PAC sent;
s_do		:DO sent WHILE PAA exp PAC PYC;
s_switch	:SWITCH PAA ID PAC LLA l_casos c_default LLC;
l_casos		:l_casos s_case
			|s_case;
s_case		:CASE NUM_I DPT sent s_break;
c_default	:DEFAULT DPT sent s_break
			|;
s_for		:FOR PAA exp PYC exp PYC s_inc PAC sent;
s_break		:BREAK PYC;
s_inc		:ID MAS_MAS
			|ID RES_RES;
s_print		:PRINT PAA exp PAC PYC;
s_scan		:SCAN PAA ID PAC;
s_return	:RETURN PYC 
			|RETURN exp;
exp			:var o_asig exp|error
			|e_simple;
o_asig		:IGU
			|MAS_IGU
			|RES_IGU
			|MUL_IGU
			|DIV_IGU
			|MOD_IGU;
var			:ID v_arr
			|ID PT ID;
v_arr		:COA exp COC v_arr
			|;
e_simple	:e_simple o_relac opnd
			|e_simple o_logic opnd
			|opnd;
o_logic		:AND
			|OR;
o_relac		:MEN_IGU
			|MAY_IGU
			|MEN
			|MAY
			|IGU_IGU
			|DIF;
opnd		:opnd o_adic term
			|term;
o_adic		:MAS
			|RES;
term		:term o_mul factor
			|factor;
o_mul		:MUL
			|DIV
			|MOD;
factor		:var
			|call
			|PAA exp PAC
			|NUM_I
			|NUM_F
			|NUM_D
			|CAR
			|CAD
			|NOT exp
			|RES exp;
call		:ID PAA arg PAC;
arg			:l_arg
			|;
l_arg		:l_arg COM exp
			|exp;


%%

extern FILE *yyin;

void yyerror(char *s){
	fprintf(stderr,"%s token no esperado en linea %d y columna %d\n", s,lineno,pos);
	return;
}


int main(int argc, char *argv[]){
	if(argc==2){
		yyin = fopen(argv[1], "rt");
		if(yyin == NULL){
			printf("El fichero %s no se puede abrir\n", argv[1]);
			exit(1);
		}
	}
	yyparse();
	return 0;
}


