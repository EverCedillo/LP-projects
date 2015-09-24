# ifndef LINKED_LIST_H
# define LINKED_LIST_H
# ifdef __cplusplus
extern "C" {
# endif
#include <stdio.h>
struct Data {
char * val;
int clase ;
};
typedef struct Data Data ;
typedef struct Nodo Nodo ;
struct Nodo {
Data data ;
Nodo * next ;
};
struct LinkedList {
Nodo * root ;
int num ;
};
typedef struct LinkedList List ;
Nodo * crea_nodo ( char * val , int clase );
void init_list ( List * list );
int insert_empty ( char * val , int clase , List * list );
int insert_head ( char * val , int clase , List * list );
int insert_end ( char * val , int clase , List * list ) ;
int search ( char * str , List * list );
int get_data(char * str, List *list );
void fprint (FILE* file, List *list);
void empty_list ( List * list );
void delete_nodo ( Nodo * next ) ;
void print ( List * list );
# ifdef __cplusplus
}
# endif
# endif