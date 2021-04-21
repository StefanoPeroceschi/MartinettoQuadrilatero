#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include"include/StePer_func.h"



int main(){
    std::string out =""; 
    StePer_Quadrilatero* quad = StePer_init (200., 120., 20., 19., 300., 400.);
    if ( quad == NULL ){
        printf("Errore: parametri non corretti\n\n");
    } 
    
    StePer_save(quad, "prova");
    
    free(quad);

    return 0;


}