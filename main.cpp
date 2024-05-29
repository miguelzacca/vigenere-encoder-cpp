#include <iostream>
#include <string>
#include <stdexcept>

std::string letters = "abcdefghijklmnopqrstuvwxyv";

std::string encode(std::string input, std::string key)
{
    std::string output;

    for (int i = 0; i < input.size(); i++)
    {
        const int inputIndex = letters.find(input[i]);
        const int keyIndex = letters.find(key[i] ? key[i] : key[i % key.size()]);
        const int newIndex = (inputIndex + keyIndex) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

std::string decode(std::string input, std::string key)
{
    std::string output;

    for (int i = 0; i < input.size(); i++)
    {
        const int inputIndex = letters.find(input[i]);
        const int keyIndex = letters.find(key[i] ? key[i] : key[i % key.size()]);
        const int newIndex = (inputIndex - keyIndex + letters.size()) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

int main(int argc, char *argv[])
{
    try
    {
        const std::string input = std::string(argv[2]);
        const std::string key = std::string(argv[3]);

        if (std::string(argv[1]) == "-e")
        {
            std::cout << encode(input, key) << std::endl;
            return 0;
        }

        if (std::string(argv[1]) == "-d")
        {
            std::cout << decode(input, key) << std::endl;
            return 0;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR: syntax error." << std::endl;
        std::cerr << "USE: vigenere <-e|-d> <TEXT> <KEY>" << std::endl;
    }
}
