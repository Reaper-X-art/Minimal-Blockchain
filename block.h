#ifndef BLOCK_H
#define BLOCK_H

#include <time.h>

typedef struct Block {
    int index;
    long timestamp;
    char data[256];
    char previous_hash[65];
    char hash[65];
    int nonce;

    struct Block* next;
} Block;

Block* create_block(int index, const char* data, const char* previous_hash);
void mine_block(Block* block, int difficulty);

#endif