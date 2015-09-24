#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct Token {
	int clase ;
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
void error(char*buffer, int pos, int line);
int cathToken(char*buffer,int status, int col, int line);
int find(char c);


int main(int argc, char const *argv[]){
	/* code */
	char *buffer,c;
	int status=0,lexic_element,pre_status,char_flag=-1,c_pos=0,c_line=1, error_flag=0;
	FILE * file;
	file =fopen(argv[1],"r");
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
			
			if(lexic_element!=-1){
				status=steps[status][lexic_element];
				}
			else if(c!=EOF){
				if(!error_flag)
				error(buffer,c_pos-strlen(buffer),c_line);
				pre_status=status=0;
				error_flag=char_flag=1;
				free(buffer);
					buffer=(char*)malloc(sizeof(char)*2);
			}
			if(status==-1){
				//printf("buffer:%s, pre_status: %d, status: %d, char_flag: %d\n",buffer,pre_status,status,char_flag );
				//scanf("%d",&o);
				if(cathToken(buffer,pre_status,c_pos-strlen(buffer),c_line)&&strlen(buffer)==0){
					status=pre_status=0;
					if(!error_flag)
						error(buffer,c_pos-strlen(buffer),c_line);
					error_flag=char_flag=1;
				}
				else{
					error=flag=char_flag=status=pre_status=0;				
					//printf("buffer:%s, pre_status: %d, status: %d, char_flag: %d\n",buffer,pre_status,status,char_flag );
					free(buffer);
					buffer=(char*)malloc(sizeof(char)*2);
				}
			}else{
				char tmp2 [2] = {c, '\0'};
				strcat ( buffer , tmp2 );
				pre_status=status;
				char_flag=1;
				error_flag=0;
			}
			c_pos=c=='\n'?0:c_pos;
		}
	}

	return 0;
}
int lex(int state){

}
void error(int pos, int line){
	printf("Error en col: %d linea:%d\n",buffer,pos, line);
}
int cathToken(char*buffer,int status, int pos, int line){
	struct Token t;
	switch(status){
		case 26: //int
		case 25: //if
		case 32: //true
		case 23: //float
		case 19: //false
		case 35: //else
		case 27: //bool
			printf("(%d,%d) %s: Palabra reservadeishon",pos,line,buffer);
		break;
		case 6: //ENTERO
			printf("(%d,%d) %s: ENTERO\n",pos,line,buffer);
		break;
		case 36: //REAL
			printf("(%d,%d) %s: REAL\n",pos,line,buffer);
		break;
		case 11: //ARITMETICO
			printf("(%d,%d) %s: ARITMETICO\n",pos,line,buffer);
		break;
		case 12: //ESPECIALES
			printf("(%d,%d) %s: SEPARADORES\n",pos,line,buffer);
		break;
		case 40: //ID's
			printf("(%d,%d) %s: IDENTIFICADOR\n",pos,line,buffer);
			break;
		case 8:
		case 9:
		case 10:
		case 37: //OP RElacionales
			printf("(%d,%d) %s: RELACIONALES\n",pos,line,buffer);
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

