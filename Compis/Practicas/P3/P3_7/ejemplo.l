%{
#   include <stdio.h>
%}


%%

"/*"([^*]|\*[^/])*"*/" {printf("Comentario\n");}
[\n\t ] {}
.+ {printf("No fue un comentario\n");}
%%

int main () {
yylex () ;
return 0;
}


