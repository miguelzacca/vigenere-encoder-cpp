#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

const std::string letters = "abcdefghijklmnopqrstuvwxyv";

int handleKeyIndex(const std::string key, const int index)
{
    const int newKeyIndex = key[index] ? key[index] : key[index % key.size()];
    return newKeyIndex;
}

std::string encode(const std::string input, const std::string key)
{
    std::string output;

    for (int index = 0; index < input.size(); index++)
    {
        const int inputIndex = letters.find(input[index]);
        const int keyIndex = letters.find(handleKeyIndex(key, index));
        const int newIndex = (inputIndex + keyIndex) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

std::string decode(const std::string input, const std::string key)
{
    std::string output;

    for (int index = 0; index < input.size(); index++)
    {
        const int inputIndex = letters.find(input[index]);
        const int keyIndex = letters.find(handleKeyIndex(key, index));
        const int newIndex = (inputIndex - keyIndex + letters.size()) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

void config()
{
    system("chmod +x ~/vigenere-encoder-cpp/config.sh");
    system("~/vigenere-encoder-cpp/config.sh");
}

int main(int argc, char *argv[])
{
    try
    {
        config();

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
