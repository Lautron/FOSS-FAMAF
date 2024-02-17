#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./solve-hanoi <disk-count>\n");
        exit(EXIT_FAILURE);
    }
    int count = atoi(argv[1]);
    if (count < 0) {
        printf("Negative disk-count is not allowed\n");
        exit(EXIT_FAILURE);
    }
    if (count > 20) {
        printf("> 20 is too slow!\n");
        exit(EXIT_FAILURE);
    }
    hanoi_t hanoi = hanoi_init(count);
    hanoi_print(hanoi);
    hanoi_solve(hanoi);
    hanoi = hanoi_destroy(hanoi);
    return 0;
}
