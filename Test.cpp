#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace std;
using namespace phonetic;

TEST_CASE("check if LOWER CASE transform work")
{
    string text = "Dond vorri be haffy";
    
    CHECK(find(text,"dond") == string("Dond"));
    CHECK(find(text,"Dond") == string("Dond"));
    CHECK(find(text,"DoNd") == string("Dond"));
    
    
    CHECK(find(text,"Vorri") == string("vori"));
    CHECK(find(text,"vorrI") == string("vorri"));
    CHECK(find(text,"vorri") == string("vorri"));
    
    
    CHECK(find(text,"BE") == string("be"));
    CHECK(find(text,"bE") == string( "be"));
    
   
    CHECK(find(text,"haffy") == string("haffy"));
    CHECK(find(text,"haFFy") == string("haffy"));
    CHECK(find(text,"HAFFY") == string("haffy"));
    CHECK(find(text,"Haffy") == string("haffy"));

}


TEST_CASE("check transform between v and w") 
{
        string text = "Dond vorri be haffy";
        
        CHECK(find(text,"worri") == string("vorri"));
        CHECK(find(text,"worry") == string("vorri"));
        
        
        CHECK(find("vord and word","word") == string("word"));
        CHECK(find("my name is volwerine","wolverine") == string("volwerine"));
        CHECK(find("my name is wolwerine","wolverine") == string("wolwerine"));
        
        
        CHECK(find("work for Vork","Vork") == string("Vork"));
        CHECK(find("work for Vork","work") == string("work"));
        
        CHECK(find("twerk for Vork","work") == string("Vork"));

        CHECK(find("ve vill we vill rock you","we") == "we");
        CHECK(find("cov and cov were out","cow") == "cov");
   
}

TEST_CASE("check transform between b, f, p") 
{

        CHECK(find("Dond vorri be haffy","happy") == string("haffy"));
        CHECK(find("fly into the pufpet","buffet") == string("pufpet"));
        
        CHECK(find("play and flay","play") == string("play"));
        CHECK(find("play and flay","flay") == string("flay")); 
        
        CHECK(find("preferd perfect","preferd") == string("preferd"));
        CHECK(find("breperd perfect","preferd") == string("breperd")); 
        
        CHECK(find("bap fap pap","pap") == string("pap"));
        CHECK(find("broblem and not problem","broblem") == string("broblem")); 
        
        CHECK(find("club or clup","clup") == string("clup"));
        CHECK(find("pice of faber","paper") == string("paber"));
    
   
}
TEST_CASE("check transform between g, j") 
{
    
        CHECK(find("give me jive me","give") == string("give"));
        CHECK(find("jive me give me","give") == string("give"));
        
        CHECK(find("google moogle","joojle") == string("google"));
        CHECK(find("goojle moogle","google") == string("goojle")); 
        
        CHECK(find("joogle moogle","google") == string("joogle"));
        CHECK(find("jump and gump","gump") == string("gump")); 
        
        CHECK(find("jump and gump","jump") == string("jump"));
        
        CHECK(find("trump is jump","gump") == string("jump")); 
        
        CHECK(find("jennifer or gennifer","Jennifer") == string("jennifer"));
        CHECK(find("gum gum jum","jum") == string("jum"));
   
}
//////////////////////////////////////////////

TEST_CASE("check transform between c, k, q") 
{
    
   
}

TEST_CASE("check transform between s, z") 
{
    
   
}

TEST_CASE("check transform between d, t") 
{
    
   
}

TEST_CASE("check transform between o, u") 
{
    
   
}

TEST_CASE("check transform between i, y") 
{
    
   
}

TEST_CASE("check Exceptions") 
{
    
   
}


/* add more test cases here */
