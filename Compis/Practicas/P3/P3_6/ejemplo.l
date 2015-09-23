%{
# include <stdio.h>
%}
%option noyywrap

letra [a-z]
digito [0-9]

%x uno
%x dos
%x tres
%x cuatro
%s cinco
%s seis
%s siete

%%

<INITIAL>{letra} {BEGIN uno; printf("cero a uno");}
<INITIAL>{digito} {BEGIN cuatro; printf("cero a cuatro");}
<INITIAL>- {BEGIN tres; printf("cero a tres");}
<INITIAL>"+" {BEGIN dos; printf("cero a dos");}
<uno>{letra} {BEGIN uno; printf("uno a uno");}
<uno>{digito} {BEGIN uno; printf("uno a uno");}
<cuatro>{digito} {BEGIN cuatro; printf("cuatro a cuatro");}
<cuatro>e {BEGIN cinco; printf("cuatro a cinco");}
<cinco>{digito} {BEGIN siete; printf("cinco a siete");}
<cinco>"-"|"+" {BEGIN seis; printf("cinco a seis");}
<seis>{digito} {BEGIN siete; printf("seis a siete");}
<siete>{digito} {BEGIN siete; printf("siete a siete");}

.|\n {}
%%
int main () {
yylex () ;
return 0;
}

