#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include"include/StePer_func.h"


int main(){
    char choice;
    StePer_Quadrilatero* quad = NULL;
    do{
        std::cout<<"\nScegli azione premendo il comando corrispondente []:\n\n";
        std::cout<<"[1]\tInizializza quadrilatero (ATTENZIONE elimina quadrilatero corrente)\n";
        std::cout<<"[2]\tCarica quadrilatero da file (ATTENZIONE elimina quadrilatero corrente)\n";
        std::cout<<"[3]\tSalva quadrilatero su file\n";
        std::cout<<"[4]\tImposta nuova altezza h\n";
        std::cout<<"[5]\tImposta nuova lunghezza aste l\n";
        std::cout<<"[6]\tImposta nuovo spesore aste s\n";
        std::cout<<"[7]\tImposta nuovo diametro perno d\n";
        std::cout<<"[8]\tImposta nuova posizione xa\n";
        std::cout<<"[9]\tImposta nuova posizione ya\n";
        std::cout<<"[0]\tTermina programma\n";

        std::cin>> choice;

        switch (choice)
        {
        case '1':{
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
        case '2':{
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
        case '3':{
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
        case '4':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova altezza h\n"; 
            std::cin>>x;
            if(StePer_set_h(quad, x)){
                std::cout<<"\nERRORE: altezza non valida\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        case '5':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova lunghezza aste l\n"; 
            std::cin>>x;
            if(StePer_set_l(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        case '6':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo spessore aste s\n"; 
            std::cin>>x;
            if(StePer_set_s(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        case '7':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire il nuovo diametro perni d\n"; 
            std::cin>>x;
            if(StePer_set_d(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        case '8':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova xa\n"; 
            std::cin>>x;
            if(StePer_set_xa(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        case '9':{
            if(quad== NULL){
                std::cout<<"\nERRORE: necessario prima inizializzare un quadrilatero\n";  
                break;   
            }
            double x;
            std::cout<<"\nInserire la nuova ya\n"; 
            std::cin>>x;
            if(StePer_set_ya(quad, x)){
                std::cout<<"\nERRORE: valore non valido\nIl quadrilatero non è stato modificato\n";  
            }            
            break;
        }
        }
        

    }while(choice != '0');
    

    free(quad);
    

    return 0;


}