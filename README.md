# vigenere-encoder-cpp

Vigenere cipher encode/encoder with C++.

## Install - Linux

```bash
git clone https://github.com/miguelzacca/vigenere-encoder-cpp.git
chmod +x ~/vigenere-encoder-cpp/main-deb ~/vigenere-encoder-cpp/config.sh
~/vigenere-encoder-cpp/config.sh
```

## Install - Windows

```cmd
git clone https://github.com/miguelzacca/vigenere-encoder-cpp.git
%HOMEPATH%/vigenere-encoder-cpp/config.bat
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

File (Linux):

```bash
vigenere -e "$(cat myfile)" mykey
```

```bash
vigenere -e "$(cat myfile)" mykey >> cipherFile
```
