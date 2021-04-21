#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include"include/StePer_func.h"



int main(){
    std::string out =""; 
    StePer_Quadrilatero* quad = StePer_init (200., 200., 20., 10., 400., 400.);
    if ( quad == NULL ){
        printf("Errore: parametri non corretti\n\n");
    } 
    
    out += StePer_to_svg_init(800,600);
    out += StePer_to_svg(quad);
    out += StePer_to_svg_close();
    

    std::cout << out;
    
    free(quad);

    return 0;


}