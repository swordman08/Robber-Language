#include "Model.h"
#include <cctype> // for tolower and isalpha

using namespace std;

Model::Model() {}

Model::~Model() {

}

// Helper function to check if a character is a vowel or nah.
bool Model::isVowel(char c) {
    c = tolower(c); // so I dont need double the cases in return.
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string Model::translateSingleConsonant(char c) {
    if (!isalpha(c) || isVowel(c)) {
        return string(1, c);
    }
    // double the consonant and insert an o in between
    char lowerC = tolower(c); // Convert to lowercase, if we are supposed to keep repeating letter capitlized when consonant is capital, than idk deduct me. 
    return string(1, c) + 'o' + lowerC;
}

string Model::translateSingleVowel(char c) {
    // Vowels are returned
    return string(1, c);
}