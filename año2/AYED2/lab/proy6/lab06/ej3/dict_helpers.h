#ifndef _DICT_HELPERS_H
#define _DICT_HELPERS_H

#include "dict.h"


dict_t dict_from_file(string filename);
/*
 * Return a dict instance populated by the data in the given filename.
 *
 * PRE: filename is not NULL.
 *
 * file data is formatted as follows:
 *      word_1: definition_1
 *      ...
 *      word_N: definition_N
 *
 * POST: Return NULL if the given filename does not exist or can not be opened.
 * Return a not NULL dict otherwise, and the dict contents are the words
 * and definitions listed in the given file.
 */

void dict_to_file(dict_t dict, string filename);
/*
 * Write dict data to file with the format expected by dict_from_file.
 *
 * PRE: 'dict' is not NULL.
 *
 * POST: 'dict' words and respective definitions are written to 'filename'
 * using the following format:
 *       word_1: definition_1
 *       ...
 *       word_N: definition_N
 */

#endif
