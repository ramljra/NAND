#include <stdio.h>
#include "ftl.h"
#include "nand.h"

#define MAX_LBA 64

typedef struct {
    int block;
    int page;
} PBA;

static PBA map_table[MAX_LBA];

void ftl_init() {
    for (int i = 0; i < MAX_LBA; i++) {
        map_table[i].block = -1;
        map_table[i].page = -1;
    }
}

void ftl_write(int lba, int data) {
    int block = lba % BLOCKS;
    int page  = lba % PAGES_PER_BLOCK;

    if (nand_write(block, page, data) != 0) {
        printf("FTL: Write failed at B%d P%d\n", block, page);
        return;
    }

    map_table[lba].block = block;
    map_table[lba].page  = page;
}

int ftl_read(int lba) {
    if (map_table[lba].block == -1) return -1;

    return nand_read(map_table[lba].block,
                     map_table[lba].page);
}
