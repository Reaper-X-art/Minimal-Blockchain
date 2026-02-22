#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

typedef struct {
    Block* head;
    int difficulty;
} Blockchain;

Blockchain* create_blockchain(int difficulty);
void add_block(Blockchain* chain, const char* data);
int is_chain_valid(Blockchain* chain);
void print_chain(Blockchain* chain);

#endif