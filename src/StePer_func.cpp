#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../include/StePer_func.h"

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
    out += "<g transform=\"rotate\(";
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
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n<circle cx=\"";
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
    out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n<circle cx=\"";
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

  




