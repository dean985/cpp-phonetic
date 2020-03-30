#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>
using namespace std;


namespace phonetic
{   
    bool isLetter(char c){
        if ( (c > 64 && c <91)  || (c >96 && c <123)) return true;
        return false;
    }

    /**
     * This function is building an array of words
     * text is the input string to be examined
     * spaces- an integer that has to be initialized to zero as an argument
     *         and the value of it will be changes to the amount of words
     */
    string* parsing(string text, int* spaces){
        int t = 0;
        // Searching for spaces - in order to understand
        // how many words are there
        for(int i =0 ; i<text.length(); i++){
            if (text[i] == ' ') t++;
        }
        *spaces = t+1;
        //Array of words
        string* str = new string[*spaces];
        int letters = 0;
        int wordlength = 0;

        for (int i = 0; i <text.length(); i++){
            //if it is a space
            if (text[i] != ' ') letters++;
            // else , it is a letter.
            else {
                str[wordlength] = text.substr(i-letters, letters);
                letters = 0;
                wordlength++;
            }
            //If reached to the end of the string
            if (i == text.length()-1){
                str[wordlength] = text.substr(i+1-letters, letters+1);
                wordlength++;
            }
        }
        return str;
    }

    /**
     * This function is using the function parsing and check the words
     * according to the requirements
     */
    string find(string text, string word)
    {
        int m = 0;
        string* t = parsing(text, &m);

        for (int i =0 ; i < m; i++){
            if (word.compare(t[i]) == 0) return t[i];
        }

        for (int i = 0 ; i< m; i++){
            string str = t[i];                                              // str is the current word being examined
            
            if (str.length() == word.length()){                             // start checking the word if and only if the word length is the same
                int c = 0;
                while(c < str.length()){
                    if (!isLetter(str[c])){
                      throw phonetic::RuleException();  
                    } 

                    if (str[c] == word[c] + 32  || str[c] == word[c]) c++;
                    
                    else if(str[c]=='j'||str[c]=='g'||str[c]=='J'||str[c]=='G'){
                        if(word[c]=='j'||word[c]=='g'||word[c]=='J'||word[c]=='G'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else if (str[c] == 'F' || str[c] == 'B' || str[c] == 'P' || 
                            str[c] == 'f' || str[c] == 'b' || str[c] == 'p' ){

                        if (word[c] == 'F' || word[c] == 'B' || word[c] == 'P' ||
                        word[c] == 'f' || word[c] == 'b' || word[c] == 'p'){
                            c++;
                        }else{
                            break;
                        }
                    }
                    else if (str[c] == 'W' || str[c] =='V' || str[c] == 'v' || str[c] == 'w'){
                        if (word[c] == 'W' || word[c] =='V' || word[c] == 'v' || word[c] == 'w'){
                            c++;
                        }else{
                            break;
                        }    
                    }                  
                    else if(str[c]=='c'||str[c]=='k'||str[c]=='q'||str[c]=='C'||str[c]=='K'||str[c]=='Q'){
                        if(word[c]=='c'||word[c]=='k'||word[c]=='q'||word[c]=='C'||word[c]=='K'||word[c]=='Q'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(str[c]=='s'||str[c]=='z'||str[c]=='S'||str[c]=='Z'){
                        if(word[c]=='s'||word[c]=='z'||word[c]=='S'||word[c]=='Z'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(str[c]=='d'||str[c]=='t'||str[c]=='D'||str[c]=='T'){
                        if(word[c]=='d'||word[c]=='t'||word[c]=='D'||word[c]=='T'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(str[c]=='o'||str[c]=='u'||str[c]=='O'||str[c]=='U'){
                        if(word[c]=='o'||word[c]=='u'||word[c]=='O'||word[c]=='U'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(str[c]=='i'||str[c]=='y'||str[c]=='I'||str[c]=='Y'){
                        if(word[c]=='i'||word[c]=='y'||word[c]=='I'||word[c]=='Y'){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        if(str[c]==word[c]){
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                }
                // While statement finished

                if (word.length() == c){        //If the our counter c equals to the word length
                                                //then we have a match
                    delete[] t;
                    return str;
                }
            }
        }
        //End of for loop 
        //If reached here - There is no match
        //free memory and throw 
        delete[] t;
        throw phonetic::RuleException();
    }
    
}
