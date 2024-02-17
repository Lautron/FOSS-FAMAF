/*
  @file array_helpers.h
  @brief defines array helpers methods. These methods operates over multidimensional array of layover
*/
#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdbool.h>
#include "flight.h"

#define HOURS 24
#define TYPE 2

typedef Flight LayoverTable [HOURS][TYPE];

/**
 * @brief Write the content of the array 'a' into stdout.
 * @param[in] a array to dump in stdout
 */
void array_dump(LayoverTable a);

/**
 * @brief calculates how many passengers are awaiting for a flight.
 * @param[in] a array with data
 * @param[in] hour A value between 0 and 23 that represent the hour to compute
 *                 the amount of awaiting passengers
 */
unsigned int passengers_amount_in_airport(LayoverTable a, unsigned int hour);


/**
 * @brief reads an array of layover information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <flight_code> <type> <hour> <passengers> <type> <hour> <passengers>
 *
 *   Those elements are copied into the multidimensional array 'a'.
 *   The dimensions of the array are given by the macros noted above.
 *
 * @param a array which will contain read file
 * @param filepath file with layover data
 */
void array_from_file(LayoverTable a, const char *filepath);

#endif
