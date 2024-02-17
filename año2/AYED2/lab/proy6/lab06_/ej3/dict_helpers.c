#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "helpers.h"
#include "string.h"


dict_t dict_from_file(string filename) {
    char* word = NULL;
    char* def = NULL;
    dict_t result = NULL;
    FILE *fd = NULL;
    char *line = NULL;
    fd = fopen(string_ref(filename), "r");
    if (fd != NULL) {
        /* filename is a existing file, so create the empty dict */
        result = dict_empty();
        while (!feof(fd)) {
            line = readline(fd);
            if (line == NULL) {
                /* this is the case of the last (empty) line */
                continue;
            }
            word = strtok(line, ":");
            if (word != NULL) {
                def = strtok(NULL, "\n");
                if (def != NULL) {
                    /* remove extra initial spaces, if any */
                    while (def[0] == ' ') {
                        def = def + 1;
                    }
                    string str_word = string_create(word);
                    string str_def = string_create(def);
                    result = dict_add(result, str_word, str_def);
                }
            }
            free(line);
        }
        fclose(fd);
    }
    return (result);
}


void dict_to_file(dict_t dict, string filename) {
    FILE *fd = NULL;
    fd = fopen(string_ref(filename), "w");
    if (fd != NULL) {
        printf("Dumping dict to filename %s.\n", string_ref(filename));
        dict_dump(dict, fd);
        fclose(fd);
    } else {
        printf("Can not dump dict to filename %s.\n", string_ref(filename));
    }
}
