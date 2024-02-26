#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>


FileProcessor::FileProcessor() { //construct
    translator = new Translator();
}

FileProcessor::~FileProcessor() { //destruct
    
   delete translator;
}

void FileProcessor::processFile(std::string inputFilePath, std::string outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    //if the file is not open, or output file not open, give error message
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    // make html doc with header (where you click on tab) named Rövarspråket Translation
    outputFile << "<!DOCTYPE html>\n<html>\n<head>\n<title>Rövarspråket Translation</title>\n</head>\n<body>\n";

    
    std::string line;
    while (getline(inputFile, line)) {
        // Translate line
        std::string translatedLine = translator->translateEnglishSentence(line);

        // Write the original and translated lines to an html file
         // make translated line in italics
         // original line bolded
        outputFile << "<p><b>" << line << "</b><br>\n<i>" << translatedLine << "</i></p>\n";
    }

    // End of html doc
    outputFile << "</body>\n</html>";

    //close files
    
    inputFile.close();
    outputFile.close();
}
