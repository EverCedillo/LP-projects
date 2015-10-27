# ifndef VALOR_H
# define VALOR_H

#define _IF 1
#define _FLOAT 2
#define _DOUBLE 3
#define _CHAR 4
#define _BOOL 5
#define _INT 6
#define _ELSE 7
#define _TRUE 8
#define _FALSE 9
#define MAS 10
#define RES 11
#define MUL 12
#define MOD 13
#define DIV 14
#define IGU_IGU 15
#define DIF 16
#define MAY_IGU 16
#define MEN_IGU 17
#define MEN 18
#define MAY 19
#define IGU 20
#define NUM 21
#define ID 22
#define _WHILE 23
#define MAS_IGU 24
#define RES_IGU 25
#define MUL_IGU 26
#define DIV_IGU 27
#define MOD_IGU 28



typedef union VALORES VALORES ;
union VALORES {
 char * sval ;
 int ival ;
 float fval ;
 double dval ;
};

VALORES yylval ;

# endif
