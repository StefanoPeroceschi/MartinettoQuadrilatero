#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

#include"include/StePer_func.h"
#include"include/StePer_sollevatore.h"


int main(){
    char choice;
    StePer_Sollevatore** macc = NULL;
    unsigned int n_istanze = 0;
    
    do{
        std::cout<<"\nScegli azione premendo il comando corrispondente []:\n\n";
        std::cout<<"[i]\tInizializza sollevatore (ATTENZIONE elimina sollevatore corrente)\n";
        std::cout<<"[a]\tSalva sollevatore su file\n";
        std::cout<<"[w]\tImposta nuova apertura alla base w\n";
        std::cout<<"[q]\tTermina programma\n";

        std::cin>> choice;

        switch (choice)
        {
        bool error ;
        case 'i':{
            unsigned r;
            double l, s, d, dim, n, x, y, w;
            do{
                error = false;
                std::cout<<"\nInserire l (semilunghezza aste, [suggerito 100])\n";
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
                std::cout<<"\nInserire d (diametro perno [suggerito 19])\n";
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
                std::cout<<"\nInserire x (posizione x [suggerita 300])\n";
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
                std::cout<<"\nInserire n° macchine sovrapposte [suggerite 2]\n";
                std::cin>> r;
                while(!(std::cin.good())){
		            std::cout<<"\nErrore: Parametro non valido, reinserire\n ";
		            std::cin.clear();
      		        while (std::cin.get() != '\n');
		            std::cin>>r;
	            }
                if(StePer_check_sollevatore(l,s,d,n,dim,x,y,w)){
                     std::cout<<"\nErrore: parametri incompatibili con la macchina\n ";
                     break;
                }
               
                StePer_destroy_macchina(macc, n_istanze);
                
                n_istanze=r;
                

                double h = 2*sqrt(l*l - (w/2)*(w/2));
                macc= new StePer_Sollevatore*[n_istanze];
                for(int i = 0; i < n_istanze; i++){
                   macc[i] = StePer_init_sollevatore(l, s, d, n, dim, x, y - h*i*n, w);
                }

                
                for(int i = 0; i < n_istanze; i++){
                   if(macc[i]==NULL){
                       error= true;
                   }
                }
                
                if(error){
                    std::cout<<"\nErrore: parametri non validi, reinserire i valori\n";
                    StePer_destroy_macchina(macc, n_istanze);
                    free(macc);
                    macc=NULL;
                    n_istanze=0;
                }
                 
            }while(error);
            break;
        }
      
        case 'a':{
            if(n_istanze==0){
                std::cout<<"\nERRORE: necessario inizializzare un sollevatore per eseguire salvataggio\n";
                break;
            } 
            std::string filename;
            

            
            std::cout<<"\nInserire nome del file su cui salvare (senza estensione)\n"; 
            std::cin>>filename;

           
            std::ofstream file;
            file.open (filename+".svg");
            file << StePer_to_svg_init();
            for(int i = 0 ; i < n_istanze; i++){
                file << StePer_to_svg_sollevatore(macc[i]);
            }
            file << StePer_to_svg_close();
            file.close();
            
            break;
        }
        
       
        case 'w':{
            if(n_istanze==0){
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
            error=false;
            for (int i= 0; i<n_istanze; i++){
                if(StePer_set_w_sollevatore(macc[i], x)){
                    error=true;
                }
            }
            double h = 2*sqrt(pow(macc[0]->lift->quad->l,2) - pow((macc[0]->guida->corsa)/2, 2));
            for (int i= 0; i<n_istanze; i++){
                if(StePer_set_y_sollevatore(macc[i], macc[0]->guida->pos_y - i*h*n_istanze)){
                    error=true;
                }
            }
            if(error){
                std::cout<<"\nERRORE: valore non valido\n\n";  
                std::cin.clear(); 
                while (std::cin.get() != '\n');
            }            
            break;
        }
        
        

    }
    }while(choice != 'q');
    

    StePer_destroy_macchina(macc, n_istanze);
    free(macc);
    

    return 0;
}



