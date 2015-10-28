#include <stdio.h>
#include <string.h>
#include "clases.h"

#define DP 0
#define SP 1
#define SIF 2
#define SWHILE 3
#define SASIG 4
#define M 5
#define H 6

int token;

void p();
void d();
void s();
void t();
void v();
void dp();
void i();
void vp();
void n();
void sp();
void sif();
void sifp();
void swhile();
void sasig();
void eat(int tok);
void h();
void hp();
void j();
void jp();
void m();
void mp();
void r();
void q();
void qp();
void o();
void avanzar();
void error();



int main(int argc , char ** argv) {
    FILE * file ;
    if( argc > 1) {
        
        file = fopen ( argv [1] , "r") ;
        if (! file ) {
            fprintf (stderr , "No se puede abrir el archivo %s \n", argv[1]);
            return(1) ;
        }
        parse_in(file);
    }
    token=yylex ();
    p();
    fclose(file);
}
void p(){
    printf("P->DS\n");
    d();
    s();
}
void d(){
    printf("D->TV;D'\n");
    t();
    v();
    eat(PYC);
    dp();
}
void dp(){
    while(isInFirst(DP,token)){
        printf("D'->TV;\n");
        t();  
        v();
        eat(PYC);
    }
    printf("D'->epsilon\n");
}
void t(){
    switch(token){
        case _INT:
            printf("T->int\n");
            avanzar();
        break;
        case _FLOAT:
            printf("T->float\n");
            avanzar();
        break;
        case _DOUBLE:
            printf("T->double\n");
            avanzar();
        break;
        case _CHAR:
            printf("T->char\n");
            avanzar();
        break;
        case _BOOL:
            printf("T->bool\n");
            avanzar();
        break;
        default:
            error();
    }
}
void v(){
    printf("V->idIV'\n");
    eat(ID);
    i();
    vp();
}
void vp(){
    while(token==ID){
        printf("V'->idI,\n");
        avanzar();
        i();
        eat(COM);
    }
    printf("V'->epsilon\n");
}

void i(){
    if(token==IGU){
        avanzar();
        switch(token){
            case ID:
                printf("I->=id\n");
                avanzar();
            break;
            case  NUM:
                printf("I->=num\n");
                avanzar();
            break;
            case CAR:
                printf("I->=caracter\n");
                avanzar();
            break;
            case _TRUE:
                printf("I->=true\n");
                avanzar();
            break;
            case _FALSE:
                printf("I->=false\n");
                avanzar();
            break;
            default:
                error();
        }
     }else
        error();
}
void s(){
    printf("S->NS'\n");
    n();
    sp();
}
void sp(){
    while(isInFirst(SP,token)){
        printf("S'->N'\n");
        n();
    }
    printf("S'->epsilon\n");
}

void n(){
    if(isInFirst(SIF,token)){
        printf("N->SIF\n");
        sif();
    }
    else if(isInFirst(SWHILE,token)){
        printf("N->SWHILE\n");
        swhile();
    }
    else if(isInFirst(SASIG,token)){
        printf("N->SASIG\n");
        sasig();
    }
    else
        error();    
}
void sif(){
    printf("SIF->if(H){S}SIF'\n");
    eat(_IF);
    eat(PAA);
    h();
    eat(PAC);
    eat(LLA);
    s();
    eat(LLC);
    sifp();
}
void sifp(){
    while(token==_ELSE){
        printf("SIF'->else{S}\n");
        avanzar();
        eat(LLA);
        s();
        eat(LLC);
    }
    printf("SIF'->epsilon\n");
}

void swhile(){
    printf("SWHILE->while(H){S}\n");
    eat(_WHILE);
    eat(PAA);
    h();
    eat(PAC);
    eat(LLA);
    s();
    eat(LLC);
}
void sasig(){
    printf("SASIG->idOM\n");
    eat(ID);
    o();
    m();
}
void o(){
    switch(token){
        case MAS_IGU:
            printf("O->+=\n");
            avanzar();
        break;
        case RES_IGU:
            printf("O->-=\n");
            avanzar();
        break;
        case MUL_IGU:
            printf("O->*=\n");
            avanzar();
        break;
        case DIV_IGU:
            printf("O->/=\n");
            avanzar();
        break;
        case MOD_IGU:
            printf("O->%%=\n");
            avanzar();
        break;
        case IGU:
            printf("O->=\n");
            avanzar();
        break;
        default:
            error();   
    } 
}

void h(){
    printf("H->JH'\n");
    j();
    hp();
}
void hp(){
    switch(token){
        case MEN:
            printf("H'-><JH'\n");
            avanzar();
            j();
            hp();
        break;
        case MEN_IGU:
            printf("H'-><=JH'\n");
            avanzar();
            j();
            hp();
        break;
        case MAY:
            printf("H'-> >JH'\n");
            avanzar();
            j();
            hp();
        break;
        case MAY_IGU:
            printf("H'-> >=JH'\n");
            j();
            hp();
        break;
        default:
            printf("H'->epsilon\n");            
    }   
}
void j(){
    printf("J->LJ'");
    m();
    jp();
}
void jp(){
    if(token==IGU_IGU){
        printf("J'->==LJ'\n");
        avanzar();
        m();
        jp();
    }else if(token==DIF){
        printf("J'->!=LJ'\n");
        avanzar();
        m();
        jp();
    }else
        printf("J'->epsilon\n");
}

void l(){
    if(isInFirst(M,token)){
        printf("L->M\n");
        m();
    }else if(isInFirst(H,token)){
        printf("L->H\n");
        h();
    }else
        error();
}
void m(){
    printf("M->QM'\n");
    q();
    mp();
}
void mp(){
    if(token==MAS){
        printf("M'->+QM'\n");
        avanzar();
        q();
        mp();
    }else if(token==RES){
        printf("M'->-QM'\n");
        avanzar();
        q();
        mp();
    }else
        printf("M'->epsilon\n");
}
void q(){
    printf("Q->RQ'\n");
    r();
    qp();
}
void qp(){
    if(token==MUL){
        printf("Q'->*RQ'\n");
        avanzar();
        r();
        qp();
    }else if(token==DIV){
        printf("Q'->/RQ'\n");
        avanzar();
        r();
        qp();
    }else if(token==MOD){
        printf("Q'->%%RQ'\n");
        avanzar();
        r();
        qp();
    }else
        printf("Q'->epsilon\n");
}
void r(){
    switch(token){
        case PAA:
            printf("R->(M)\n");
            avanzar();
            m();
            eat(PAC);
        break;
        case NUM:
            printf("R->num\n");
            avanzar();
        break;
        case CAR:
            printf("R->caracter\n");
            avanzar();
        break;
        case _TRUE:
            printf("R->true\n");
            avanzar();
        break;
        case _FALSE:
            printf("R->false\n");
            avanzar();
        break;
        default:
            error();        
    }
}

int isInFirst(int nombre,int token){
    switch(nombre){
        case DP:
            return token==_INT||token==_FLOAT||token==_DOUBLE||token==_CHAR||token==_BOOL?1:0;
        break;
        case SP:
            return token==_IF||token==_WHILE||token==ID?1:0;
        break;
        case SIF:
            return token==_IF?1:0;
        break;
        case SWHILE:
            return token==_WHILE?1:0;
        break;
        case SASIG:
            return token == ID?1:0;
        break;
    }
}
void avanzar() {
            printf("\n<%d>(%d,%d)",token,lineno,pos);
      token= yylex();
}
void eat(int tok){
      if(tok==token ){
    	token=yylex( ); 
      } 
      else{
	    error( );
      }
}
void error(){
    printf("Error\n");
}

    
