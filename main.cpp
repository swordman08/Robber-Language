#include "FileProcessor.h"

int main(int argc, char** argv) {
    FileProcessor processor; //object of fileProcessor initialized.
    processor.processFile("input.txt", "output.html"); //name of input and output files.
    return 0; //end main by return
}