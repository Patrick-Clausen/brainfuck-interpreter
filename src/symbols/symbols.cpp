#include "symbols.hpp"

std::vector<Symbol> convertToSymbols(std::string bf_string) {
    std::vector<Symbol> symbols;
    
    for(char c: bf_string) {
        switch (c) {
            case '>':
                symbols.push_back(INCREMENT_POINTER);
                break;
            case '<':
                symbols.push_back(DECREMENT_POINTER);
                break;
            case '+':
                symbols.push_back(INCREMENT_DATA);
                break;
            case '-':
                symbols.push_back(DECREMENT_DATA);
                break;
            case '.':
                symbols.push_back(OUTPUT_DATA);
                break;
            case ',':
                symbols.push_back(INPUT_DATA);
                break;
            case '[':
                symbols.push_back(JUMP_FORWARD);
                break;
            case ']':
                symbols.push_back(JUMP_BACKWARD);
                break;
        }
    }
    
    return symbols;
}