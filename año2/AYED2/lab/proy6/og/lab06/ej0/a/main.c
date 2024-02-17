/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "queue.h"
#include "queue_helpers.h"

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads a queue given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain the string \"empty: \" followed by a number"
           " that indicates with 0 that the content of the file is NOT EMPTY, and"
           " any other value indicates that there is no data in the file.\n"
           " * The second line must contain the members of the queue"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "empty: <empty_flag>\n"
           "<elem 1> <elem 2> ... <elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    // parse the file and returns the loaded queue
    queue q=queue_from_file(filepath);
    
    /*dumping the queue */
    queue_dump(q);
    
    // 
    // COMPLETAR: Liberar la memoria usada por <q>
    //
    return EXIT_SUCCESS;
}

