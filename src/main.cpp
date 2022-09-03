//
// Created by Patrick Clausen on 03/09/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "A single argument, containing the path to a brainfuck file, should be given." << std::endl;
        return -1;
    }

    std::string path(argv[1]);
    std::cout << path << std::endl;

    std::ifstream brainfuck_file(path);

    if (!brainfuck_file.is_open())
    {
        std::cerr << "Unable to open specified file" << std::endl;
        return -2;
    }

    std::stringstream string_stream;

    while (brainfuck_file.good())
    {
        char c = brainfuck_file.get();
        string_stream << c;
    }

    std::cout << string_stream.str() << std::endl;

    return 0;
}