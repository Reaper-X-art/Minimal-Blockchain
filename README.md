# Minimal Blockchain in C

This project is a **minimal blockchain implemented entirely in C**.  
It demonstrates core blockchain concepts including proof-of-work, cryptographic hashing (SHA-256), immutability, and dynamic memory usage with linked lists.

## Features
- Genesis block and dynamic addition of new blocks
- Each block contains index, timestamp, data, hash, previous hash, and nonce
- Proof-of-Work mining with adjustable difficulty
- Linked-list based blockchain structure
- Chain validation function

## Requirements
- GCC (MinGW / Linux / macOS)
- OpenSSL library

## How to Compile
```bash


gcc main.c blockchain.c block.c crypto.c -o blockchain -lssl -lcrypto
./blockchain.exe
