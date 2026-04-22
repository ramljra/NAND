#include "nvme.h"
#include "ftl.h"

#define Q_DEPTH 8

typedef struct {
    int lba;
    int data;
} cmd_t;

static cmd_t sq[Q_DEPTH];
static int head = 0, tail = 0;

void nvme_submit_write(int lba, int data) {
    sq[tail].lba = lba;
    sq[tail].data = data;
    tail = (tail + 1) % Q_DEPTH;
}

void nvme_process() {
    while (head != tail) {
        ftl_write(sq[head].lba, sq[head].data);
        head = (head + 1) % Q_DEPTH;
    }
}
