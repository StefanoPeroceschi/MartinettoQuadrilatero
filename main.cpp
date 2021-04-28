#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>

#include"include/StePer_func.h"


int main(){
    char choice;
    StePer_Quadrilatero* quad = NULL;
    do{
        std::cout<<"\nScegli azione premendo il comando corrispondente []:\n\n";
        std::cout<<"[i]\tInizializza quadrilatero (ATTENZIONE elimina quadrilatero corrente)\n";
        std::cout<<"[c]\tCarica quadrilatero da file (ATTENZIONE elimina quadrilatero corrente)\n";
        std::cout<<"[a]\tSalva quadrilatero su file\n";
        std::cout<<"[b]\tSalva scrissor lift su file\n";
        std::cout<<"[h]\tImposta nuova altezza h\n";
        std::cout<<"[l]\tImposta nuova lunghezza aste l\n";
        std::cout<<"[s]\tImposta nuovo spesore aste s\n";
        std::cout<<"[d]\tImposta nuovo diametro perno d\n";
        std::cout<<"[x]\tImposta nuova posizione xa\n";
        std::cout<<"[y]\tImposta nuova posizione ya\n";
        std::cout<<"[q]\tTermina programma\n";

        std::cin>> choice;

        switch (choice)
        {
        case 'i':{
            double h, l, s, d, xa, ya;
            do{
                std::cout<<"\nInserire h\n";
                std::cin>> h;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>h;
	            }
                std::cout<<"\nInserire l\n";
                std::cin>> l;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>l;
	         }
                std::cout<<"\nInserire s\n";
                std::cin>> s;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>s;
	            }
                std::cout<<"\nInserire d\n";
                std::cin>> d;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>d;
	            }
                std::cout<<"\nInserire xa\n";
                std::cin>> xa;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>xa;
	            }
                std::cout<<"\nInserire ya\n";
                std::cin>> ya;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>ya;
	            }

                if(quad != NULL){
                    free (quad);
                }
                quad = StePer_init(h,l,s,d,xa,ya);


                if(quad == NULL){
                    std::cout<<"\nErrore: parametri non validi, reinserire i valori\n";
                    break;
                }
            }while(quad==NULL);
            break;
        }
        case 'c':{
            std::string filename;
            
                
            std::cout<<"\nInserire nome del file da caricare (senza estensione)\nil file deve essere stato generato "; 
            std::cout<<"da questo programma per evitare errori\n";
            std::cin>>filename;

            if(quad != NULL){
                free (quad);
            }

            quad = StePer_load_from_file(filename);

            if(quad == NULL){
                std::cout<<"\nERRORE: file danneggiato o non esistente\n";
            }              
                      
            
            break;
        }
        case 'a':{
            if(quad == NULL){
                std::cout<<"\nERRORE: necessario inizializzare un quadrilatero per eseguire salvataggio\n";
                break;
            } 
            std::string filename;
            char choice;
            bool with_measures;

            
            std::cout<<"\nInserire nome del file su cui salvare (senza estensione)\n"; 
            std::cin>>filename;
            std::cout<<"\nSi vogliono salvare anche le misure? [s/n]\n"; 
            std::cin>>choice;
            choice== 's' ? with_measures=true : with_measures=false;
            

            StePer_save(quad, filename, with_measures);
            
            break;
        }
        case 'h':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova altezza h\n"; 
            std::cin>>x;
            if(StePer_set_h(quad, x)){
                std::cout<<"\nERRORE: altezza non valida\nIl quadrilatero non è stato modificato\n"; 
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'l':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova lunghezza aste l\n"; 
            std::cin>>x;
            if(StePer_set_l(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 's':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo spessore aste s\n"; 
            std::cin>>x;
            if(StePer_set_s(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'd':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo diametro perni d\n"; 
            std::cin>>x;
            if(StePer_set_d(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'x':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova xa\n"; 
            std::cin>>x;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>x;
	        }
            if(StePer_set_xa(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'y':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova ya\n"; 
            std::cin>>x;
            while(!(std::cin.good())){
		        std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		        std::cin.clear();
      		    while (std::cin.get() != '\n');
		        std::cin>>x;
	        }
            if(StePer_set_ya(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        case 'b':{
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
        }
        }
        

    }while(choice != 'q');
    

    free(quad);
    

    return 0;


}