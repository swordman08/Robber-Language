#ifndef MODEL_H
#define MODEL_H
#include <iostream>


using namespace std;


class Model {
public:
    Model();
    ~Model();
    string translateSingleConsonant(char c);
    string translateSingleVowel(char c);
    
private:
    bool isVowel(char c);

};



#endif // MODEL_H