#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include "../include/StePer_func.h"

/**
* Verifica parametri 
* la funzione ritorna 1 se i parametri sono validi altrimenti ritorna 0 
*/
int StePer_check (double h, double l, double s, double d, double xa, double ya){
    
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
    if(xa > 700 || ya > 590 ){
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
    if(StePer_check ( h,  l,  s,  d,  xa,  ya)){
        StePer_Quadrilatero* quad = new StePer_Quadrilatero;
        quad->h = h;
        quad->l = l;
        quad->s = s;
        quad->d = d;
        quad->xa = xa;
        quad->ya = ya;

        quad->xb = xa;
        quad->yb = ya - h;
        quad->theta = asin (h/(2*l)) * 180 / PI;

        return quad;

    }
    return NULL;


}

/**
* Generazione stringa svg di inizializzazione
* 
* la funzione ritorna la stringa con il testo relativo all'inizializzazione del file svg, 
* in ingresso chiede le dimensioni del file : x y
* ritorna la stringa se i parametri sono corretti, NULL altrimenti
*/
std::string StePer_to_svg_init (int x, int y){
    if(x > 10 || y > 10 || x < 10000 || y< 10000){
        std::string out = "";
        out += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"";
        out += std::to_string(x) ;
        out +=  "\" height=\"";
        out += std::to_string(y) ;
        out += "\">";
        return out;        
    }
  
    return NULL;
}

/**
* Generazione stringa svg di chiusura
* 
* la funzione ritorna la stringa con il testo di chiusura del file svg
*/
std::string StePer_to_svg_close (){ 
    return "\n</svg>\n";
}


/**
* Generazione stringa svg
* 
* la funzione ritorna la stringa con il testo relativo al componente svg, 
* non comprende inizializzazione file svg
*/
std::string StePer_to_svg (StePer_Quadrilatero* quad){
    std::string out = "";
    out += "\n\n<g transform=\"rotate\(";
    out += std::to_string(quad -> theta);
    out += ", ";
    out += std::to_string(quad -> xb);
    out += ", ";
    out += std::to_string(quad -> yb);
    out += ")\">\n\t<rect  x=\"";
    out += std::to_string(quad -> xb); 
    out += "\" y=\"";
    out += std::to_string(quad -> yb - ( (quad -> s)/2 ) );
    out += "\" width=\"";
    out += std::to_string(quad-> l);
    out += "\" height=\"";
    out += std::to_string(quad->s);
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n</g>\n\n<g transform=\"rotate\(";
    out += std::to_string(-(quad -> theta));
    out += ", ";
    out += std::to_string(quad -> xb);
    out += ", ";
    out += std::to_string(quad -> yb);    
    out += ")\">\n\t<rect  x=\"";
    out += std::to_string( (quad -> xb) - (quad -> l)); 
    out += "\" y=\"";
    out += std::to_string(quad -> yb - ( (quad -> s)/2 ) );
    out += "\" width=\"";
    out += std::to_string(quad-> l);
    out += "\" height=\"";
    out += std::to_string(quad-> s);
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n</g>\n\n<g transform=\"rotate\(";
    out += std::to_string(-(quad -> theta));
    out += ", ";
    out += std::to_string(quad -> xa);
    out += ", ";
    out += std::to_string(quad -> ya);
    out += ")\">\n\t<rect  x=\"";
    out += std::to_string(quad -> xa);
    out += "\" y=\"";
    out += std::to_string( (quad -> ya) - ( (quad -> s) / 2) );
    out += "\" width=\"";
    out += std::to_string(quad -> l);
    out += "\" height=\"";
    out += std::to_string(quad -> s);
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n\t<circle cx=\"";
    out += std::to_string( (quad -> xa) + (quad -> l) );
    out += "\" cy=\"";
    out += std::to_string(quad -> ya);
    out += "\" r=\"";
    out += std::to_string( (quad -> d) / 2 );
    out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n</g>\n\n<g transform=\"rotate(";
    out += std::to_string(quad -> theta);
    out += ", ";
    out += std::to_string(quad -> xa);
    out += ", ";
    out += std::to_string(quad -> ya);
    out += ")\">\n\t<rect  x=\"";
    out += std::to_string( (quad -> xa) - (quad -> l) );
    out += "\" y=\"";
    out += std::to_string( (quad -> ya) - ( (quad -> s) / 2) );
    out += "\" width=\"";
    out += std::to_string(quad -> l);
    out += "\" height=\"";
    out += std::to_string(quad -> s);
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n\t<circle cx=\"";
    out += std::to_string( (quad -> xa) - (quad -> l) );
    out += "\" cy=\"";
    out += std::to_string(quad -> ya);
    out += "\" r=\"";
    out += std::to_string( (quad -> d) / 2 );
    out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n</g>\n\n<circle cx=\"";
    out += std::to_string(quad -> xa);
    out += "\" cy=\"";
    out += std::to_string(quad -> ya);
    out += "\" r=\"";
    out += std::to_string( (quad -> d) / 2 );
    out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n<circle cx=\"";
    out += std::to_string(quad -> xb);
    out += "\" cy=\"";
    out += std::to_string(quad -> yb);
    out += "\" r=\"";
    out += std::to_string( (quad -> d) / 2 );
    out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n\n\n";


    return out;    
}

  
/**
*   Modifica il valore di h      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_h(StePer_Quadrilatero* quad,double new_h){
    if (StePer_check (new_h, quad -> l, quad -> s, quad -> d, quad -> xa, quad -> ya)){
        quad -> h = new_h;
        quad -> yb = quad -> ya - quad -> h;
        quad -> theta = asin ( (quad -> h) / (2* quad -> l) ) * 180 /PI;
     
        return 1;
    }
    else{
        printf("StePer_set_h: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}

/**
*   Modifica il valore di s      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_s(StePer_Quadrilatero* quad,double new_s){
    if (StePer_check (quad -> h, quad -> l, new_s, quad -> d, quad -> xa, quad -> ya)){
        quad -> s = new_s;
        return 1;
    }
    else{
        printf("StePer_set_s: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}

/**
*   Modifica il valore di l      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_l(StePer_Quadrilatero* quad,double new_l){
    if (StePer_check (quad -> h, new_l, quad -> s, quad -> d, quad -> xa, quad -> ya)){
        quad -> l = new_l;
        quad -> theta = asin ((quad -> h)/(2*quad ->l)) * 180 / PI;

        return 1;
    }
    else{
        printf("StePer_set_l: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}
/**
*   Modifica il valore di d      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_d(StePer_Quadrilatero* quad,double new_d){
    if (StePer_check (quad -> h, quad -> l, quad -> s, new_d, quad -> xa, quad -> ya)){
        quad -> d = new_d;
        return 1;
    }
    else{
        printf("StePer_set_d: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}
/**
*   Modifica il valore di xa      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_xa(StePer_Quadrilatero* quad,double new_xa){
    if (StePer_check (quad -> h, quad -> l, quad -> s, quad -> d, new_xa, quad -> ya)){
        quad -> xa = new_xa;
        quad -> xb = quad -> xa;
       
        return 1;
    }
    else{
        printf("StePer_set_xa: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}
/**
*   Modifica il valore di ya      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_ya(StePer_Quadrilatero* quad,double new_ya){
    if (StePer_check (quad -> h, quad -> l, quad -> s, quad -> d, quad -> xa, new_ya)){
        quad -> ya = new_ya;
        quad -> yb = quad -> ya - quad -> h;
        
        return 1;
    }
    else{
        printf("StePer_set_ya: Errore, nuovo parametro non valido\n\n");
    }
    return 0;
}


/**
*   Salva su file      
*   la funzione salva il file svg chiedendo un puntatore a Quadrilatero in ingresso ed il nome del file su cui salvare
*/
void StePer_save(StePer_Quadrilatero* quad,std::string filename){
    if( quad != NULL){
        std::ofstream file;
        file.open (filename+".svg");
        file << StePer_to_svg_init(800,600);
        file << StePer_to_svg( quad );
        std::cout<<std::endl<<StePer_to_svg( quad )<<std::endl<<std::endl;
        file << StePer_to_svg_close();
        file.close();
    }
    else{
       printf("StePer_save: Errore, puntatore a Quadrilatero pari a NULL\n\n");
    }
}

/**
*   Carica da file    
*   la funzione carica il file svg (il cui nome è passato all'ingresso) restituendo
*   il puntatore al quadrilatero generato se i parametri sono corretti altrimenti ritorna NULL
*/
 StePer_Quadrilatero* StePer_parse(std::string	filename){
    double h, s, l, d, xa, ya, yb;
    std::string line = "";
    int line_index = 0;

    std::ifstream f ( filename + ".svg");

	if( !f.good() ){
		printf("StePer_parse: File non leggibile o non esistente\n");
		return NULL;
	}

	if( f.is_open() ){

		while(getline(f, line)){
            if (line_index == 3){
            
                line = line.substr( line.find(",") + 2 );
                xa = stod( line);

                line = line.substr( line.find(",") + 2 );
                yb = stod( line);
            }
            else if (line_index == 4){
            
                line = line.substr( line.find("width=\"") + 7 );
                l = stod( line);

                line = line.substr( line.find("height") + 8 );
                s = stod( line);
               
            }
            else if (line_index == 11){
            
                line = line.substr( line.find(",") + 2 );
                line = line.substr( line.find(",") + 2 );
                ya = stod( line);
               
            }
            else if (line_index == 13){
            
                line = line.substr( line.find("r=\"") + 3 );
                d = stod( line) * 2;
               
            }
            line_index ++;
        }
    
        h = ya - yb; 

        return StePer_init ( h, l, s, d, xa, ya);
    }

    f.close();
}
