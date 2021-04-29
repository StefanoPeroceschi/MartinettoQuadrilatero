#ifndef STEPER_MACCHINA_H
#define STEPER_MACCHINA_H

#define SVG_X 800
#define SVG_Y 600
#define OFFSET 20
#define THICKNESS 0.8

#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include "guida.h"



#define PI 3.14159265


/**
* Struttura Sollevatore
* contiene un puntatore a Scrissorlift ed uno a GuidaPrismatica 
*  
*/
struct StePer_Sollevatore{
   StePer_ScrissorLift* lift;
   GuidaPrismatica* guida;
};

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
StePer_Sollevatore* StePer_init_sollevatore (
    double l,
    double s,
    double d,
    double n_aste,
    double dim_blocchi,
    double x,
    double y,
    double w
    
    );
/**
 * Deallocazione Sollevatore
 * La funzione elimina dalla memoria un elemento della struct Sollevatore passando in ingresso un puntatore ad esso
 * 
 */
void StePer_destroy_sollevatore(

    StePer_Sollevatore* sol

    );


/**
 * Controllo Sollevatore
 * La funzione verifica che i parametri dei due componenti di sollevatore siano compatibili 
 * ritorna 0 se sono compatibili, 1 altrimenti
 */
int StePer_check_sollevatore(

    double l,
    double s,
    double d,
    double n_aste,
    double dim_blocchi,
    double x,
    double y,
    double w
    
    );

    /**
 * Generatore stringa Sollevatore
 * La funzione genera una stringa contenente il codice svg relativo al sollevatore. Ritorna "ERRORE: puntatore nullo" se 
*   se il puntatore in ingresso è nullo, ritorna la stringa del componente altrimenti
*   @param sol puntatore a struct Sollevatore
*/
std::string StePer_to_svg_sollevatore(StePer_Sollevatore* sol);

/**
 * Stampa Sollevatore
 * La funzione genera un file svg con la rappresentazione del sollevatore. Se il puntatore è nullo ritorna 1 altrimenti ritorna 0
 * ATTENZIONE se è già presente nella cartella un file con lo stesso nome lo sovrascrive! 
 *  @param filename     nome del file su cui salvare (senza estensione)
 *  @param sol          puntatore a Sollevatore da stampare
 */
int StePer_save_sollevatore(
    StePer_Sollevatore* sol, 
    std::string filename
    );

    /**
*   Modifica il valore di l_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_l parametro nuovo
*/
int StePer_set_l_sollevatore(StePer_Sollevatore* sol,double new_l);

/**
*   Modifica il valore di s_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_s parametro nuovo
*/
int StePer_set_s_sollevatore(StePer_Sollevatore* sol,double new_s);

/**
*   Modifica il valore di d_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_d parametro nuovo
*/
int StePer_set_d_sollevatore(StePer_Sollevatore* sol,double new_d);


/**
*   Modifica il valore di n_aste_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_n parametro nuovo
*/
int StePer_set_n_sollevatore(StePer_Sollevatore* sol,double new_n);

/**
*   Modifica il valore di x_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_x parametro nuovo
*/
int StePer_set_x_sollevatore(StePer_Sollevatore* sol,double new_x);

/**
*   Modifica il valore di y_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_y parametro nuovo
*/
int StePer_set_y_sollevatore(StePer_Sollevatore* sol,double new_y);

/**
*   Modifica il valore di w_sollevatore     
*   se il nuovo valore è incompatibile con la macchina Sollevatore ritorna 1 e non modifica il componente 
*   altrimenti ritorna 0 e modifica il parametro
*   @param sol puntatore a Sollevatore da modificare
*   @param new_w parametro nuovo
*/
int StePer_set_w_sollevatore(StePer_Sollevatore* sol,double new_w);


#endif 
