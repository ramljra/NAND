#ifndef NAND_H
#define NAND_H

#define BLOCKS 16
#define PAGES_PER_BLOCK 8

void nand_init();
int nand_write(int block, int page, int data);
int nand_read(int block, int page);
void nand_erase(int block);

#endif
