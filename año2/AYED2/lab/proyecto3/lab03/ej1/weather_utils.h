#ifndef WEATHER_UTILS
#define WEATHER_UTILS 
#include "array_helpers.h"
int get_min_historic_temp(WeatherTable a);
void get_max_temp_per_year(WeatherTable a, int res[]);
void get_max_prec_month(WeatherTable a, int res[]);
#endif /* ifndef WEATHER_UTILS */
