# ifndef VALOR_H
# define VALOR_H
/* Aqui van los defines para las clases lexicas */
# define ID 1
# define REAL 2
# define ENTERO 3
# define DOUBLE 4
/* Se define una union para guardar todos los valores de los tokens */
typedef union VALORES VALORES ;
union VALORES {
char * sval ;
int ival ;
float fval ;
double dval ;
};
/* Se declara la variable yylval de tipo VALORES */
VALORES yylval ;
# endif
