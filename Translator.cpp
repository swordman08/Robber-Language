#include "Translator.h"
#include "Model.h"

using namespace std;

Translator::Translator() {
    model = new Model();
    
}
//just messed around with pointer, was pretty easy to implement, literally a line of code and a few -> ->
//before I was creating a new model everytime translateEnglishWord was called. Not sure if I implemented correctly though.

//deconstruct that deletes model object.
Translator::~Translator() {
    delete model;
}


// Helper function to check if a character is a vowel, assuming this is not part of Model
//I assume I am allowed to use this, as you said we could use private helper functions
bool Translator::isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string Translator::translateEnglishWord(string word)
{
    
    string translatedWord;
    for (char c : word) {
        if (isalpha(c)) {
            if (isVowel(c) || !isalpha(c)) {
                // Use model objects translateSingleVowel for vowels
                translatedWord += model->translateSingleVowel(c);
            } else {
                // Use model objects translateSingleConsonant for consonants
                translatedWord += model->translateSingleConsonant(c);
            }
        } else {
            // spaces or commas or etc characters are added directly
            translatedWord += c;
        }
    }
    return translatedWord;
}

string Translator::translateEnglishSentence(string sentence) {
    string translatedSentence;
    string currentWord;
    for (size_t i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        if (isalpha(c)) { //if space or , or etc, go into translating word else if statement
            currentWord += c;
        } else {
            if (!currentWord.empty()) {
                translatedSentence += translateEnglishWord(currentWord);
                //clear currentword after appending so room for next word in sentence.
                currentWord.clear();
            }
            translatedSentence += c; // Add space or , or etc.
        }
    }
    if (!currentWord.empty()) {
        translatedSentence += translateEnglishWord(currentWord);
    }
   
    
    
    
    return translatedSentence;
}