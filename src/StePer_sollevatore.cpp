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
    if (StePer_check_scrissorlift(n_aste,l,s,d,x,y,w)){
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

/**
*   Modifica il valore di l_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_l parametro nuovo
*/
int StePer_set_l_sollevatore(StePer_Sollevatore* sol,double new_l){
    if ( ! StePer_check_sollevatore(new_l, sol->lift->quad->s,sol->lift->quad->d, sol->lift->n_quad, sol->guida->incastri->dim_x, sol->guida->pos_x, sol->guida->pos_y, sol->guida->corsa )){
        double h;
        h= 2*sqrt(new_l*new_l - pow((sol->guida->corsa)/2, 2));
        if( StePer_set_h  (sol->lift->quad, h))                         return 1;
        if( StePer_set_ya (sol->lift->quad, sol->guida->pos_y +h/2))    return 1;
        if( StePer_set_l  (sol->lift->quad, new_l))                     return 1;
        if( StePer_set_xa (sol->lift->quad, sol->guida->pos_x - (sol->guida->lunghezza)/2 + (sol->guida->corsa)/2 ))return 1;
        if( guida_set_lunghezza(sol->guida, 2*new_l + sol->guida->guida->dim_x ))                                   return 1;
        
        sol->guida->pos_x= sol->lift->quad->xa - (sol->guida->corsa)/2 +  (sol->guida->lunghezza)/2;


        return 0;
    }
    return 1;
}


/**
*   Modifica il valore di s_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_s parametro nuovo
*/
int StePer_set_s_sollevatore(StePer_Sollevatore* sol,double new_s){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, new_s,sol->lift->quad->d, sol->lift->n_quad, sol->guida->incastri->dim_x, sol->guida->pos_x, sol->guida->pos_y, sol->guida->corsa )){
        StePer_set_s(sol->lift->quad,new_s);
        return 0;
    }
    return 1;
}


/**
*   Modifica il valore di d_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_d parametro nuovo
*/
int StePer_set_d_sollevatore(StePer_Sollevatore* sol,double new_d){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,new_d, sol->lift->n_quad, sol->guida->incastri->dim_x, sol->guida->pos_x, sol->guida->pos_y, sol->guida->corsa )){
        StePer_set_d(sol->lift->quad,new_d);
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di n_aste_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_n parametro nuovo
*/
int StePer_set_n_sollevatore(StePer_Sollevatore* sol,double new_n){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,sol->lift->quad->d, new_n, sol->guida->incastri->dim_x, sol->guida->pos_x, sol->guida->pos_y, sol->guida->corsa )){
        sol->lift->n_quad = new_n;
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di x_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_x parametro nuovo
*/
int StePer_set_x_sollevatore(StePer_Sollevatore* sol,double new_x){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,sol->lift->quad->d, sol->lift->n_quad, sol->guida->incastri->dim_x, new_x, sol->guida->pos_y, sol->guida->corsa )){
        StePer_set_xa(sol->lift->quad, new_x + (sol->guida->corsa)/2 - (sol->guida->corsa)/2  );
        sol->guida->pos_x = new_x + (sol->guida->lunghezza)/2 - (sol->guida->corsa)/2 ;
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di y_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_y parametro nuovo
*/
int StePer_set_y_sollevatore(StePer_Sollevatore* sol,double new_y){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,sol->lift->quad->d, sol->lift->n_quad, sol->guida->incastri->dim_x, sol->guida->pos_x, new_y, sol->guida->corsa )){
        double h;
        h= sqrt(sol->lift->quad->l *sol->lift->quad->l - pow((sol->guida->corsa)/2, 2));
        sol->lift->quad->ya = new_y +h ;
        sol->guida->pos_y = new_y;
        return 0;
    }
    return 1;
}

/**
*   Modifica il valore di w_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_w parametro nuovo
*/
int StePer_set_w_sollevatore(StePer_Sollevatore* sol,double new_w){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,sol->lift->quad->d, sol->lift->n_quad, sol->guida->incastri->dim_x, sol->guida->pos_x, sol->guida->pos_y, new_w )){
        double h;
        h= 2*sqrt(pow(sol->lift->quad->l, 2) - pow(new_w/2, 2));
        if (StePer_set_h(sol->lift->quad, h))return 1;
        if (StePer_set_ya(sol->lift->quad, sol->guida->pos_y + h/2))return 1;
        if (StePer_set_xa(sol->lift->quad, sol->guida->pos_x -(sol->guida->lunghezza)/2 + new_w/2))return 1;
        if (guida_set_corsa(sol->guida, new_w))return 1; 
        return 0;
    }
    return 1;
}
/**
*   Modifica il valore di dim_blocchi sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_x parametro nuovo
*/
int StePer_set_dimblocchi_sollevatore(StePer_Sollevatore* sol,double new_x){
    if ( ! StePer_check_sollevatore(sol->lift->quad->l, sol->lift->quad->s,sol->lift->quad->d, sol->lift->n_quad, new_x, sol->guida->pos_x, sol->guida->pos_y, sol->guida->corsa )){
        
        if (guida_set_cerniera(sol->guida, new_x, new_x))return 1;
        if (guida_set_guida(sol->guida, new_x, new_x))return 1; 
        return 0;
    }
    return 1;
}