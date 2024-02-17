/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "pstack.h"

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Read elements arrivals with an associated priority and return the"
           "order in wich are popped from the stack.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

pstack pstack_from_file(const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    int res = 0, empty_flag=0;
    pstack s = pstack_empty();
    while (!feof(file) && !empty_flag) {
        pstack_elem patient_id = 0;
        unsigned int priority = 0;
        res = fscanf(file," %u %u ", &patient_id, &priority);
        if (res != 2) {
            fprintf(stderr, "Invalid list of patient with priority.\n");
            exit(EXIT_FAILURE);
        }
        s = pstack_push(s, patient_id, priority);
    }
    fclose(file);
    return s;
}

void dump_priority(priority_t p) {
    if (p==worst) {
        fprintf(stdout, "worst priority");
    } else if (p==low) {
        fprintf(stdout, "low priority");
    } else if (p==normal) {
        fprintf(stdout, "normal priority");
    } else if (p==high) {
        fprintf(stdout, "high priority");
    } else if (p==best) {
        fprintf(stdout, "best priority");
    } else {
        fprintf(stdout, "not valid priority");
    }
}

void pstack_dump(pstack s) {
    unsigned int length = pstack_size(s);
    fprintf(stdout, "length: %u\n", length);
    fprintf(stdout, "[ ");
    while(!pstack_is_empty(s)) {
        fprintf(stdout, "(%u, ", pstack_top(s));
        dump_priority(pstack_top_priority(s));
        fprintf(stdout, ")");
        
        s = pstack_pop(s);
        if (!pstack_is_empty(s)) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* get the dequeue from the file */
    pstack s = pstack_from_file(filepath);

    /* call the function for show the priority stack elements */
    pstack_dump(s);

    /* destroy instance of pstack */
    s = pstack_destroy(s);

    return (EXIT_SUCCESS);
}
