#include "weather_utils.h"
#include "array_helpers.h"

int get_min_historic_temp(WeatherTable a)
{
  int prev = a[0][0][0]._min_temp;
  for (int y = 0; y < YEARS; y++) {
    for (int m = 0; m < MONTHS; m++) {
      for (int d = 0; d < DAYS; d++) {
	int elem = a[y][m][d]._min_temp;
	prev = elem < prev ? elem : prev;
      }
    }
  }
  return prev;
}

void get_max_temp_per_year(WeatherTable a, int res[])
{
  for (int y = 0; y < YEARS; y++) {
    int prev = a[0][0][0]._max_temp;
    for (int m = 0; m < MONTHS; m++) {
      for (int d = 0; d < DAYS; d++) {
	int elem = a[y][m][d]._max_temp;
	prev = elem > prev ? elem : prev;
      }
    }
    res[y] = prev;
  }
}

void get_max_prec_month(WeatherTable a, int res[])
{
  unsigned int precM, maxM, resM;
  for (unsigned int y = 0; y < YEARS; y++) {
    maxM = 0;
    for (unsigned int m = 0; m < MONTHS; m++) {
      precM = 0;
      for (unsigned int d = 0; d < DAYS; d++) {
	precM = a[y][m][d]._rainfall;
      }
      if (precM > maxM) {
	maxM = precM;
	resM = m;
      }
    }
    res[y] = resM;
  }
}
