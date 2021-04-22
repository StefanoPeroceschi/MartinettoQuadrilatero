#ifndef STEPER_FUNC_H
#define STEPER_FUNC_H

#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>


#define PI 3.14159265


/**
* Struttura Quadrilatero
* 
* contenente h (altezza), l (lunghezza aste),
* s (spessore aste), d (diametro perni), xa,ya (coordinate perno alla base)
* theta, xb, yb (parametri per la stampa) 
*/
struct StePer_Quadrilatero{
    double h, l, s, d;
    
    //Parametri necessari alla stampa
    double theta, xa, ya, xb, yb;
};

/**
* Verifica parametri 
*
* la funzione ritorna 1 se i parametri sono validi altrimenti ritorna 0 
*/
int StePer_check (double h, double l, double s, double d, double xa, double ya);

/**
* Inizializzazione Quadrilatero 
* 
* la funzione ritorna il puntatore al quadrilatero generato 
* se i parametri sono validi altrimenti ritorna NULL
*/
StePer_Quadrilatero* StePer_init (double h, double l, double s, double d, double xa, double ya);

/**
* Generazione stringa svg di inizializzazione
* 
* la funzione ritorna la stringa con il testo relativo all'inizializzazione del file svg, 
* in ingresso chiede le dimensioni del file : x y
* ritorna la stringa se i parametri sono corretti, NULL altrimenti
*/
std::string StePer_to_svg_init (int x, int y);

/**
* Generazione stringa svg del componente
* 
* la funzione ritorna la stringa con il testo relativo al componente svg, 
* non comprende inizializzazione file svg
*/
std::string StePer_to_svg (StePer_Quadrilatero* quad);

/**
* Generazione stringa svg di chiusura
* 
* la funzione ritorna la stringa con il testo di chiusura del file svg
*/
std::string StePer_to_svg_close ();




/**
*   Modifica il valore di h      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_h(StePer_Quadrilatero* quad,double new_h);

/**
*   Modifica il valore di s      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_s(StePer_Quadrilatero* quad,double new_s);

/**
*   Modifica il valore di l      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_l(StePer_Quadrilatero* quad,double new_l);
/**
*   Modifica il valore di d      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_d(StePer_Quadrilatero* quad,double new_d);

/**
*   Modifica il valore di xa      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_d(StePer_Quadrilatero* quad,double new_xa);
/**
*   Modifica il valore di ya      
*   se il nuovo valore è incompatibile ritorna 0 e non modifica il componente 
*   altrimenti ritorna 1 e modifica il parametro
*/
int StePer_set_d(StePer_Quadrilatero* quad,double new_ya);

/**
*   Salva su file      
*   la funzione salva il file svg chiedendo un puntatore a Quadrilatero in ingresso
*   ed il nome del file su cui salvare
*/
void StePer_save(StePer_Quadrilatero* quad,std::string filename);

/**
*   Carica da file    
*   la funzione carica il file svg (il cui nome è passato all'ingresso) restituendo
*   il puntatore al quadrilatero caricato
*/
 StePer_Quadrilatero* StePer_parse(std::string filename); 


#endif 
