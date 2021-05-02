
#include "../include/catch2/catch2.hpp"
#include "../include/StePer_sollevatore.h"


TEST_CASE("StePer_init_sollevatore deve ritornare un puntatore se chiamato con parametri corretti ", "[sollevatore][init]") {
    REQUIRE(StePer_init_sollevatore(150, 23, 22, 2, 34, 400, 550, 280)!=NULL);    
}
TEST_CASE("StePer_init_sollevatore deve ritornare NULL se chiamato con parametri scorretti ", "[sollevatore][init]") {
    REQUIRE(StePer_init_sollevatore(150, 20, 21, 2, 32, 400, 550, 150)  ==NULL); 
    REQUIRE(StePer_init_sollevatore(150, 22, 21, 8, 32, 400, 550, 150)  ==NULL); 
    REQUIRE(StePer_init_sollevatore(150, 22, 21, 2, 32, 400, 5550, 150) ==NULL); 
    REQUIRE(StePer_init_sollevatore(150, 22, 21, 2, 32, 400, 550, 1150) ==NULL); 
    REQUIRE(StePer_init_sollevatore(150, 22, 21, 2, 400, 400, 550, 150) ==NULL);    
}

TEST_CASE("Check valori validi", "[sollevatore][check]") {
    REQUIRE(StePer_check_sollevatore(150, 23, 22, 2, 34, 400, 550, 280)==0);    
}

TEST_CASE("Check valori non validi", "[sollevatore][check]") {
    REQUIRE(StePer_check_sollevatore(150, 20, 21, 2, 32, 400, 550, 150)  ==1); 
    REQUIRE(StePer_check_sollevatore(150, 22, 21, 8, 32, 400, 550, 150)  ==1); 
    REQUIRE(StePer_check_sollevatore(150, 22, 21, 2, 32, 400, 5550, 150) ==1); 
    REQUIRE(StePer_check_sollevatore(150, 22, 21, 2, 32, 400, 550, 1150) ==1); 
    REQUIRE(StePer_check_sollevatore(150, 22, 21, 2, 400, 400, 550, 150) ==1);    

}

TEST_CASE("Due sollevatori inizializzati con gli stessi parametri devono essere uguali", "[sollevatore][are_equal]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true);
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2); 
}

TEST_CASE("modifica parametro l", "[sollevatore][set_l]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(160., 23., 22., 2, 34., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_l_sollevatore(sol1, 150.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2);
}

TEST_CASE("modifica parametro s", "[sollevatore][set_s]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 25., 22., 2, 34., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_s_sollevatore(sol1, 23.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true);
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2); 
}

TEST_CASE("modifica parametro d", "[sollevatore][set_d]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 20., 2, 34., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_d_sollevatore(sol1, 22.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2);
}

TEST_CASE("modifica parametro n_aste", "[sollevatore][set_n]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 3, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_n_sollevatore(sol1, 3);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2);
}

TEST_CASE("modifica parametro dimensione_blocchi di guida prismatica", "[sollevatore][set_dimblocchi]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 22., 2, 31., 300., 550., 290.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 34., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_dimblocchi_sollevatore(sol1, 34.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2);
}

TEST_CASE("modifica parametro w (estensione guida prismatica) ", "[sollevatore][set_w]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 22., 2, 31., 300., 550., 280.);
    StePer_Sollevatore* sol2= StePer_init_sollevatore(150., 23., 22., 2, 31., 300., 550., 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == false); 
    StePer_set_w_sollevatore(sol1, 290.);
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
    StePer_destroy_sollevatore(sol1);
    StePer_destroy_sollevatore(sol2);
}

TEST_CASE("Verifica che Sollevatore salvato e ricaricato sia uguale all'originale", "[sollevatore][save/load]") {
    StePer_Sollevatore* sol1= StePer_init_sollevatore(150., 23., 22., 2, 31., 300., 550., 280.);
    StePer_Sollevatore* sol2;

    StePer_save_sollevatore(sol1, "test_cmake_sollevatore");
    sol2 = StePer_load_from_file_sollevatore("test_cmake_sollevatore");
     
    REQUIRE(StePer_are_equal(sol1, sol2 ) == true); 
   
}





