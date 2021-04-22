#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include"include/StePer_func.h"


int main(){
     StePer_Quadrilatero* quad = new StePer_Quadrilatero ;

     quad = StePer_init (40., 250., 20., 19., 400., 400.);/*
    if ( quad == NULL ){
        printf("Errore: parametri non corretti\n\n");
    } 
    
    StePer_save(quad, "template");*/
   // quad = StePer_parse("template");
    std::cout << quad -> h <<std::endl;
    std::cout << quad -> l <<std::endl;
    std::cout << quad -> s <<std::endl;
    std::cout << quad -> d <<std::endl;
    std::cout << quad -> xa <<std::endl;
    std::cout << quad -> ya <<std::endl << std::endl;

    StePer_set_l(quad, 100.);

    std::cout << quad -> h <<std::endl;
    std::cout << quad -> l <<std::endl;
    std::cout << quad -> s <<std::endl;
    std::cout << quad -> d <<std::endl;
    std::cout << quad -> xa <<std::endl;
    std::cout << quad -> ya <<std::endl << std::endl;

    StePer_save(quad, "template_modificato"); 

    free(quad);

    return 0;


}