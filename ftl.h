#ifndef FTL_H
#define FTL_H

void ftl_init();
void ftl_write(int lba, int data);
int ftl_read(int lba);

#endif
