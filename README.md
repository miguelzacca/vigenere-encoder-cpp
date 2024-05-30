# vigenere-encoder-cpp

Vigenere cipher encode/encoder with C++. Linux only.

## Install

```bash
git clone https://github.com/miguelzacca/vigenere-encoder-cpp
chmod +x ~/vigenere-encoder-cpp/main
chmod +x ~/vigenere-encoder-cpp/config.sh
~/vigenere-encoder-cpp/config.sh
```

## Use

```bash
vigenere <-e|-d> <TEXT> <KEY>
```

- `-e` to encode
- `-d` to decode

## Example

Simple:

```bash
vigenere -e mysecret mykey
```

```bash
vigenere -e "my secret" mykey
```

File:

```bash
vigenere -e "$(cat myfile)" mykey
```

```bash
vigenere -e "$(cat myfile)" mykey >> cipherFile
```
