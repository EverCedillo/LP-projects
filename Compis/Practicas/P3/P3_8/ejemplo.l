%{

	#include <stdio.h>
%}
%x comment

%%

     
<INITIAL>"/*"         {BEGIN(comment);}
<comment>[^*\n]*        
<comment>"*"+[^*/\n]*   
<comment>\n             
<comment>"*"+"/"        {BEGIN(INITIAL); printf("comment\n");}

%%

int main () {
yylex () ;
return 0;
}
