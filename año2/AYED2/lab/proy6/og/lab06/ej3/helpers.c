#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "string.h"

#define BUFFER_SIZE 128

char *readline(FILE * file) {
    bool done = false;
    char *result = NULL, *read_from = NULL;
    char *alloc_result = NULL, *fgets_result = NULL;
    unsigned int size = BUFFER_SIZE;
    size_t result_len = 0;

    /* char *fgets(char *s, int size, FILE *stream);

       fgets() reads in at most one less than size characters from stream and
       stores them into the buffer pointed to by s. Reading stops after an EOF
       or a newline. If a newline is read, it is stored into the buffer. A
       terminating null byte ('\0') is stored after the last character in the
       buffer. */

    while (!done) {
        /* need to use 2 pointers to avoid leaking resources from 'result' */
        alloc_result = realloc(result, size * sizeof(char));
        if (alloc_result == NULL) {
            /* realloc failed, yet we need to free the memory from 'result' */
            free(result);
            result = NULL;
            done = true;
        } else {
            /* point 'result' to the newly allocated memory */
            result = alloc_result;

            /* point 'read_from' to the unused memory space */
            read_from = result + result_len;

            /* read from 'file' up to 'size - result_len' */
            fgets_result = fgets(read_from, size - result_len, file);
            if (fgets_result == NULL) {
                free(result);
                result = NULL;
                done = true;
            } else {
                /* check if the user entered a newline */
                result_len = strlen(result);
                assert(result_len < size);
                if (feof(file)) {
                    done = true;
                } else if (result[result_len - 1] == '\n') {
                    /* Remove trailing '\n' */
                    result[result_len - 1] = '\0';
                    assert(strlen(result) == result_len - 1);
                    done = true;
                }
            }
        }
        size = size * 2;
    }

    /* will return NULL if something went wrong */
    assert(result == NULL || result[strlen(result)] != '\n');
    return (result);
}

char *readline_from_stdin(void) {
    return (readline(stdin));
}

string readstring_from_stdin() {
    char *str = readline_from_stdin();
    string readed = string_create(str);
    free(str);
    return (readed);
}
