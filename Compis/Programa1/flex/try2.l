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

%option yylineno

letra [a-z]
digito [0-9] 

%s edo_0
%s edo_1
%s edo_2
%s edo_3
%s edo_4
%s edo_5
%s edo_6
%s edo_7
%s edo_8
%s edo_9
%s edo_10
%s edo_11
%s edo_12
%s edo_13
%s edo_14
%s edo_15
%s edo_16
%s edo_17
%s edo_18
%s edo_19
%s edo_20
%s edo_21
%s edo_22
%s edo_23
%s edo_24
%s edo_25
%s edo_26
%s edo_27
%s edo_28
%s edo_29
%s edo_30
%s edo_31
%s edo_32
%s edo_33
%s edo_34
%s edo_35
%s edo_36
%s edo_37
%s edo_38
%s edo_39
%s edo_40

%%
<INITIAL>i {printf("i"); BEGIN edo_1;}
<INITIAL>t {BEGIN edo_4;}
<INITIAL>f {BEGIN edo_2;}
<INITIAL>e {BEGIN edo_5;}
<INITIAL>b {BEGIN edo_3;}
<INITIAL>{digito} {BEGIN edo_6;}
<INITIAL>\. {BEGIN edo_7;}
<INITIAL>[+*/-] {BEGIN edo_11;}
<INITIAL>[\n\t ] {BEGIN edo_15;}
<INITIAL># {BEGIN edo_13;}
<INITIAL>[{}()] {BEGIN edo_12;}
<INITIAL>@ {BEGIN edo_14;}
<INITIAL>> {BEGIN edo_9;}
<INITIAL>< {BEGIN edo_10;}
<INITIAL>= {BEGIN edo_8;}

<edo_1>n {BEGIN edo_24;}
<edo_1>f {return RESERVADA; BEGIN edo_25;}

<edo_2>l {BEGIN edo_20;}
<edo_2>a {BEGIN edo_16;}

<edo_3>o {BEGIN edo_27;}

<edo_4>r {BEGIN edo_30;}

<edo_5>l {BEGIN edo_33;}

<edo_6>{digito} {BEGIN edo_6;}
<edo_6>\. {BEGIN edo_7;}
<edo_6>. {}

<edo_7>{digito} {BEGIN edo_36;}

<edo_8>= {BEGIN edo_37;}

<edo_9>= {BEGIN edo_37;}

<edo_10>= {BEGIN edo_37;}

<edo_11>.|\n {}

<edo_12>. {}

<edo_13>[^\n] {BEGIN edo_13;}

<edo_14>{letra} {BEGIN edo_40;}

<edo_15>. {}

<edo_16>l {BEGIN edo_17;}

<edo_17>s { BEGIN edo_18;}

<edo_18>e {return RESERVADA; BEGIN edo_19;}

<edo_19>. {}

<edo_20>o {BEGIN edo_21;}

<edo_21>a {BEGIN edo_22;}

<edo_22>t {return RESERVADA; BEGIN edo_23;}

<edo_23>. {}

<edo_24>t {return RESERVADA; BEGIN edo_26;}

<edo_25>. {}

<edo_26>. {}

<edo_27>o {BEGIN edo_28;}

<edo_28>l {return RESERVADA; BEGIN edo_29;}

<edo_29>. {}

<edo_30>u {BEGIN edo_31;}

<edo_31>e {return RESERVADA; BEGIN edo_32;}

<edo_32>. {}

<edo_33>s {BEGIN edo_34;}

<edo_34>e {return RESERVADA; BEGIN edo_35;}

<edo_40>{letra}|{digito} {BEGIN edo_40;}
<edo_40>. {}

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