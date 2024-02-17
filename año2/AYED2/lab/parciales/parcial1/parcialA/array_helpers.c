/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
 * @brief returns true when reach last entry in flight table
 * @return True when is the last entry of the flight table, False otherwise
 */
static bool is_last_line(unsigned int hour, unsigned int type)
{
  return hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(LayoverTable a)
{
  for (unsigned int hour = 0u; hour < HOURS; ++hour) {
    for (unsigned int type = 0u; type < TYPE; ++type) {
      Flight f = a[hour][type];
      fprintf(stdout, "%c: %s at %u:00 with %u passengers", f.code, f.type == 0 ? "arrives" : "departs", f.hour - 1, f.passengers_amount);
      if (!is_last_line(hour, type)) {
	fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int passengers_amount_in_airport(LayoverTable a, unsigned int h)
{
  /* COMPLETAR */
  int result = 0;
  unsigned int hour;
  for (unsigned int i = 0; i < HOURS; i++) {
    hour = a[i][0].hour - 1;
    if (hour < h) {
      result += a[i][0].passengers_amount;
      result -= a[i][1].passengers_amount;
    } else if (hour == h) {
      result += a[i][0].passengers_amount;
    }
  }
  return (unsigned int)result;
}

void array_from_file(LayoverTable array, const char* filepath)
{
  FILE* file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;
  while (!feof(file)) {
    int res = fscanf(file, "_%c_", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    /* COMPLETAR: Generar y guardar ambos Flight en el array multidimensional */
    Flight flight_arrival = flight_from_file(file, code);
    Flight flight_departure = flight_from_file(file, code);
    array[i][0] = flight_arrival;
    array[i][1] = flight_departure;
    i++;
  }
  fclose(file);
}
