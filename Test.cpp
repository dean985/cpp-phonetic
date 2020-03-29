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
    
    
    CHECK(find(text,"Vorri") == string("vorri"));
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
        
        
        CHECK(find("vord and word","word") == string("vord"));
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


TEST_CASE("check transform between c, k, q") 
{       
        string text = "kommunity cuit kuiet cilo";
        CHECK(find(text, "community") == string("kommunity"));
        CHECK(find(text, "quit") == string("cuit"));
        CHECK(find(text, "quiet") == string("keuit"));
        CHECK(find(text, "kilo") == string("cilo"));
        
        string text2 = "herkules chikqen qangroo darq";
        CHECK(find(text2, "hercules") == string("herkules"));
        CHECK(find(text2, "chicken") == string("chikqen"));
        CHECK(find(text2, "kangroo") == string("qangroo"));
        CHECK(find(text2, "dark") == string("darq"));
        
        CHECK(find("maqe", "make") == string("maqe"));
        CHECK(find("kool", "cool") == string("kool"));
        CHECK(find("roqq", "rock") == string("roqq"));
}

TEST_CASE("check transform between s, z") 
{
    CHECK(find("mezs", "mess") == string("mezs"));
    CHECK(find("mezz", "mess") == string("mezz"));
    CHECK(find("initialise", "initialize") == string("initialise"));
    CHECK(find("sleep", "sleep") == string("sleep"));
    CHECK(find("zleep", "sleep") == string("zleep"));
    CHECK(find("magasine", "magazine") == string("magasine"));
    CHECK(find("gooze", "goose") == string("gooze"));
    CHECK(find("marz", "mars") == string("marz"));
    CHECK(find("buz", "bus") == string("buz"));
    CHECK(find("organisation", "organization") == string("organisation"));
    CHECK(find("recognisez", "recognizes") == string("recognizes"));
   
}

TEST_CASE("check transform between d, t") 
{
    CHECK(find("toor","door") == string("toor"));
    CHECK(find("rood","root") == string("rood"));
    CHECK(find("telta", "delta") == string("telta"));
    CHECK(find("telda", "delta") == string("telda"));
    CHECK(find("horizondal","horizontal") == string("horizondal"));
    CHECK(find("remode","remote") == string("remode"));
    CHECK(find("build", "built") == string("build"));
    CHECK(find("bud", "but") == string("bud"));
    CHECK(find("god", "got") == string("god"));
    CHECK(find("coasd", "coast") == string("coasd"));
    CHECK(find("cad", "cat") == string("cad"));
}

TEST_CASE("check transform between o, u") 
{
    CHECK(find("chuculate","chocolate") == string("chuculate"));
    CHECK(find("choculate","chocolate") == string("choculate"));
    CHECK(find("bathruum", "bathroom") == string("bathruum"));
    CHECK(find("authurs","authors") == string("authurs"));
    CHECK(find("aothors","authors") == string("aothors"));
    CHECK(find("aroond", "around") == string("aroond"));
    CHECK(find("aoto", "auto") == string("aoto"));
    CHECK(find("buuk", "book") == string("buuk"));
    CHECK(find("up", "op") == string("up"));
    CHECK(find("op","up") == string("op"));
    CHECK(find("aodiu","audio") == string("aodiu"));
   
}

TEST_CASE("check transform between i, y") 
{
    CHECK(find("alwais","always") == string("alwais"));
    CHECK(find("beauti","beauty") == string("beauty"));
    CHECK(find("buiyng","buying") == string("buiyng"));
    CHECK(find("buiing","buying") == string("buiing"));
    CHECK(find("arrai", "array") == string("arrai"));
    CHECK(find("easyly","easily") == string("easyly"));
    CHECK(find("emploiment","employment") == string("emploiment"));
    CHECK(find("diversyty","diversity") == string("diversyty"));
    CHECK(find("dyversyty","diversity") == string("dyversyty"));
    CHECK(find("displaied","displayed") == string("displaied"));
    CHECK(find("dysplayed", "displayed") == string("dysplayed"));
}

TEST_CASE("check Exceptions") 
{
    CHECK_THROWS_AS(find("Dond vorri be haffy", ""), phonetic::RuleException);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "123"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "123word"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "1a2b3"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond 1a2b3 be haffy", "vorri"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "hello1a2b3"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "vorri be"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "hello@$"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri !!!! haffy", "Dond"), phonetic::badWord);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "hello"), phonetic::notFound);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "haff"), phonetic::notFound);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "bbe"), phonetic::notFound);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "vorr"), phonetic::notFound);
    CHECK_THROWS_AS(find("Dond vorri be haffy", "worre"), phonetic::notFound);
    
    /// OPTIONAL CASES TO THROW EXEPTION ///
    /// empty word
    ///didnt find the word
   
}