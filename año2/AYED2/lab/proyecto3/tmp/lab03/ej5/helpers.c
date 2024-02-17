/*
  @file helpers.c
  @brief player helpers methods implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

static const char SEPARATOR = ' ';

void array_copy(player_t copy[], player_t array[], unsigned int length) {
    /* This method is not actually performing a 'copy'. why? */
    for (unsigned int i = 0u; i < length; ++i) {
        copy[i] = array[i];
    }
}

/**
 * @brief counts the amaount of players which have the same name as 'value' present in Array 'a'
 *
 * @param[in]  a       Players array
 * @param[in]  length  Players array length
 * @param[in]  value   Player who will be count
 *
 * @return amount of players with name 'value.name' contained in 'a'
 */
static unsigned int array_value_count(player_t a[], unsigned int length, player_t value) {
    unsigned int count = 0u;
    for (unsigned int i = 0u; i < length; ++i) {
        if (a[i] == value) {
            ++count;
        }
    }
    return (count);
}

bool array_is_permutation_of(player_t a[], player_t b[], unsigned int length) {
    unsigned int i = 0u;
    bool result = true;
    while (i < length && result) {
        unsigned int a_count = array_value_count(a, length, a[i]);
        unsigned int b_count = array_value_count(b, length, a[i]);
        result = (a_count == b_count);
        ++i;
    }
    return (result);
}

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

/**
 * @brief Reads an unsigned int value from stream file
 *
 * @param[in]      file  The opened file stream
 *
 * @return value read from file
 */
static unsigned int process_unsigned(FILE *file) {
    unsigned int value = 0u;
    int res = fscanf(file, " %u ", &value);
    if (res != 1u) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    return (value);
}

void atp_dump(player_t atp[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout,"%s ", atp[i]->name);
        fprintf(stdout,"%s ", atp[i]->country);
        fprintf(stdout,"%u %u %u %u\n", atp[i]->rank, atp[i]->age, atp[i]->points, atp[i]->tournaments);
    }
}

static unsigned int process_FILE(FILE *file, player_t atp[]) {
    unsigned int i = 0u;
    player_t player = NULL;
    while (!feof(file)) {
        player = (player_t)malloc(sizeof(struct _player_t));
        process_string(file, SEPARATOR, player->name, MAX_NAME_LENGTH + 1u);
        process_string(file, SEPARATOR, player->country, MAX_COUNTRY_LENGTH + 1u);
        player->rank = process_unsigned(file);
        player->age = process_unsigned(file);
        player->points = process_unsigned(file);
        player->tournaments = process_unsigned(file);
        atp[i] = player;
        ++i;
    }
    return (i);
}

unsigned int process_file(const char *filepath, player_t atp[]) {
    unsigned int size = 0u;
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    size = process_FILE(file, atp);
    fclose(file);
    return (size);
}

void destroy(player_t atp[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        free(atp[i]);
        atp[i] = NULL;
    }
}
