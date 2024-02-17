/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "pqueue.h"

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Read patients arrivals with an associated priority and return the"
           "order in wich the patients are seen.\n"
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

pqueue pqueue_from_file(const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    int res = 0, empty_flag=0;
    unsigned int min_allowed_priority=0u;
    res = fscanf(file,"min_priority: %u\n", &min_allowed_priority);
    if(res != 1)
    {
        fprintf(stderr, "pqueue min allowed priority missing\n");
        exit(EXIT_FAILURE);
    }
    pqueue q = pqueue_empty(min_allowed_priority);
    while (!feof(file) && !empty_flag) {
        pqueue_elem patient_id = 0;
        unsigned int priority = 0;
        res = fscanf(file," %u %u ", &patient_id, &priority);
        if (res != 2) {
            fprintf(stderr, "Invalid list of patient with priority.\n");
            exit(EXIT_FAILURE);
        }
        q = pqueue_enqueue(q, patient_id, priority);
    }
    fclose(file);
    return q;
}

void pqueue_dump(pqueue q) {
    unsigned int length = pqueue_size(q);
    fprintf(stdout, "length: %u\n", length);
    fprintf(stdout, "[ ");
    while(!pqueue_is_empty(q)) {
        fprintf(stdout, "(%u, %u)", pqueue_peek(q), pqueue_peek_priority(q));
        q = pqueue_dequeue(q);
        if (!pqueue_is_empty(q)) {
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
    pqueue q = pqueue_from_file(filepath);
    pqueue q2 = pqueue_from_file(filepath);
    /* call the function for show the priority queue of patients */
    pqueue_dump(q);

    /* destroy instance of dequeue */
    q = pqueue_destroy(q);
    q2 = pqueue_destroy(q2);

    return (EXIT_SUCCESS);
}
