/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "dict.h"
#include "dict_helpers.h"
#include "helpers.h"
#include "string.h"

#define ADD    'a'
#define REMOVE 'r'
#define DUMP   'u'
#define EMPTY  'e'
#define LOAD   'l'
#define SEARCH 's'
#define REPLACE 'c'
#define SHOW   'h'
#define SIZE   'z'
#define QUIT   'q'

#define RESULT_PREFIX "\t-> "

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s\n\n", program_name);
}

char print_menu(void) {
    char result = '\0';
    char *line = NULL;

    printf("\nChoose what you want to do. Options are:\n"
           "\n"
           "\t**************************************************************\n"
           "\t* z: Size of the dictionary                                  *\n"
           "\t* s: Search for a definition in the dict                     *\n"
           "\t* a: Add a new word to the dict                              *\n"
           "\t* r: Remove a word from the dict                             *\n"
           "\t* c: Change a definition to the dict                         *\n"
           "\t* e: Empty the dict                                          *\n"
           "\t* h: Show the dict in stdout                                 *\n"
           "\t* l: Load the dict from a file                               *\n"
           "\t* u: Dump the dict to a file                                 *\n"
           "\t* q: Quit                                                    *\n"
           "\t**************************************************************\n"
           "\nPlease enter your choice: ");

    line = readline_from_stdin();
    if (line != NULL) {
        result = line[0];
    }

    free(line);
    return (result);
}

bool is_valid_option(char option) {
    bool result = false;

    result = (option == ADD || option == REMOVE ||
              option == DUMP || option == EMPTY || option == LOAD ||
              option == SEARCH || option == SHOW || option == SIZE ||
              option == QUIT);

    return (result);
}

string get_input(const char *message) {
    string result = NULL;
    printf("\t%s: ", message);
    result = readstring_from_stdin();
    assert(result != NULL);
    return (result);
}

dict_t on_add(dict_t current) {
    string definition = NULL;
    string word = NULL;
    word = get_input("Please enter the word to add into the dict");
    if (dict_exists(current, word)) {
        printf(RESULT_PREFIX "The word is already in the dict.\n");
        word = string_destroy(word);
    } else {
        definition = get_input("Please enter the definition");
        current = dict_add(current, word, definition);
        printf(RESULT_PREFIX "The word and definition were added.\n");
    }
    return (current);
}

dict_t on_replace(dict_t current) {
    string definition = NULL;
    string word = NULL;
    word = get_input("Please enter the word to replace in the dict");
    if (!dict_exists(current, word)) {
        printf(RESULT_PREFIX "The word does not exist in the dict.\n");
        word = string_destroy(word);
    } else {
        definition = get_input("Please enter the new definition");
        current = dict_add(current, word, definition);
        printf(RESULT_PREFIX "The definition was replaced.\n");
    }
    return (current);
}

dict_t on_remove(dict_t current) {
    string word =
            get_input("Please enter the word to delete from the dict");
    if (!dict_exists(current, word)) {
        printf(RESULT_PREFIX "The word does not exist in the dict.\n");
    } else {
        current = dict_remove(current, word);
        printf(RESULT_PREFIX "The word was removed.\n");
    }
    word = string_destroy(word);
    return (current);
}

dict_t on_load(dict_t current) {
    string filename
            = get_input("Please enter the filename to load the dict from");
    dict_t other = dict_from_file(filename);
    if (other == NULL) {
        printf("Can not load dict from filename %s\n", string_ref(filename));
    } else {
        printf(RESULT_PREFIX "The dictionary was successfully loaded.\n");
        current = dict_destroy(current);    /* destroy current */
        current = other;
    }
    filename = string_destroy(filename);
    return (current);
}

void on_dump(dict_t current) {
    string filename = get_input("Please enter the filename to dump the file");
    dict_to_file(current, filename);
    filename = string_destroy(filename);
    printf(RESULT_PREFIX "The dictionary was successfully dumped.\n");
}

dict_t on_empty(dict_t current) {
    current = dict_remove_all(current);
    printf(RESULT_PREFIX "All words were removed\n");
    return (current);
}

void on_search(dict_t current) {
    string definition = NULL;
    string word = NULL;
    word = get_input("Please enter the word to search in the dict");
    definition = dict_search(current, word);
    if (definition == NULL) {
        printf(RESULT_PREFIX "The word does not exist in the dict\n");
    } else {
        printf(RESULT_PREFIX "The definition of \"%s\" is : \"%s\"\n",
               string_ref(word), string_ref(definition));
    }
    word = string_destroy(word);
}

void on_size(dict_t current) {
    printf(RESULT_PREFIX "The size of the dict is %u\n", dict_length(current));
}

int main(void) {
    char option = '\0';
    dict_t current = dict_empty();
    /* print a simple menu and do the requested operations */
    do {
        option = print_menu();
        switch (option) {
            case ADD:
                current = on_add(current);
                break;
            case REMOVE:
                current = on_remove(current);
                break;
            case REPLACE:
                current = on_replace(current);
                break;
            case DUMP:
                on_dump(current);
                break;
            case EMPTY:
                current = on_empty(current);
                break;
            case LOAD:
                current = on_load(current);
                break;
            case SEARCH:
                on_search(current);
                break;
            case SHOW:
                dict_dump(current, stdout);
                break;
            case SIZE:
                on_size(current);
                break;
            case QUIT:
                current = dict_destroy(current);
                printf(RESULT_PREFIX "Exiting.\n");
                return (EXIT_SUCCESS);
            default:
                printf("\n\"%c\" is invalid. Please choose a valid "
                       "option.\n\n", option);
        }
    } while (option != QUIT);
    return (EXIT_SUCCESS);
}
