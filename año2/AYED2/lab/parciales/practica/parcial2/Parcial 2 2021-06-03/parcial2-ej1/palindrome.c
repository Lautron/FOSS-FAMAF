#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "helpers/stack.h"

static size_t letter_count(char *str) {
    assert(str!=NULL);
    size_t count=0, i=0;
    while (str[i] != '\0') {
        // Increments only if str[i] is not blank
        count += str[i] != ' ';
        i++;
    }
    return count;
}

static char *remove_blanks(char *str, size_t *no_blanks_count) {
    assert(str!=NULL);
    size_t size_noblank=0;
    size_t count=0,i=0;
    char *no_blank=NULL;
    /*
     * Completar
     *
     */
    while (str[i] != '\0') {
        /*
         * Completar
         */
        i++;
    }
    /*
     * Completar
     *
     */
    return no_blank;
}

static void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <phrase-to-check>\n\n"
           "Check if the phrase is a palindrome. Discards blank spaces from the "
           "given phrase when analysis is performed.\n",
           program_name);
}

static char* parse_phrase(int argc, char *argv[]) {
    /* Parse the phrase given by command line argument. */
    char *result=NULL;
    /* Program takes exactly one argument */
    if (argc != 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Use the first argument ass the phrase */
    result = argv[1];
    /* return phrase */
    return result;
}

int main(int argc, char *argv[]) {
    // First parameter is used as phrase
    char *phrase=argv[1];
    //
    bool is_palindrome=true;
    char *phrase_noblank = NULL;
    size_t size_noblank=0;
    // Parse arguments and get the phrase to be analysed
    phrase=parse_phrase(argc, argv);
    // Discard blank spaces
    phrase_noblank = remove_blanks(phrase, &size_noblank);
    // A stack (lifo) needed for checking algorithm
    stack letters_lifo=stack_empty();
    // Save half phrase in the stack
    size_t  i=0, half_size=size_noblank / 2;
    for (i=0; i < half_size; i++) {
        letters_lifo = stack_push(letters_lifo, phrase_noblank[i]);
    }
    if (size_noblank % 2 == 1) {
        i++;  // Skip the middle letter of prhase
    }
    // Simetry check
    while (!stack_is_empty(letters_lifo)) {
        is_palindrome = is_palindrome && stack_top(letters_lifo) == phrase_noblank[i];
        letters_lifo = stack_pop(letters_lifo);
        i++;
    }
    // Check subscript
    assert(i == size_noblank);
    // Destroy stack instance
    letters_lifo = stack_destroy(letters_lifo);
    // Free auxiliar string
    /*
     * Completar
     *
     */
    phrase_noblank = NULL;
    printf(is_palindrome ? "es palíndromo!\n": "no es palíndromo\n");
    return 0;
}
