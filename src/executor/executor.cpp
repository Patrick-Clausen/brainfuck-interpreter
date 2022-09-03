#include <array>
#include <iostream>

#include "executor.hpp"

void jumpIterForward(std::vector<Symbol>::iterator &iter);
void jumpIterBackward(std::vector<Symbol>::iterator &iter);

void execute(std::vector<Symbol> symbols)
{
    auto symbol_iter = symbols.begin();

    std::array<char, 30000> data_store;
    auto data_store_iter = data_store.begin();

    while (symbol_iter != symbols.end())
    {
        switch (*symbol_iter)
        {
        case INCREMENT_POINTER:
            data_store_iter++;
            break;
        case DECREMENT_POINTER:
            data_store_iter--;
            break;
        case INCREMENT_DATA:
            (*data_store_iter)++;
            break;
        case DECREMENT_DATA:
            (*data_store_iter)--;
            break;
        case OUTPUT_DATA:
            std::cout << (*data_store_iter);
            break;
        case INPUT_DATA:
            *data_store_iter = getchar();
            break;
        case JUMP_FORWARD:
            if (*data_store_iter == 0) {
                jumpIterForward(symbol_iter);
            }
            break;
        case JUMP_BACKWARD:
            if (*data_store_iter != 0) {
                jumpIterBackward(symbol_iter);    
            }
            break;
        }
        symbol_iter++;
    }
}

void jumpIterForward(std::vector<Symbol>::iterator &iter)
{
    int depth = 1;
    while (depth > 0)
    {
        iter++;
        Symbol current = (*iter);

        switch (current)
        {
        case JUMP_FORWARD:
            depth++;
            break;
        case JUMP_BACKWARD:
            depth--;
            break;
        }
    }
}

void jumpIterBackward(std::vector<Symbol>::iterator &iter)
{
    int depth = 1;
    while (depth > 0)
    {
        iter--;
        Symbol current = (*iter);

        switch (current)
        {
        case JUMP_FORWARD:
            depth--;
            break;
        case JUMP_BACKWARD:
            depth++;
            break;
        }
    }
}