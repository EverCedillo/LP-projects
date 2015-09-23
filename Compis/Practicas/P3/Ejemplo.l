/* Analizador Lexico para un lenguaje estilo de Pascal */
/* Inicia codigo en C */

%{
	#include <stdio.h>
%}

/* Variables de expresiones regulares */

digito [0-9]

id [a-z][a-z0-9]*

%% /* Seccion de E s p e c i f i c a c i o n Lexica */

if|then|begin|end|procedure|function { printf ( " Una palabra clave : %s\n", yytext ); }
{id} { printf ( "Un identificador : %s, de longitud %d\n", yytext , yyleng ) ;}
{digito}+ { printf ( "Un entero : %s (%d)\n", yytext , atoi ( yytext ) ) ;}
{digito}*"."{digito}+ { printf ( "Un real : %s (%g)\n", yytext , atof ( yytext ) ) ;}
"+"|"-"|"*"|"/" { printf ( "Un operador : %s\n", yytext ) ;}
"{"[^\n]*"}" {/* ignora los comentarios */}
[ \t\n]+ {/* ignora los espacios en blanco */}
. { printf ( " Caracter no reconocido : %s\n", yytext ) ;}

%% 
/* Codigo de usuario */
int main (int argc , char ** argv ){
	yylex();
	return 0;
}

