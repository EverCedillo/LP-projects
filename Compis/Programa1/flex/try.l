%{

	#include <stdio.h>
	#include <string.h>
	#define RESERVADA 1
	#define ENTERO 2
	#define REAL 3
	#define ESPECIAL 4
	#define ID 5
	#define RELACIONAL 6
	#define ASIGNACION 7
	#define ARITMETICO 8
%}



letra [a-zA-Z]
digito [0-9]

%%


[\n\t ] {printf("espacio mil\n");}
(float|int|bool|if|true|false)[^\n\t ] {printf("%s",yytext); return RESERVADA;}
@{letra}({digito}{letra})*[^\n\t ] {printf("%s",yytext); return ID;}

{digito}+[^\n\t ] {printf("%s",yytext); return ENTERO;}
{digito}*.{digito}+ {printf("%s",yytext); return REAL;}
#.* {printf("comentario\n");}
[*+-/] {printf("%s",yytext); return ARITMETICO;}
[{()}] {printf("%s",yytext); return ESPECIAL;}

"<"|">"|"<="|">="|"==" {printf("%s",yytext); return RELACIONAL;}
= {printf("%s",yytext); return ASIGNACION;}

.* {printf("ño: %s\n",yytext);}
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
        printf("<%d>\n",res);
        res=yylex ();
    }
    fclose ( yyin ) ;
    return 0;
}
