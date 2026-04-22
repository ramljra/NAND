#include <stdio.h>
#include "nand.h"
#include "ftl.h"
#include "nvme.h"

int main() {
    nand_init();
    ftl_init();

    nvme_submit_write(1, 100);
    nvme_submit_write(2, 200);

    nvme_process();

    printf("Read LBA1: %d\n", ftl_read(1));
    printf("Read LBA2: %d\n", ftl_read(2));

    return 0;
}
