#include <stdio.h>
#include <iostream>
#include <fstream>
#include "lexer.h"

Lexer::Lexer(std::string &file_name) {
    char c = 0;
    FILE* input_file = fopen(file_name.c_str(),"r");
    if(input_file == nullptr) {
        std::cout << "[Error] Script " << input_file << " could not be read\n";
    } else {
        c = getc(input_file);
        while(c != EOF) {
            std::cout << c;
            c = getc(input_file);
        }
        std::cout << "\n";
        fclose(input_file);
    }
}