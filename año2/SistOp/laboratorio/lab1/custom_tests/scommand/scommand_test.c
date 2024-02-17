#include "../../command.h"
#include <assert.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compilation and execution options:
// - To view program output and fails
//      gcc scommand_test.c ../../command.c ../../strextra.c -o ejecutable_scommand_test `pkg-config
//      --cflags --libs glib-2.0` && ./ejecutable_scommand_test < scommand_test_input.in
// - To view memory leaks and heaps (only for us)
//      gcc scommand_test.c ../../command.c ../../strextra.c -o ejecutable_scommand_test `pkg-config
//      --cflags --libs glib-2.0` && valgrind --leak-check=full ./ejecutable_scommand_test <
//      scommand_test_input.in
// - To view memory leaks and all heaps information
//      gcc scommand_test.c ../../command.c ../../strextra.c -o ejecutable_scommand_test `pkg-config
//      --cflags --libs glib-2.0` && valgrind --leak-check=full -v --track-origins=yes
//      ./ejecutable_scommand_test < scommand_test_input.in

#define SIZE 28

int main(void) {
    scommand test = scommand_new();

    char *a[SIZE];
    for (unsigned int i = 0; i < SIZE; i++) {
        a[i] = malloc(sizeof(char) * 1024);
        scanf("%s", &(*a[i]));
        if (i < 26) {
            scommand_push_back(test, a[i]);
        } else if (i == 26) {
            scommand_set_redir_in(test, a[i]);
        } else if (i == 27) {
            scommand_set_redir_out(test, a[i]);
        }
    }

    char *representation = scommand_to_string(test);
    printf("%s\n", representation);
    free(representation);
    representation = NULL;

    test = scommand_destroy(test);
    return 0;
}