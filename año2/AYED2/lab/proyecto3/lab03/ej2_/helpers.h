/*
  @file helpers.h
  @brief player helper functions declaration
*/
#ifndef _HELPERS_H
#define _HELPERS_H
#include <stdbool.h>
#include "player.h"

/**
 * @brief Return whether the array 'other' is a permutation of the array 'a'
 *        The arrays 'a' and 'other' must have both the same 'length'.
 *
 * @param[in]      a array of players
 * @param[in]      other another array of players
 * @param[in]  length length of both arrays
 *
 * @return true is 'a' is permutation of 'other', false otherwise
 */
bool array_is_permutation_of(player_t a[], player_t other[], unsigned int length);

/**
 * @brief Copy the array 'src' into the array 'dst'
 *
 * @param[in]      dst     The destination
 * @param[in]      src     The source
 * @param[in]      length  Length of both arrays
 */
void array_copy(player_t dst[], player_t src[], unsigned int length);


/**
 * @brief Loads the contents of the file into the array of players.
 *
 * @param[in]  filepath  Filepath to player atp file
 * @param[out] atp       Array of players
 *
 * @return     The amount of players read from file
 */
unsigned int process_file(const char *filepath, player_t atp[]);

/**
 * @brief Prints the contents of the array of players to standard output.
 *
 * @param[in]      atp     Array of players
 * @param[in]      length  Array length
 */
void atp_dump(player_t atp[], unsigned int length);

#endif
