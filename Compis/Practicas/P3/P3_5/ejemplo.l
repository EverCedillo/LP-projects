%{
# include <stdio.h>
%}
%option noyywrap
/* Declaracion de los estados */
%x una_a
%x una_b
%s dos_as
%s dos_bs

%%
<INITIAL>a { BEGIN una_a ; printf (" estado initial , con a") ;}
<INITIAL>b { BEGIN una_a ; printf (" estado initial , con b") ;}
<una_a>a { BEGIN dos_as ; printf (" estado una_a , con a") ;}
<una_a>b { BEGIN una_b ; printf (" estado una_a , con b") ;}
<una_b>a { BEGIN una_a ; printf (" estado una_b , con a") ;}
<una_b>b { BEGIN dos_bs ; printf (" estado una_b , con b") ;}
<dos_as>. { printf (" estado dos_a ") ; yyless (0) ; BEGIN INITIAL ;}
<dos_bs>. { printf (" estado una_a ") ; yyless (0) ; BEGIN INITIAL ;}
.|\n {}

%%
int main () {
yylex () ;
return 0;
}
