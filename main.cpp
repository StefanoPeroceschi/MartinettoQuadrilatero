#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include"include/StePer_func.h"



int main(){
     StePer_Quadrilatero* quad = new StePer_Quadrilatero;

 /*   StePer_Quadrilatero* quad = StePer_init (40.1234, 250.3453, 20.34534, 19.5464, 400.4563, 450.34543);
    if ( quad == NULL ){
        printf("Errore: parametri non corretti\n\n");
    } */
    
   // StePer_save(quad, "duo");
    quad = StePer_parse("duo");
    std::cout << quad -> h <<std::endl;
    std::cout << quad -> l <<std::endl;
    std::cout << quad -> s <<std::endl;
    std::cout << quad -> d <<std::endl;
    std::cout << quad -> xa <<std::endl;
    std::cout << quad -> ya <<std::endl << std::endl;
    StePer_set_h(quad, 300.);
    std::cout << quad -> h <<std::endl;
    std::cout << quad -> l <<std::endl;
    std::cout << quad -> s <<std::endl;
    std::cout << quad -> d <<std::endl;
    std::cout << quad -> xa <<std::endl;
    std::cout << quad -> ya <<std::endl << std::endl;
    StePer_save(quad, "duo1");  
    free(quad);

    return 0;


}