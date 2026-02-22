#include <stdio.h>
#include "blockchain.h"

int main() {
    Blockchain* chain = create_blockchain(4);

    add_block(chain, "First transaction");
    add_block(chain, "Second transaction");
    add_block(chain, "Third transaction");

    print_chain(chain);

    if(is_chain_valid(chain))
        printf("\nBlockchain is VALID\n");
    else
        printf("\nBlockchain is INVALID\n");

    return 0;
}