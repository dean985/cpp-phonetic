#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace std;
using namespace phonetic;

TEST_CASE("check if LOWER CASE transform work")
{
    string text = "Dond vorri be haffy";
    
    CHECK(find(text,"dond") == "Dond");
    CHECK(find(text,"Dond") == "Dond");
    CHECK(find(text,"DoNd") == "Dond");
    
    
    CHECK(find(text,"Vorri") == "vori");
    CHECK(find(text,"vorrI") == "vorri");
    CHECK(find(text,"vorri") == "vorri");
    
    
    CHECK(find(text,"BE") == "be");
    CHECK(find(text,"bE") == "be");
    
   
    CHECK(find(text,"haffy") == "haffy");
    CHECK(find(text,"haFFy") == "haffy");
    CHECK(find(text,"HAFFY") == "haffy");
    CHECK(find(text,"Haffy") == "haffy");

}


TEST_CASE("check transform between v and w") 
{
    
   
}

TEST_CASE("check transform between b, f, p") 
{
    
   
}
TEST_CASE("check transform between g, j") 
{
    
   
}

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
