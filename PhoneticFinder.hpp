#pragma once
#include <string>
using namespace std;

namespace phonetic 
{
    struct RuleException : public exception 
    {
       const char * what () const throw () 
       {
          return "C++ Exception";
       }
    };
    
    struct badWord : public exception {
        const char * what () const throw () 
        {
            return "String contains a letter that isn't in english.";
        }
    };
    
    struct notFound : public exception {
        const char * what () const throw () 
        {
            return "Word not found.";
        }
    };
    
    string find(string text, string word);
}