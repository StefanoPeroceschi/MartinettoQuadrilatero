#include "../include/StePer_func.h"
#include <cstdlib>


/**
* Verifica parametri 
* la funzione ritorna 1 se i parametri sono validi altrimenti ritorna 0 
*/
int StePer_Check (double h, double l, double s, double d, double xa, double ya){
    
    //Check valori negativi
    if(h<=0||l<=0||s<=0||d<=0||xa<0||ya<0){
        return 0;
    }

    //Check valori di h
    if(h < 1.5*s || h < 1.5*d || h > 2*l-s ){
        return 0;
    }

    //Check valori di d
    if(d > s ){
        return 0;
    }

    //Check valori di l
    if(l < 3*s || l < 3*d){
        return 0;
    }
    
    //Check valori di xa,ya
    if(xa > 700 || ya > 590){
        return 0;
    }

    
    return 1;
}



/**
* Inizializzazione Quadrilatero 
* 
* la funzione ritorna il puntatore al quadrilatero generato 
* se i parametri sono validi altrimenti ritorna NULL
*/
StePer_Quadrilatero* StePer_init (double h, double l, double s, double d, double xa, double ya){
    if(StePer_Check ( h,  l,  s,  d,  xa,  ya)){
        StePer_Quadrilatero* quad = new StePer_Quadrilatero;
        quad->h = h;
        quad->l = l;
        quad->s = s;
        quad->d = d;
        quad->xa = xa;
        quad->ya = ya;
        return quad;

    }
    return NULL;


}






