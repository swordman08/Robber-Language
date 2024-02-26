#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <fstream>
#include "Translator.h"
#include <string> //used std::string instead of just 
// "using namespace std for fileprocessor as using gave me lots of errors.

class FileProcessor {
public:
    FileProcessor(); //construct
    ~FileProcessor(); //dstruct
    void processFile(std::string inputFilePath, std::string outputFilePath);
    
private:
    Translator *translator;
};

#endif // FILEPROCESSOR_H
