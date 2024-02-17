#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char* str)
{
  size_t res = 0;
  while (*str != '\0') {
    res++;
    str++;
  }
  // printf("%lu\n", res);
  return res;
}

char* string_filter(const char* str, char c)
{
  char* res;
  res = calloc(string_length(str), sizeof(char));
  char* it = res;
  while (*str != '\0') {
    if (*str != c) {
      *it = *str;
      it++;
    }
    str++;
  }
  printf("%s\n", res);
  return res;
}
