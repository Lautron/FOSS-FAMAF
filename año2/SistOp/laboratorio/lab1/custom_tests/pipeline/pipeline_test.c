#include "../../command.h"
#include <assert.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compilation and execution options:
// - To view program output and fails
//      gcc pipeline_test.c ../../command.c ../../strextra.c -o ejecutable_pipeline_test `pkg-config
//      --cflags --libs glib-2.0` && ./ejecutable_pipeline_test < pipeline_test_input.in
// - To view memory leaks and heaps (only for us)
//      gcc pipeline_test.c ../../command.c ../../strextra.c -o ejecutable_pipeline_test `pkg-config
//      --cflags --libs glib-2.0` && valgrind --leak-check=full ./ejecutable_pipeline_test <
//      pipeline_test_input.in
// - To view memory leaks and all heaps information
//      gcc pipeline_test.c ../../command.c ../../strextra.c -o ejecutable_pipeline_test `pkg-config
//      --cflags --libs glib-2.0` && valgrind --leak-check=full -v --track-origins=yes
//      ./ejecutable_pipeline_test < pipeline_test_input.in

#define SIZE 3

int main(void) {
    pipeline test = pipeline_new();
    for (unsigned int j = 0; j < 28; j++) {
        scommand test1 = scommand_new();

        char *a[SIZE];
        for (unsigned int i = 0; i < SIZE; i++) {
            a[i] = malloc(sizeof(char) * 1024);
            scanf("%s", &(*a[i]));
            if (i < SIZE - 2) {
                scommand_push_back(test1, a[i]);
            } else if (i == SIZE - 2) {
                scommand_set_redir_in(test1, a[i]);
            } else if (i == SIZE - 1) {
                scommand_set_redir_out(test1, a[i]);
            }
        }

        char *representation = scommand_to_string(test1);
        printf("%s\n", representation);
        free(representation);
        representation = NULL;

        pipeline_push_back(test, test1);
    }
    pipeline_pop_front(test);
    pipeline_set_wait(test, false);
    printf("length --> %u\n", pipeline_length(test));
    char *representation = pipeline_to_string(test);
    printf("%s\n", representation);
    free(representation);
    representation = NULL;

    test = pipeline_destroy(test);
    return 0;
}