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
    
    string find(string text, string word);
}