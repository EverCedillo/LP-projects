#include <stdio.h>
#include <string.h>
#include "clases.h"

#define DP 0
#define SP 1
#define SIF 2
#define SWHILE 3
#define SASIG 4
#define E 5
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
void j();
void m();
void l();
void r();
void q();
void o();
void avanzar();
void error();



main(int argc , char ** argv) {
    token = yylex();
    p();
}
void p(){
    d();
    s();
}
void d(){
    t();
    v();
    eat(PYC);
    dp();
}
void dp(){
    while(isInFirst(DP,token)){
        t();  
        v();
        eat(PYC);
    }
}
void t(){
    if(token==_INT||token==_FLOAT||token==_DOUBLE||token==_CHAR||token==_BOOL)
        avanzar();
    else
        error();
}
void v(){
    eat(ID);
    i();
    vp();
}
void vp(){
    while(token==ID){
        avanzar();
        i();
        eat(COM);
    }
}

void i(){
    if(token==IGU){
        avanzar();
        if(token==ID||token==NUM||token==CAR||token==_TRUE||token==_FALSE)
            avanzar();
        else
            error();
     }else
        error();
}
void s(){
    n();
    sp();
}
void sp(){
    while(isInFirst(SP,token))
        n();
}

void n(){
    if(isInFirst(SIF,token))
        sif();
    else if(isInFirst(SWHILE,token))
        swhile();
    else if(isInFirst(SASIG,token))
        sasig();
    else
        error();    
}
void sif(){
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
        avanzar(); //Todo deepende de eat()
        eat(LLA);
        s();
        eat(LLC);
    }
}

void swhile(){
    eat(_WHILE);
    eat(PAA);
    h();
    eat(PAC);
    eat(LLA);
}
void sasig(){
    eat(ID);
    o();
    m();
}

void j(){
    l();
    while(token==IGU_IGU||token==DIF){
        avanzar();
        l();
    }
}
void h(){
    j();
    while(token==MAY||token==MAY_IGU||token==MEN||token==MEN_IGU){
        avanzar();
        j();
    }
}
void l(){
    if(isInFirst(E,token))
        m();
    else if(isInFirst(H,token))
        h();
    else
        error();
}
void m(){
    q();
    while(token==MAS||token==RES){
        avanzar();
        q();
    }
}
void q(){
    r();
    while(token==MUL||token==DIV||token==MOD){
        avanzar();
        r();
    }
}
void r(){
    switch(token){
        case PAA:
            avanzar();
            m();
            eat(PAC);
        break;
        case NUM:
        case CAR:
        case _TRUE:
        case _FALSE:
            avanzar();
        break;
        default:
            error();        
    }
}
void o(){
    if(token==MAS_IGU||token==RES_IGU||token==MUL_IGU||token==DIV_IGU||token==MOD_IGU||token==IGU)
        avanzar();
    else
        error();
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
        case E:
            return 1;
        break;
        case H:
            return 1;
        break;
    }
}
void avanzar() {
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

    
