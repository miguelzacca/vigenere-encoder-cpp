#!/bin/bash

if ! grep -q "^alias vigenere=" ~/.bashrc; then
    echo "alias vigenere='~/vigenere-encoder-cpp/main'" >>~/.bashrc
    source ~/.bashrc
    echo "INFO: ~/.bashrc updated successfully."
fi
