#ifndef STEPER_FUNC_H
#define STEPER_FUNC_H




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



#endif // STEPER_FUNC_H
