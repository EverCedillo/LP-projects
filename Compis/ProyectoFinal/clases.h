/********************************
*Cedillo Martínez Jesús Everardo
*García González Brenda
*26/10/15
*********************************/
# ifndef CLASES_H
# define CLASES_H

//Valor de los diferentes token que puede reconocer el analizador léxico
#define IF 1
#define FLOAT 2
#define DOUBLE 3
#define CHAR 4
#define BOOL 5
#define INT 6
#define ELSE 7
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
#define NUM_F 21
#define ID 22
#define WHILE 23
#define MAS_IGU 24
#define RES_IGU 25
#define MUL_IGU 26
#define DIV_IGU 27
#define MOD_IGU 28
#define PYC 29
#define COM 30
#define LLA 31
#define LLC 32
#define PAA 33
#define PAC 34
#define CAR 35
#define CAD 36
#define FOR 37
#define NUM_D 38
#define NUM_I 39
#define SWITCH 40
#define CASE 41
#define BREAK 42
#define VOID 43
#define PRINT 44
#define SCAN 45
#define STRUCT 46
#define RETURN 47
#define DO 48
#define COA 49
#define COC 50
#define DEFAULT 51
#define OR 52
#define AND 53
#define NOT 54
#define MAS_MAS 55
#define RES_RES 56
#define DPT 57
#define PT 58

/*

//Estructura para yylval, donde se almacena el valor
//y nombre de los token

typedef struct VALORES VALORES ;
struct VALORES {
    int ival;
    float fval ;
    double dval ;
    char cval;
    char * sval ;
};


// Variables globales de control de posición en archivo fuente

VALORES yylval;*/

//Apuntador de entrada para yylex() y creación de yylval


int pos;
int lineno;

# endif
