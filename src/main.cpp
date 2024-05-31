#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

static const std::string LETTERS = "abcdefghijklmnopqrstuvwxyz";

void toLowerCase(std::string &str)
{
  for (char &c : str)
  {
    c = std::tolower(c);
  }
}

std::string process(const std::string &input, const std::string &key, bool encode)
{
  std::string output;
  output.reserve(input.size());

  for (std::size_t i = 0; i < input.size(); ++i)
  {
    const std::size_t inputIndex = LETTERS.find(input[i]);
    if (inputIndex == std::string::npos)
    {
      output += input[i];
      continue;
    }

    const std::size_t keyIndex = LETTERS.find(key[i % key.size()]);
    if (keyIndex == std::string::npos)
    {
      throw std::invalid_argument("Key contains invalid characters.");
    }

    const std::size_t calc = encode ? inputIndex + keyIndex : inputIndex - keyIndex + LETTERS.size();
    output += LETTERS[calc % LETTERS.size()];
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

    std::string input = argv[2];
    std::string key = argv[3];

    toLowerCase(input);
    toLowerCase(key);

    if (std::string(argv[1]) == "-e")
    {
      std::cout << process(input, key, true) << std::endl;
      return 0;
    }

    if (std::string(argv[1]) == "-d")
    {
      std::cout << process(input, key, false) << std::endl;
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
