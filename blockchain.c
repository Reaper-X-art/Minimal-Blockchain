#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blockchain.h"

Blockchain* create_blockchain(int difficulty) {
    Blockchain* chain = (Blockchain*)malloc(sizeof(Blockchain));
    chain->difficulty = difficulty;

    chain->head = create_block(0, "Genesis Block", "0");
    mine_block(chain->head, difficulty);

    return chain;
}

void add_block(Blockchain* chain, const char* data) {
    Block* current = chain->head;

    while(current->next != NULL)
        current = current->next;

    Block* new_block = create_block(
        current->index + 1,
        data,
        current->hash
    );

    mine_block(new_block, chain->difficulty);

    current->next = new_block;
}

int is_chain_valid(Blockchain* chain) {
    Block* current = chain->head;

    while(current->next != NULL) {
        Block* next = current->next;

        if(strcmp(current->hash, next->previous_hash) != 0)
            return 0;

        current = current->next;
    }

    return 1;
}

void print_chain(Blockchain* chain) {
    Block* current = chain->head;

    while(current != NULL) {
        printf("\nIndex: %d\n", current->index);
        printf("Timestamp: %ld\n", current->timestamp);
        printf("Data: %s\n", current->data);
        printf("Hash: %s\n", current->hash);
        printf("Prev Hash: %s\n", current->previous_hash);
        printf("Nonce: %d\n", current->nonce);

        current = current->next;
    }
}