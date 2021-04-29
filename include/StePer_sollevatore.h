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


#endif 
