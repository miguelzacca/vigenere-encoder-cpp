#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <cctype>

const std::string letters = "abcdefghijklmnopqrstuvwxyz";

std::string toLowerCase(const std::string &str)
{
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

std::string encode(const std::string &input, const std::string &key)
{
    const std::string lowerInput = toLowerCase(input);

    std::string output;
    output.reserve(lowerInput.size());

    for (std::size_t index = 0; index < lowerInput.size(); ++index)
    {
        if (lowerInput[index] == ' ')
        {
            output += ' ';
            continue;
        }
        const std::size_t inputIndex = letters.find(lowerInput[index]);
        const std::size_t keyIndex = letters.find(key[index % key.size()]);
        if (inputIndex == std::string::npos || keyIndex == std::string::npos)
        {
            throw std::invalid_argument("Input or key contains invalid characters.");
        }
        const std::size_t newIndex = (inputIndex + keyIndex) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

std::string decode(const std::string &input, const std::string &key)
{
    const std::string lowerInput = toLowerCase(input);

    std::string output;
    output.reserve(lowerInput.size());

    for (std::size_t index = 0; index < lowerInput.size(); ++index)
    {
        if (lowerInput[index] == ' ')
        {
            output += ' ';
            continue;
        }
        const std::size_t inputIndex = letters.find(lowerInput[index]);
        const std::size_t keyIndex = letters.find(key[index % key.size()]);
        if (inputIndex == std::string::npos || keyIndex == std::string::npos)
        {
            throw std::invalid_argument("Input or key contains invalid characters.");
        }
        const std::size_t newIndex = (inputIndex + letters.size() - keyIndex) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 4)
        {
            throw std::invalid_argument("Invalid number of arguments.");
        }

        const std::string input = argv[2];
        const std::string key = argv[3];

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

        throw std::invalid_argument("Invalid option.");
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << "USE: vigenere <-e|-d> <TEXT> <KEY>" << std::endl;
        return -1;
    }
}
