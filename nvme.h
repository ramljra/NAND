#ifndef NVME_H
#define NVME_H

void nvme_submit_write(int lba, int data);
void nvme_process();

#endif
