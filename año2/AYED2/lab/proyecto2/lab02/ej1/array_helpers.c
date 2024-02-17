#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void array_copy(int copy[], int array[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        copy[i] = array[i];
    }
}

unsigned int array_value_count(int a[], unsigned int length, int value) {
    unsigned int count = 0u;
    for (unsigned int i = 0u; i < length; ++i) {
        if (a[i] == value) {
            ++count;
        }
    }
    return count;
}

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "%u\n", length);
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}


bool array_is_permutation_of(int a[], int b[], unsigned int length) {
    unsigned int i = 0u;
    bool result = true;
    while (i < length && result) {
        unsigned int a_count = array_value_count(a, length, a[i]);
        unsigned int b_count = array_value_count(b, length, a[i]);
        result = (a_count == b_count);
        i++;
    }
    return result;
}

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    if (size > max_size) {
        fprintf(stderr, "Allowed size is %d.\n", max_size);
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %d ", &(array[i]));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i;
    }
    fclose(file);
    return size;
}
