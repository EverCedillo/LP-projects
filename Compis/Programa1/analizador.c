/********************************+
Analizador léxico
Programa 1
Cedillo Martínez Jesús Everardo
García González Brenda
22-sep-2015
**********************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"



#define RESERVED_WORD 0
#define ID 1
#define SPECIAL_CHARACTER 2
#define ASSIGNMENT_OPERATOR 3
#define ARITMETIC_OPERATOR 4
#define RELATIONAL_OPERATOR 5
#define INTEGER 6
#define FLOAT 7

struct Token {
	int type ;
	char * lexema ;
	int col ;
	int line;
};


int steps [41][25]={
	{1,-1,4,2,-1,-1,-1,5,-1,3,-1,-1,6,7,-1,11,15,15,15,13,12,14,9,10,8},
	{-1,24,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,20,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,39,13,13,13,13,13,13,13,13},
	{40,40,40,40,40,40,40,40,40,40,40,40,-1,-1,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{40,40,40,40,40,40,40,40,40,40,40,40,40,-1,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	};
int chars_set[]={'i','n','t','f','l','o','a','e','s','b','r','u'};
int id=0;
List symbol_table;

void error(char*buffer, int col, int line);
int cathToken(char*buffer,int status, int col, int line,FILE*file);
int find(char c);


int main(int argc, char const *argv[]){
	/* code */
	init_list(&symbol_table);
	char *buffer,c;
	int status=0,lexic_element,pre_status,char_flag=-1,c_pos=0,c_line=1, error_flag=0;
	FILE * file =fopen(argv[1],"r");
	FILE* file_token=fopen("token.tk","w");
	buffer=(char*)malloc(sizeof(char)*2);
	
	if(file!=NULL){
		while(feof(file)==0){

			if(char_flag){
				c=fgetc(file);
				//printf("%c: c_line:%d,col:%d\n",c,c_line,c_pos);
				if(c=='\n')
					c_line++;
				c_pos++;
			}

			status=c==EOF?-1:status;
			lexic_element=find(c);
			//printf("%c,status:%d,%d-%s, char_flag:%d\n",c,status,lexic_element,buffer,char_flag);
			
			if(lexic_element!=-1)
				status=steps[status][lexic_element];
			else if(c!=EOF){
				if(!error_flag)
					error(buffer,c_pos-strlen(buffer),c_line);
				status=0;
				error_flag=char_flag=1;
				free(buffer);
				buffer=(char*)malloc(sizeof(char)*2);
			}
			if(status==-1){
				//printf("buffer:%s, pre_status: %d, status: %d, char_flag: %d\n",buffer,pre_status,status,char_flag );
				//scanf("%d",&o);
				if(cathToken(buffer,pre_status,c_pos-strlen(buffer),c_line,file_token)&&strlen(buffer)==0){
					status=pre_status=0;
					if(!error_flag)
						error(buffer,c_pos-strlen(buffer),c_line);
					error_flag=char_flag=1;
				}
				else{
					error_flag=char_flag=status=pre_status=0;				
					//printf("buffer:%s, pre_status: %d, status: %d, char_flag: %d\n",buffer,pre_status,status,char_flag );
					free(buffer);
					buffer=(char*)malloc(sizeof(char)*2);
				}
			}else{
				char tmp2 [2] = {c, '\0'};
				strcat ( buffer , tmp2 );
				pre_status=status;
				char_flag=1;
				//error_flag=0;
			}
			c_pos=c=='\n'?0:c_pos;
		}
	}
	fclose(file);
	fclose(file_token);
	printf("\n/** Tabla de Simbolos **/\n");
	print(&symbol_table);
	return 0;
}


/************************************
Función de tratamiento de error,
sólo ignora el error e imprime donde se localiza 
y continúa la ejecución del análisis

función error(char*buffer,int col, int line)
recibe:
	char*buffer, la cadena de texto que genero el error
	int col, int line, la línea y columna donde se originó el error

************************************/
void error(char*buffer,int col, int line){
	printf("Error en linea: %d col:%d\n",line,col);
}

/************************************
Función que recibe candidatos a token, y decide si
las cadenas de caracteres son token y de qué tipo
además genera la tabla de símbolos, al identiicar
token clase IDENTIFICADOR o PALABRA RESERVADA

función int cathToken(char*buffer,int status, int col, int line)
recibe:
	char*buffer, la cadena de texto candidata a token
	int status, el estado del auttómata analizador donde el token se originó
	int col, int line, la posición del archivo donde se encuentra el candidato a token

devuelve:
	0 si el candidato a token fue aceptado
	-1 de no ser aceptado el candidatoa token
************************************/
int cathToken(char*buffer,int status, int col, int line, FILE*file){
	struct Token t;
	
	t.lexema = buffer;
	t.col=col;
	t.line = line;

	switch(status){
		case 26: //int
		case 25: //if
		case 32: //true
		case 23: //float
		case 19: //false
		case 35: //else
		case 29: //bool
			t.type = RESERVED_WORD;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("PALABRA RESERVADA:%d, Tipo:%d, Col:%d, Line: %d\n",id,t.type,t.col,t.line);
			insert_begin(buffer,id++,&symbol_table);
		break;
		case 6: //ENTERO
			t.type = INTEGER;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 36: //REAL
			t.type = FLOAT;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 11: //ARITMETICO
			t.type = ARITMETIC_OPERATOR;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 12: //ESPECIALES
			t.type = SPECIAL_CHARACTER;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 40: //ID's
			t.type = ID;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("IDENTIFICADOR:%d, Tipo:%d, Col:%d, Line: %d\n",id,t.type,t.col,t.line);
			insert_begin(buffer,id++,&symbol_table);
		break;
		case 8:
			t.type = ASSIGNMENT_OPERATOR;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 9:
		case 10:
		case 37: //OP RElacionales
			t.type = RELATIONAL_OPERATOR;
			fprintf(file, "Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
			printf("Lexema:%s, Tipo:%d, Col:%d, Line: %d\n",t.lexema,t.type,t.col,t.line);
		break;
		case 15:
		case 39:
			//ITNORE
			//printf("ITNORE\n");
			break;
		case EOF:
			printf("END OF FILE\n");
			break;
		default:
			//printf("Nadiwis\n");
			return -1;
		return 0;
	}
}

/************************************
Función que recibe caracteres que forman elementos léxicos
y ayuda en la desición del siguiente paso del autómata 
verificando la posibilidad de transición 

función int find(char c)
recibe:
	char c, caracter que provocará un desplazamiento en el autómata analizador
devuelve:
	la columna donde se debe buscar el estado siguiente del autómata
	-1, si el caracter no está definidio en el lenguaje

************************************/
int find(char c){
	int i=0;
	for(i=0;i<12;i++){ //Caracteres que forman las palabras reservadas
		if(c==chars_set[i])
			return i;
	}
	if(47<=c&&57>=c)//digitos
		return i;
	if(c=='.')
		return 13;
	if((65<=c&&90>=c)||(97<=c&&122>=c)) //letras minúsculas y mayúsculas
		return 14;
	if(c==43||c==45||c==42||c==47) //aritméticos +,-,*,/
		return 15;
	if(c=='\n')
		return 16;
	if(c=='\t')
		return 17;
	if(c==' ')
		return 18;
	if(c=='#')
		return 19;
	if(c=='{'||c=='}'||c=='('||c==')')
		return 20;
	if(c=='@')
		return 21;
	if(c=='>')
		return 22;
	if(c=='<')
		return 23;
	if(c=='=')
		return 24;
	return -1;
}

