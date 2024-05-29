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

    for (size_t index = 0; index < lowerInput.size(); index++)
    {
        if (lowerInput[index] == ' ')
        {
            output += ' ';
            continue;
        }
        const int inputIndex = letters.find(lowerInput[index]);
        const int keyIndex = letters.find(key[index % key.size()]);
        const int newIndex = (inputIndex + keyIndex) % letters.size();
        output += letters[newIndex];
    }

    return output;
}

std::string decode(const std::string &input, const std::string &key)
{
    const std::string lowerInput = toLowerCase(input);

    std::string output;

    for (size_t index = 0; index < lowerInput.size(); index++)
    {
        if (lowerInput[index] == ' ')
        {
            output += ' ';
            continue;
        }
        const int inputIndex = letters.find(lowerInput[index]);
        const int keyIndex = letters.find(key[index % key.size()]);
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
        std::cerr << e.what() << std::endl;

        return -1;
    }
}
