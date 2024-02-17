/*
  @file helpers.h
  @brief song helper functions declaration
*/
#ifndef _HELPERS_H
#define _HELPERS_H
#include <stdbool.h>
#include "song.h"

/**
 * @brief Loads the contents of the file into the array of songs.
 *
 * @param[in]  filepath  Filepath to playlist file
 * @param[out] playlist  Array of songs
 * @param[in]  max_size  Maximum allowed length of the array stored in playlist
 *
 * @return     The amount of songs read from file
 */
unsigned int process_file(const char *filepath, song_t playlist[], unsigned int max_size);

/**
 * @brief Prints the contents of the array of songs to standard output.
 *
 * @param[in]      playlist Array of songs
 * @param[in]      length   Array length
 */
void playlist_dump(song_t playlist[], unsigned int length);

#endif
