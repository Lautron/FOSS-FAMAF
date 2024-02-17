/*
  @file layover.h
  @brief Defines an airport layover betwen the arrival and departure of a flight
*/

#ifndef _FLIGHT_H
#define _FLIGHT_H
#define EXPECTED_FLIGHT_FILE_FORMAT " %u %u %u "

typedef enum { arrival, departure } flight_t;

#include <stdio.h>

/** @brief Type used to represent flight data.*/
typedef struct _flight
{
  char code;
  flight_t type;
  unsigned int hour;
  unsigned int passengers_amount;
} Flight;

/**
 * @brief reads flight data from file line
 * @details
 * Flight file line must contain:
 * <unsigned int> <unsigned int> <unsigned int>
 *
 * @param[in] file Opened file stream
 * @param[in] code The flight code
 * @return Flight structure which contain read information from file
 */
Flight flight_from_file(FILE* file, char code);

#endif //_FLIGHT_H
