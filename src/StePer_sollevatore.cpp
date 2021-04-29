#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include "../include/StePer_func.h"
#include "../include/StePer_sollevatore.h"
#include "../include/guida.h"



/**
* Inizializzazione Sollevatore 
* 
* la funzione ritorna il puntatore al Sollevatore generato 
* se i parametri sono validi altrimenti ritorna NULL
* in ingresso chiede i seguenti parametri:
* @param l, @param s, @param d, @param n_aste  parametri relativi al meccanismo di alzata lift
* @param dim_blocchi , parametro relativo alla guida prismatica, in particolare alla dimensione dei blocchi quadrati
* @param x, @param y, @param w , parametri relativi alla posizione della macchina ed alla estensione della guida prismatica alla base
*/
StePer_Sollevatore* StePer_init_sollevatore (double l, double s, double d,  double n_aste, double dim_blocchi, double x, double y, double w){
    double xa,ya,h, l_guida;
    h   = 2* sqrt( (l*l) - ( (w/2)* (w/2) ) );
    xa  = x + w/2;
    ya  = y + h/2; 
    l_guida = 2* l + dim_blocchi ;
  
    GuidaPrismatica* guida = guida_init(x,y,l_guida, w, dim_blocchi, dim_blocchi);
    if (guida == NULL){
        return NULL;
    }

    StePer_ScrissorLift* lift = StePer_init_scrissorlift(n_aste,l,s,d,x- l_guida/2 ,y,w);
    if(lift == NULL){
        return NULL;
    }
    
    StePer_Sollevatore* sol = new StePer_Sollevatore;
    sol->guida=guida;
    sol->lift=lift;
    return sol;
}

/**
 * Deallocazione Sollevatore
 * La funzione elimina dalla memoria un elemento della struct Sollevatore passando in ingresso un puntatore ad esso
 * 
 */
void StePer_destroy_sollevatore(StePer_Sollevatore* sol){
    guida_distruggi(sol -> guida);
    StePer_destroy_scrissorlift(sol -> lift);
    free(sol);
}

/**
 * Controllo Sollevatore
 * La funzione verifica che i parametri dei due componenti di sollevatore siano compatibili 
 * ritorna 0 se sono compatibili, 1 altrimenti
 */
int StePer_check_sollevatore(double l, double s, double d,  double n_aste, double dim_blocchi, double x, double y, double w){
    if (dim_blocchi > l/2){
        return 1;
    } 
    return 0;
    
}

/**
 * Generatore stringa Sollevatore
 * La funzione genera una stringa contenente il codice svg relativo al sollevatore. Ritorna "ERRORE: puntatore nullo" se 
*   se il puntatore in ingresso è nullo, ritorna la stringa del componente altrimenti
*   @param sol puntatore a struct Sollevatore
*/
std::string StePer_to_svg_sollevatore(StePer_Sollevatore* sol){
   if( sol != NULL && sol ->guida != NULL && sol-> lift != NULL){
        std::string out = "";
        
        out += guida_to_SVGstring(sol -> guida);
        out += StePer_to_svg_scrissorlift( sol -> lift);
        
        return out;
    }
    return "\n\nERRORE: puntatore nullo\n\n";
    
}

/**
 * Stampa Sollevatore
 * La funzione genera un file svg con la rappresentazione del sollevatore. Se il puntatore è nullo ritorna 1 altrimenti ritorna 0
 * ATTENZIONE se è già presente nella cartella un file con lo stesso nome lo sovrascrive! 
 *  @param filename     nome del file su cui salvare (senza estensione)
 *  @param sol          puntatore a Sollevatore da stampare
 */
int StePer_save_sollevatore(StePer_Sollevatore* sol, std::string filename){
   if( sol != NULL && sol ->guida != NULL && sol-> lift != NULL){
        std::ofstream file;
        file.open (filename+".svg");
        file << StePer_to_svg_init();
        file << StePer_to_svg_sollevatore(sol);
        file << StePer_to_svg_close();
        file.close();
        return 0;
    }
    return 1;
    
}
  


