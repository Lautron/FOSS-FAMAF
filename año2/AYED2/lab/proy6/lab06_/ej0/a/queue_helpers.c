#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue_helpers.h"


void queue_dump(queue q) {
    unsigned int length = queue_size(q);
    fprintf(stdout, "length: %u\n", length);
    fprintf(stdout, "[ ");
    while(!queue_is_empty(q)) {
        fprintf(stdout, "%i", queue_first(q));
        q = queue_dequeue(q);
        if (!queue_is_empty(q)) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}


queue queue_from_file(const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    int res = 0, empty_flag=0;
    res = fscanf(file, "empty: %d", &empty_flag);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    queue q=queue_empty();
    while (!feof(file) && !empty_flag) {
        int value=0;
        res = fscanf(file," %d ", &value);
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        q = queue_enqueue(q, value);
    }
    fclose(file);
    return q;
}

