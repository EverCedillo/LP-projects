# include "linkedlist.h"
# include <string.h>
# include <stdio.h>

Nodo * crea_nodo ( char * val , int clase ){
Nodo * newnod =( Nodo *) malloc ( sizeof ( Nodo )) ;
int len = strlen (val );
newnod -> data . val = malloc ( len * sizeof ( char ));
strcpy ( newnod -> data .val , val) ;
newnod -> data . clase = clase ;
newnod -> next = NULL ;
return newnod ;
}
void init_list ( List * list ){
list -> root = NULL ;
list -> num = 0;
}
int insert_empty ( char * val , int clase , List * list )
{
Nodo * newnod = crea_nodo (val , clase );
list -> root = newnod ;
list -> num ++;
return list -> num -1;
}
int insert_begin ( char * val , int clase , List * list )
{
int pos = search (val , list );
if( pos != -1) {
return pos ;
}
Nodo * newtmp = crea_nodo (val , clase ) ;
Nodo * tmp = list -> root ;
if(list -> root == NULL ) {
list -> root = newtmp ;
} else {
newtmp -> next = list -> root ;
list -> root = newtmp ;
}
list -> num ++;
return list ->num -1;
}
int insert_end ( char * val , int clase , List * list )
{
int pos = search (val , list );
if( pos != -1) {
return pos ;
}
Nodo * newtmp = crea_nodo (val , clase );
Nodo * tmp = list -> root ;
if (! list -> root ) {
list -> root = newtmp ;
} else {
while (tmp -> next != NULL ){
tmp = tmp -> next ;
}
tmp -> next = newtmp ;
}
list -> num ++;
return list ->num -1;
}
int search ( char * str , List * list )
{
Nodo * tmp = list -> root ;
int pos = 0;
while (tmp ){
if( strcmp (tmp -> data .val , str ) ==0) {
return pos ;
}
tmp = tmp -> next ;
pos ++;
}
return -1;
}
void empty_list ( List * list )
{
delete_nodo (list -> root ) ;
list -> num = 0;
}
void delete_nodo ( Nodo * next )
{
if(next -> next != NULL ){
delete_nodo (next -> next ) ;
}
free ( next );
}
void print ( List * list ){
Nodo * tmp = list -> root ;
while (tmp != NULL ){
printf (" Clase : %d, valor :%s\n",tmp -> data .clase ,tmp -> data .val );
tmp = tmp -> next ;
}
}