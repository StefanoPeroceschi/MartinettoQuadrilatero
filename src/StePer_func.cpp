#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include "../include/StePer_func.h"



/**
* Verifica parametri 
* la funzione ritorna 0 se i parametri sono validi altrimenti ritorna 1 
*/
int StePer_check (double h, double l, double s, double d, double xa, double ya){
    
    //Check valori negativi
    if(h<=0||l<=0||s<=0||d<=0||xa<0){
        return 1;
    }

    //Check valori di h
    if(h < 1.2*s || h > (2*l)-s ){
        return 1;
    }

    //Check valori di d
    if(d > s ){
        return 1;
    }

    //Check valori di s
    if(s > l / 3 ){
        return 1;
    }

    //Check valori di l
    if(l < 3*s || l < 3*d){
        return 1;
    }
    
    //Check valori di xa,ya
    if(xa > SVG_X || ya > SVG_Y + h/2 ||ya-h< -h/2){
        return 1;
    }
    
    
    return 0;
}



/**
* Inizializzazione Quadrilatero 
* 
* la funzione ritorna il puntatore al quadrilatero generato 
* se i parametri sono validi altrimenti ritorna NULL
*/
StePer_Quadrilatero* StePer_init (double h, double l, double s, double d, double xa, double ya){
    if( ! StePer_check ( h,  l,  s,  d,  xa,  ya)){
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
*/
std::string StePer_to_svg_init (){
        std::string out = "";
        out += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"";
        out += std::to_string(SVG_X) ;
        out +=  "\" height=\"";
        out += std::to_string(SVG_Y) ;
        out += "\">";
        return out;        
    
  
    
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
* la funzione richiede un puntatore a quadrilatero in ingresso ed il flag per stampare le misure e ritorna la stringa con il testo relativo al componente svg, 
* non comprende l'inizializzazione del file svg
*/
std::string StePer_to_svg (StePer_Quadrilatero* quad, bool with_measures, char sl){
    std::string out = "";
    out += "\n\n<g transform=\"rotate\(";
    out += std::to_string(quad -> theta);
    out += ", ";
    out += std::to_string(quad -> xb);
    out += ", ";
    out += std::to_string(quad -> yb);
    out += ")\">\n";
    if ( sl != 'u'){
        out += "\t<rect  x=\"";
        out += std::to_string(quad -> xb); 
        out += "\" y=\"";
        out += std::to_string(quad -> yb - ( (quad -> s)/2 ) );
        out += "\" width=\"";
        out += std::to_string(quad-> l);
        out += "\" height=\"";
        out += std::to_string(quad->s);
        out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n";
    }
    if(with_measures){
        out += "\t<rect  x=\"";
        out += std::to_string(quad->xa);
        out += "\" y=\"";
        out += std::to_string(quad->yb -(quad->s)/2 -OFFSET);
        out += "\" width=\"";
        out += std::to_string(quad->l);
        out += "\" height=\"";
        out += std::to_string(THICKNESS);
        out += "\" style=\"fill:rgb(0,0,0);\" />\n\t<rect  x=\"";
        out += std::to_string(quad->xa + quad->l + OFFSET);
        out += "\" y=\"";
        out += std::to_string(quad->yb - (quad->s)/2);
        out += "\" width=\"";
        out += std::to_string(THICKNESS);
        out += "\" height=\"";
        out += std::to_string(quad->s);
        out += "\" style=\"fill:rgb(0,0,0);\" />\n\t<text x=\"";
        out += std::to_string(quad->xa + (quad->l)/2);
        out += "\" y=\"";
        out += std::to_string(quad->yb -(quad->s)/2 -OFFSET-2);
        out += "\" fill=\"black\">";
        out += std::to_string((int)(quad->l));
        out += "</text>\n\t<text x=\"";
        out += std::to_string(quad->xa + quad->l + OFFSET+2);
        out += "\" y=\"";
        out += std::to_string(quad->yb);
        out += "\" fill=\"black\">";
        out += std::to_string((int)(quad->s));
        out += "</text>\n";
    }

    out += "</g>\n\n<g transform=\"rotate\(";
    out += std::to_string(-(quad -> theta));
    out += ", ";
    out += std::to_string(quad -> xb);
    out += ", ";
    out += std::to_string(quad -> yb);    
    out += ")\">\n";
    if ( sl != 'u'){
        out += "\t<rect  x=\"";
        out += std::to_string( (quad -> xb) - (quad -> l)); 
        out += "\" y=\"";
        out += std::to_string(quad -> yb - ( (quad -> s)/2 ) );
        out += "\" width=\"";
        out += std::to_string(quad-> l);
        out += "\" height=\"";
        out += std::to_string(quad-> s);
        out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n";
    }
    out += "</g>\n\n<g transform=\"rotate\(";
    out += std::to_string(-(quad -> theta));
    out += ", ";
    out += std::to_string(quad -> xa);
    out += ", ";
    out += std::to_string(quad -> ya);
    out += ")\">\n";
    if ( sl != 'l'){
        out += "\t<rect  x=\"";
        out += std::to_string(quad -> xa);
        out += "\" y=\"";
        out += std::to_string( (quad -> ya) - ( (quad -> s) / 2) );
        out += "\" width=\"";
        out += std::to_string(quad -> l);
        out += "\" height=\"";
        out += std::to_string(quad -> s);
        out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n";
    }
    out += "\t<circle cx=\"";
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
    out += ")\">\n";
    if ( sl != 'l'){
        out += "\t<rect  x=\"";
        out += std::to_string( (quad -> xa) - (quad -> l) );
        out += "\" y=\"";
        out += std::to_string( (quad -> ya) - ( (quad -> s) / 2) );
        out += "\" width=\"";
        out += std::to_string(quad -> l);
        out += "\" height=\"";
        out += std::to_string(quad -> s);
        out += "\" style=\"fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)\" />\n";
    }
    out += "\t<circle cx=\"";
    out += std::to_string( (quad -> xa) - (quad -> l) );
    out += "\" cy=\"";
    out += std::to_string(quad -> ya);
    out += "\" r=\"";
    out += std::to_string( (quad -> d) / 2 );
    out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n</g>\n\n";
    if(sl != 'l'){
        out += "<circle cx=\"";
        out += std::to_string(quad -> xa);
        out += "\" cy=\"";
        out += std::to_string(quad -> ya);
        out += "\" r=\"";
        out += std::to_string( (quad -> d) / 2 );
        out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n";
    }
    if(sl != 'u'){
        out += "<circle cx=\"";
        out += std::to_string(quad -> xb);
        out += "\" cy=\"";
        out += std::to_string(quad -> yb);
        out += "\" r=\"";
        out += std::to_string( (quad -> d) / 2 );
        out += "\" stroke=\"black\" stroke-width=\"1\" fill=\"lightgrey\" />\n\n";
    }
   

    if(with_measures){
        out += "<rect  x=\"";
        out += std::to_string(quad->xa -(quad->l * cos(quad->theta * 2* PI /360))- (quad-> s)/2 - OFFSET);
        out += "\" y=\"";
        out += std::to_string(quad->yb);
        out += "\" width=\"";
        out += std::to_string(THICKNESS);
        out += "\" height=\"";
        out += std::to_string(quad->h);
        out += "\" style=\"fill:rgb(0,0,0);\" />\n<text x=\"";
        out += std::to_string(quad->xa -(quad->l * cos(quad->theta * 2* PI /360))- (quad-> s)/2 - OFFSET-22);
        out += "\" y=\"";
        out += std::to_string(quad->yb + (quad->h)/2);
        out += "\" fill=\"black\">";
        out += std::to_string((int)(quad->h));
        out += "</text>\n\n<rect  x=\"";
        out += std::to_string(quad->xa - (quad->d)/2);
        out += "\" y=\"";
        out += std::to_string(quad->ya + (quad->s)/2 + OFFSET);
        out += "\" width=\"";
        out += std::to_string(quad->d);
        out += "\" height=\"";
        out += std::to_string(THICKNESS);
        out += "\" style=\"fill:rgb(0,0,0);\" />\n<text  x=\"";
        out += std::to_string(quad->xa - 8);
        out += "\" y=\"";
        out += std::to_string(quad->ya + (quad->s)/2 + OFFSET+ 12);
        out += "\" fill=\"black\">";
        out += std::to_string((int)(quad->d));
        out += "</text>\n\n\n";
    }
    return out;    
}

  
/**
*   Modifica il valore di h      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_h(StePer_Quadrilatero* quad,double new_h){
    if ( ! StePer_check (new_h, quad -> l, quad -> s, quad -> d, quad -> xa, quad -> ya)){
        quad -> h = new_h;
        quad -> yb = quad -> ya - quad -> h;
        quad -> theta = asin ( (quad -> h) / (2* quad -> l) ) * 180 /PI;
     
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di s      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_s(StePer_Quadrilatero* quad,double new_s){
    if ( ! StePer_check (quad -> h, quad -> l, new_s, quad -> d, quad -> xa, quad -> ya)){
        quad -> s = new_s;
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di l      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_l(StePer_Quadrilatero* quad,double new_l){
    if ( ! StePer_check (quad -> h, new_l, quad -> s, quad -> d, quad -> xa, quad -> ya)){
        quad -> l = new_l;
        quad -> theta = asin ((quad -> h)/(2*quad ->l)) * 180 / PI;

        return 0;
    }
    return 1;
}
/**
*   Modifica il valore di d      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_d(StePer_Quadrilatero* quad,double new_d){
    if ( ! StePer_check (quad -> h, quad -> l, quad -> s, new_d, quad -> xa, quad -> ya)){
        quad -> d = new_d;
        return 0;
    }
    return 1;
}
/**
*   Modifica il valore di xa      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_xa(StePer_Quadrilatero* quad,double new_xa){
    if ( ! StePer_check (quad -> h, quad -> l, quad -> s, quad -> d, new_xa, quad -> ya)){
        quad -> xa = new_xa;
        quad -> xb = quad -> xa;
       
        return 0;
    }
    return 1;
}
/**
*   Modifica il valore di ya      
*   se il nuovo valore ?? incompatibile ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*/
int StePer_set_ya(StePer_Quadrilatero* quad,double new_ya){
    if ( ! StePer_check (quad -> h, quad -> l, quad -> s, quad -> d, quad -> xa, new_ya)){
        quad -> ya = new_ya;
        quad -> yb = quad -> ya - quad -> h;
        
        return 0;
    }
    return 1;
}


/**
*   Salva su file      
*   la funzione salva il file svg chiedendo un puntatore a Quadrilatero in ingresso, il nome del file su cui salvare ed il flag per salvare le misure
*   se il puntatore ?? nullo non viene generato alcun file e ritorna 1 , altrimenti ritorna 0
*/
int StePer_save(StePer_Quadrilatero* quad,std::string filename, bool with_measures){
    if( quad != NULL){
        std::ofstream file;
        file.open (filename+".svg");
        file << StePer_to_svg_init();
        file << StePer_to_svg( quad, with_measures);
        file << StePer_to_svg_close();
        file.close();
        return 0;
    }
    return 1;
}

/**
*   Carica da file    
*   la funzione carica il file svg (il cui nome ?? passato all'ingresso) restituendo
*   il puntatore al quadrilatero generato se i parametri sono corretti altrimenti ritorna NULL
*/
 StePer_Quadrilatero* StePer_load_from_file(std::string	filename){
    double h, s, l, d, xa, ya, yb;
    std::string line = "";
    int line_index = 0;
    bool with_measures;

    std::ifstream f ( filename + ".svg");

	if( !f.good() ){
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
            else if (line_index == 5){
                line[0]=='<'? with_measures=false : with_measures=true;
               
            }
            else if (line_index == 11 && with_measures==false){
            
                line = line.substr( line.find(",") + 2 );
                line = line.substr( line.find(",") + 2 );
                ya = stod( line);
               
            }
            else if (line_index == 13 && with_measures==false){
            
                line = line.substr( line.find("r=\"") + 3 );
                d = stod( line) * 2;
               
            }
            else if (line_index == 15 && with_measures==true){
            
                line = line.substr( line.find(",") + 2 );
                line = line.substr( line.find(",") + 2 );
                ya = stod( line);
               
            }
            else if (line_index == 17 && with_measures==true){
            
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

/**
*   Generatore stringa svg di scrissor lift      
*   la funzione genera la stringa relativa al componente Scrissorlift in formato svg, ritorna "ERRORE: puntatore nullo" se 
*   se il puntatore in ingresso ?? nullo o se lo ?? il suo elemento quad, ritorna la stringa del componente altrimenti
*   @param lift puntatore a struct Scrissorlift
*/
std::string StePer_to_svg_scrissorlift(StePer_ScrissorLift* lift){
    if( lift != NULL && lift->quad != NULL){
    
        std::string out = "";
        
        for(int i = lift->n_quad; i>=0; i--){
            
            StePer_Quadrilatero* local;
            local= StePer_init(lift->quad->h,lift->quad->l,lift->quad->s,lift->quad->d,lift->quad->xa, lift->quad->ya- (lift->quad->h)*i);
           
            if(i ==lift->n_quad){
                out += StePer_to_svg( local, false, 'u');
            }
            else if(i==0){
               out += StePer_to_svg( local, false, 'l');
            }
            else{
                out += StePer_to_svg( local, false);
            };
            
        }
       
        
        return out;
    }
    return "\n\nERRORE: puntatore nullo\n\n";
}

/**
*   Salva su file scrissor lift      
*   la funzione salva il file svg del meccanismo chiedendo un puntatore a ScrissorLift ed il nome del file su cui salvare
*   se il puntatore ?? nullo o il puntatore a quadrilatero contenuto ?? nullo non viene generato alcun file e ritorna 1 , altrimenti ritorna 0
*/
int StePer_save_scrissorlift(StePer_ScrissorLift* lift,std::string filename){
    if( lift != NULL && lift->quad != NULL){
    
        std::ofstream file;
        file.open (filename+".svg");
        file << StePer_to_svg_init();
        file << StePer_to_svg_scrissorlift( lift);
        file << StePer_to_svg_close();
        file.close();
        return 0;
    }
    return 1;
}

/**
*   Verifica ScrissorLift      
*   verifica che tutti i quadrilateri all'interno di scrissorlift siano validi  
*   se le misure del quadrilatrero alla base non sono valide ritorna 1, se il meccanismo esce dal file
*   ritorna -1 altrimenti ritorna 0
*/
int StePer_check_scrissorlift(int n_seg, double l, double s, double d, double x, double y, double w){
    
    double xa,ya,h;

    h   = 2* sqrt( (l*l) - ( (w/2)* (w/2) ) );
    xa  = x + w/2;
    ya  = y + h/2; 
    
    if( StePer_check(h,l,s,d,SVG_X/2,SVG_Y/2) ){
        return 1;
    }
    for(int i = n_seg; i>=0; i--){
            if( StePer_check (h,l,s,d,xa, ya-i*h ) ){
                return -1;
            }
    }
    return 0;
}

/**
*   Inizializzazione scrissor lift      
*   la funzione inizializza il meccanismo scrissorlift passando i parametri:
*   n_seg   = numero di segmenti pantografo
*   l       = lunghezza aste pantografo
*   s       = spessore aste pantografo
*   d       = diametro perni pantografo
*   x       = posizione x della prima coppia rotoidale in basso a sinistra
*   y       = posizione y della prima coppia rotoidale in basso a sinistra
*   w       = distanza tra le due coppie rotoidali alla base
*   ritorna il puntatore a ScrissorLift se i parametri sono corretti altrimenti ritorna NULL
*/
StePer_ScrissorLift* StePer_init_scrissorlift(int n_seg, double l, double s, double d, double x, double y, double w){
    
    double xa,ya,h;

    h   = 2* sqrt( (l*l) - ( (w/2)* (w/2) ) );
    xa  = x + w/2;
    ya  = y + h/2; 
    
    if( !(StePer_check_scrissorlift(n_seg,l,s,d,x,y,w))  ){

        StePer_Quadrilatero* quad = StePer_init(h, l, s, d, xa, ya);
        StePer_ScrissorLift* lift = new StePer_ScrissorLift;
        lift -> n_quad = n_seg;
        lift -> quad = quad;
        
        return lift;
    }
    return NULL;
};

/**
*   Eliminazione scrissor lift      
*   la funzione dealloca la strutture ScrissorLift chiedendo un puntatore a struttura in ingresso
*   se il puntatore ?? nullo non fa niente 
*/
void StePer_destroy_scrissorlift(StePer_ScrissorLift* lift){

    if( lift != NULL){
        if(lift->quad!=NULL){
            free(lift -> quad);
        }
        free (lift);

    }
    
};

