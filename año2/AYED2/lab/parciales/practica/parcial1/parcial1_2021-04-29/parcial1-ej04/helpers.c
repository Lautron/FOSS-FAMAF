/*
  @file helpers.c
  @brief sogn helpers methods implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "movie.h"
#include "helpers.h"

static const char SEPARATOR = ' ';

/**
 * @brief reads characters from file until feof or separator is reached. read characters are stored in 'result'
 *
 * @param[in]  file             An opened stream file
 * @param[in]  separator        string separator
 * @param[out] result           the read characters wil be stored here
 * @param[in]  result_max_size  The maximum of characters that result allow.
 *
 * @return Amount of read characters
 */
static unsigned int process_string(FILE *file, char separator, char result[], unsigned int result_max_size)
{
    unsigned int str_size = 0u;
    char c = (char)((int)separator + 1);
    while (!feof(file) && c != separator) {
        c = fgetc(file);
        if (c != separator && str_size < result_max_size - 1u)
        {
            result[str_size] = c;
            ++str_size;
        }
        else if (c != separator && str_size >= result_max_size - 1u)
        {
            fprintf(stderr, "Max string length reached: %u \n", result_max_size);
            exit(EXIT_FAILURE);
        }
    }
    result[str_size] = '\0';

    return str_size;
}


void movielist_dump(movie_t movielist[], unsigned int length) {
    for (unsigned int i = 0u; i < length; i++) {
        fprintf(stdout,"[%.1f*] [%d votos] \"%s\" dirigida por %s (%uh %umin)\n",
                movielist[i].avg_rating,
                (int) movielist[i].n_votes,
                movielist[i].name,
                movielist[i].director,
                movielist[i].runtime / 60,
                movielist[i].runtime % 60);
    }
}

/**
 * @brief process an opened file stream pointer and stores parsed values into movie array
 *
 * @param[in]      file       The opened file
 * @param[out]     movielist  Movies array
 *
 * @return Amount of read movies
 */
static unsigned int process_FILE(FILE *file, movie_t movielist[], unsigned int max_size) {
    unsigned int i = 0u;
    while (!feof(file)) {
        int readed=0;
        process_string(file, SEPARATOR, movielist[i].name, MAX_NAME_LENGTH + 1u);
        process_string(file, SEPARATOR, movielist[i].director, MAX_DIRECTOR_LENGTH + 1u);
        readed = fscanf(file, " %u  %f  %f ", &movielist[i].runtime,
                                              &movielist[i].avg_rating,
                                              &movielist[i].n_votes);
        readed = readed;
        ++i;
    }
    max_size = max_size;
    return (i);
}

unsigned int process_file(const char *filepath, movie_t movielist[], unsigned int max_size) {
    unsigned int size = 0;
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    size = process_FILE(file, movielist, max_size);
    fclose(file);
    return (size);
}
