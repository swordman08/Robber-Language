#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "Model.h"

using namespace std;



class Translator {

public:
    Translator(); //constructor
    ~Translator(); //deconstructor
    string translateEnglishWord(string word); 
    string translateEnglishSentence(string sentence); 

private:
    Model *model;
    bool isVowel(char c);
    
};

#endif // TRANSLATOR_H