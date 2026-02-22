#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "block.h"
#include "crypto.h"

static void calculate_hash(Block* block) {
    char input[1024];

    sprintf(input, "%d%ld%s%s%d",
            block->index,
            block->timestamp,
            block->data,
            block->previous_hash,
            block->nonce);

    sha256(input, block->hash);
}

Block* create_block(int index, const char* data, const char* previous_hash) {
    Block* block = (Block*)malloc(sizeof(Block));

    block->index = index;
    block->timestamp = time(NULL);
    strncpy(block->data, data, sizeof(block->data));
    strncpy(block->previous_hash, previous_hash, 65);
    block->nonce = 0;
    block->next = NULL;

    calculate_hash(block);

    return block;
}

void mine_block(Block* block, int difficulty) {
    char target[65] = {0};

    for(int i = 0; i < difficulty; i++)
        target[i] = '0';

    do {
        block->nonce++;
        calculate_hash(block);
    } while(strncmp(block->hash, target, difficulty) != 0);

    printf("Block mined: %s\n", block->hash);
}