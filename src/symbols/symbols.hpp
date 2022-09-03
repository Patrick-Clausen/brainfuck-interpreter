#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <vector>
#include <string>

enum Symbol {
    INCREMENT_POINTER,
    DECREMENT_POINTER,
    INCREMENT_DATA,
    DECREMENT_DATA,
    OUTPUT_DATA,
    INPUT_DATA,
    JUMP_FORWARD,
    JUMP_BACKWARD
};

std::vector<Symbol> convertToSymbols(std::string bf_string);
#endif