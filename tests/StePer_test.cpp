
#include "../include/catch2/catch2.hpp"
#include "../include/StePer_func.h"


TEST_CASE("StePer_check deve ritornare 1 con parametri non validi", "[func]") {
    REQUIRE(StePer_check(-1,2,2,2,2,2)==1 );
    REQUIRE(StePer_check(2,-1,2,2,2,2)==1 );
    REQUIRE(StePer_check(2,2,-1,2,2,2)==1 );
    REQUIRE(StePer_check(2,2,2,2,2,2)==1 );
    REQUIRE(StePer_check(200,200,20,19,400,400)==0 );
     
}
TEST_CASE("StePer_check deve ritornare 0 con parametri validi", "[func]") {

    REQUIRE(StePer_check(200,200,20,19,400,400)==0 );
     
}


TEST_CASE("StePer_init deve ritornare un puntatore se chiamato con parametri corretti ", "[func]") {
    REQUIRE(StePer_init(200,200,20,19,400,400)!=NULL);    
}
TEST_CASE("StePer_init deve ritornare NULL se chiamato con parametri scorretti ", "[func]") {
    REQUIRE(StePer_init(0,0,0,-2,400,400)==NULL);    
}

TEST_CASE("StePer_to_svg_init deve tornare la stringa con l'inizializzazione svg", "[func]") {
    std::string out = "";
    out += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"";
    out += std::to_string(SVG_X) ;
    out +=  "\" height=\"";
    out += std::to_string(SVG_Y) ;
    out += "\">";
    REQUIRE(StePer_to_svg_init()== out);    
}


TEST_CASE("StePer_to_svg_close deve tornare la stringa con la chiusura dell' svg", "[func]") {
    REQUIRE(StePer_to_svg_close()== "\n</svg>\n");    
}
TEST_CASE("Salvado e ricaricando un quadrilatero devo riottenere il quadrilatero di partenza ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);

    StePer_save(quad, "test_cmake_with_measures",true);
    StePer_save(quad, "test_cmake_without_measures",false);
    free ( quad );
    quad=StePer_load_from_file("test_cmake_with_measures");

    REQUIRE( quad->h==Approx(200.1));
    REQUIRE( quad->l==Approx(200.2));
    REQUIRE( quad->s==Approx(13.3));
    REQUIRE( quad->d==Approx(12.4));
    REQUIRE( quad->xa==Approx(400.5));
    REQUIRE( quad->ya==Approx(500.6));   
    free ( quad );
    quad=StePer_load_from_file("test_cmake_without_measures");

    REQUIRE( quad->h==Approx(200.1));
    REQUIRE( quad->l==Approx(200.2));
    REQUIRE( quad->s==Approx(13.3));
    REQUIRE( quad->d==Approx(12.4));
    REQUIRE( quad->xa==Approx(400.5));
    REQUIRE( quad->ya==Approx(500.6));    

    free (quad);
}

TEST_CASE("StePer_load_from_file deve ritornare NULL se il file non esiste", "[func]") {
    REQUIRE(StePer_load_from_file("file_inesistente")==NULL );    
}

TEST_CASE("StePer_set_h non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_h(quad,401.);
    REQUIRE(quad->h==Approx(200.1) );    
    free(quad);
}
TEST_CASE("StePer_set_h deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_h(quad,300.);
    REQUIRE(quad->h==Approx(300.) );    
    free(quad);
}

TEST_CASE("StePer_set_l non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_l(quad,13.);
    REQUIRE(quad->l==Approx(200.2) );    
    free(quad);
}
TEST_CASE("StePer_set_l deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_l(quad,300.);
    REQUIRE(quad->l==Approx(300.) );    
    free(quad);
}

TEST_CASE("StePer_set_s non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_s(quad,401.);
    REQUIRE(quad->s==Approx(13.3) );    
    free(quad);
}
TEST_CASE("StePer_set_s deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_s(quad,15.);
    REQUIRE(quad->s==Approx(15.) );    
    free(quad);
}

TEST_CASE("StePer_set_d non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_d(quad,401.);
    REQUIRE(quad->d==Approx(12.4) );    
    free(quad);
}
TEST_CASE("StePer_set_d deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_d(quad,12.);
    REQUIRE(quad->d==Approx(12.) );    
    free(quad);
}

TEST_CASE("StePer_set_xa non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_xa(quad,901.);
    REQUIRE(quad->xa==Approx(400.5) );    
    free(quad);
}
TEST_CASE("StePer_set_xa deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_xa(quad,300.);
    REQUIRE(quad->xa==Approx(300.) );    
    free(quad);
}

TEST_CASE("StePer_set_ya non deve modificare il parametro se in ingresso ha valori non validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_ya(quad,720.);
    REQUIRE(quad->ya==Approx(500.6) );    
    free(quad);
}
TEST_CASE("StePer_set_ya deve modificare il parametro se in ingresso ha valori validi ", "[func]") {
    StePer_Quadrilatero* quad;
    quad=StePer_init(200.1,200.2,13.3,12.4,400.5,500.6);
    StePer_set_ya(quad,300.);
    REQUIRE(quad->ya==Approx(300.) );    
    free(quad);
}

TEST_CASE("StePer_init_scrissorlift deve inizializzare una struttura Scrissorlift con parametri corretti", "[func]") {
    StePer_ScrissorLift* lift;
    lift=StePer_init_scrissorlift(3,200.,22.,21.,300.,490.,370.);
    REQUIRE(lift->quad->l==Approx(200.) );
    REQUIRE(lift->quad->s==Approx(22.) );
    REQUIRE(lift->quad->d==Approx(21.) );    
    REQUIRE(lift->n_quad== 3 );
    free(lift);
}
TEST_CASE("StePer_init_scrissorlift deve ritornare un puntatore nullo se si chiama con parametri non corretti", "[func]") {
    StePer_ScrissorLift* lift;
    lift=StePer_init_scrissorlift(3,200.,22.,23.,300.,490.,370.);
    REQUIRE(lift==NULL );
    lift=StePer_init_scrissorlift(4,200.,22.,21.,300.,490.,370.);
    REQUIRE(lift==NULL );
    lift=StePer_init_scrissorlift(1,200.,22.,21.,300.,490.,400.);
    REQUIRE(lift==NULL );
    lift=StePer_init_scrissorlift(1,200.,22.,21.,300.,820.,350.);
    REQUIRE(lift==NULL );

    free(lift);
}








