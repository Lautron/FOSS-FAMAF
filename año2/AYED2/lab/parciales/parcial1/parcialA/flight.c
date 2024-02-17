/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include "flight.h"
#include <stdlib.h>

static const int AMOUNT_OF_FLIGHT_VARS = 3;

Flight flight_from_file(FILE* file, char code)
{
  Flight flight;
  flight.code = code;

  /* COMPLETAR */
  int res = fscanf(file, EXPECTED_FLIGHT_FILE_FORMAT, &flight.type, &flight.hour, &flight.passengers_amount);
  if (res != AMOUNT_OF_FLIGHT_VARS) {
    fprintf(stderr, "Invalid data.\n");
    exit(EXIT_FAILURE);
  }

  return flight;
}
