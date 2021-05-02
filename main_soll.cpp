#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>

#include"include/StePer_func.h"
#include"include/StePer_sollevatore.h"


int main(){
    char choice;
    StePer_Sollevatore* sol = StePer_init_sollevatore(150.,23.,22.,3,43.,400.,550.,250.);
    do{
        std::cout<<"\nScegli azione premendo il comando corrispondente []:\n\n";
        std::cout<<"[i]\tInizializza sollevatore (ATTENZIONE elimina sollevatore corrente)\n";
        std::cout<<"[c]\tCarica quadrilatero da file (ATTENZIONE elimina quadrilatero corrente)\n";
        std::cout<<"[a]\tSalva sollevatore su file\n";
        std::cout<<"[l]\tImposta nuova lunghezza aste l\n";
        std::cout<<"[s]\tImposta nuovo spesore aste s\n";
        std::cout<<"[d]\tImposta nuovo diametro perno d\n";
        std::cout<<"[n]\tImposta nuovo n_aste\n";
        std::cout<<"[f]\tImposta nuova dimensione blocchi\n";
        std::cout<<"[x]\tImposta nuova posizione x\n";
        std::cout<<"[y]\tImposta nuova posizione y\n";
        std::cout<<"[w]\tImposta nuova apertura alla base w\n";
        std::cout<<"[q]\tTermina programma\n";

        std::cin>> choice;

        switch (choice)
        {
        case 'i':{
            double l, s, d, dim, n, x, y, w;
            do{
                std::cout<<"\nInserire l\n";
                std::cin>> l;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>l;
	         }
                std::cout<<"\nInserire s (spessore aste [suggerito 20])\n";
                std::cin>> s;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>s;
	            }
                std::cout<<"\nInserire d  (diametro perno [suggerito 19])\n";
                std::cin>> d;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>d;
	            }
                std::cout<<"\nInserire n_aste (numero elementi sollevatore a forbice [suggerito 2])\n";
                std::cin>> n;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>n;
	            }
                std::cout<<"\nInserire dim_blocchi della guida prismatica [suggerito 34]\n";
                std::cin>> dim;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>dim;
	            }
                std::cout<<"\nInserire x (posizione x [suggerita 400])\n";
                std::cin>> x;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>x;
	            }
                std::cout<<"\nInserire y (posizione y [suggerita 550])\n";
                std::cin>> y;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>y;
	            }
                std::cout<<"\nInserire w (estensione guida prismatica [suggerito 170])\n";
                std::cin>> w;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>w;
	            }

                if(sol != NULL){
                    StePer_destroy_sollevatore (sol);
                }
                sol = StePer_init_sollevatore(l,s,d,n,dim,x,y, w);


                if(sol == NULL){
                    std::cout<<"\nErrore: parametri non validi, reinserire i valori\n";
                    break;
                }
            }while(sol==NULL);
            break;
        }
        case 'c':{
            std::string filename;
            
                
            std::cout<<"\nInserire nome del file da caricare (senza estensione)\nil file deve essere stato generato "; 
            std::cout<<"da questo programma per evitare errori\n";
            std::cin>>filename;

            if(sol != NULL){
               // free (quad);
            }

            //sol = StePer_load_from_file(filename);

            if(sol == NULL){
                std::cout<<"\nERRORE: file danneggiato o non esistente\n";
            }              
                      
            
            break;
        }
        case 'a':{
            if(sol == NULL){
                std::cout<<"\nERRORE: necessario inizializzare un sollevatore per eseguire salvataggio\n";
                break;
            } 
            std::string filename;
            

            
            std::cout<<"\nInserire nome del file su cui salvare (senza estensione)\n"; 
            //std::cin>>filename;
              filename="e";        

            StePer_save_sollevatore(sol, filename);
            
            break;
        }
        case 'l':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova lunghezza l\n"; 
            std::cin>>x;
            if(StePer_set_l_sollevatore  (sol, x)){
                std::cout<<"\nERRORE: lunghezza non valida\nIl sollevatore non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 's':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo spessore aste s\n"; 
            std::cin>>x;
            if(StePer_set_s_sollevatore  (sol, x)){
                std::cout<<"\nERRORE: spessore non valido\nIl sollevatore non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'd':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo spessore perno d\n"; 
            std::cin>>x;
            if(StePer_set_d_sollevatore  (sol, x)){
                std::cout<<"\nERRORE: spessore non valido\nIl sollevatore non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'n':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo numero aste n\n"; 
            std::cin>>x;
            if(StePer_set_n_sollevatore  (sol, x)){
                std::cout<<"\nERRORE: numero non valido\nIl sollevatore non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'f':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova dimensione blocchi\n"; 
            std::cin>>x;
            
            if(StePer_set_dimblocchi_sollevatore (sol, x)){
                std::cout<<"\nERRORE: numero non valido\nIl sollevatore non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'x':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova coordinata x\n"; 
            std::cin>>x;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>x;
	        }
            if(StePer_set_x_sollevatore(sol, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'y':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova coordinata y\n"; 
            std::cin>>x;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>x;
	        }
            if(StePer_set_y_sollevatore(sol, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'w':{
            if(sol== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un sollevatore\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo valore w\n"; 
            std::cin>>x;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>x;
	        }
            if(StePer_set_w_sollevatore(sol, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        /*case 'b':{
            if(quad == NULL){
                std::cout<<"\nERRORE: necessario inizializzare un quadrilatero per eseguire salvataggio\n";
                break;
            } 
            std::string filename;
            bool with_measures;
            int n_segmenti;

            
            std::cout<<"\nInserire nome del file su cui salvare (senza estensione)\n"; 
            std::cin>>filename;
            std::cout<<"\nInserire numero di segmenti\n"; 
            std::cin>>n_segmenti;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>n_segmenti;
	        }
            double w = sqrt( pow(2 * quad->l,2 ) - pow(quad->h,2)  );
            
            StePer_ScrissorLift* lift = StePer_init_scrissorlift(n_segmenti, quad->l, quad->s, quad->d, (quad->xa)-w/2,(quad->ya)-(quad->h)/2,w);
            if (lift==NULL){
                std::cout <<"\nErrore: il meccanismo esce dal riquadro, scegliere un numero minore di segmenti\n";
                break;
            }
            StePer_save_scrissorlift(lift, filename);
            StePer_destroy_scrissorlift(lift);
            
            break;
        }*/
        }
        

    }while(choice != 'q');
    

    StePer_destroy_sollevatore(sol);
    

    return 0;


}