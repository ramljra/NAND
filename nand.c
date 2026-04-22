#include <stdio.h>
#include "nand.h"

static int nand[BLOCKS][PAGES_PER_BLOCK];
static int valid[BLOCKS][PAGES_PER_BLOCK];

void nand_init() {
    for (int i = 0; i < BLOCKS; i++)
        for (int j = 0; j < PAGES_PER_BLOCK; j++)
            valid[i][j] = 0;
}

int nand_write(int block, int page, int data) {
    if (valid[block][page]) return -1;
    nand[block][page] = data;
    valid[block][page] = 1;
    return 0;
}

int nand_read(int block, int page) {
    if (!valid[block][page]) return -1;
    return nand[block][page];
}

void nand_erase(int block) {
    for (int i = 0; i < PAGES_PER_BLOCK; i++)
        valid[block][i] = 0;
}
