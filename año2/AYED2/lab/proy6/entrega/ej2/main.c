#include "string.h"
#include <stdio.h>

int main(void)
{
  string s1 = string_create("abc");
  string s2 = string_create("fgh");
  bool is_less = string_less(s1, s2);
  bool is_eq = string_eq(s1, s2);
  printf("is_less:%d\nis_eq:%d\n", is_less, is_eq);
  s1 = string_destroy(s1);
  s2 = string_destroy(s2);

  printf("\n");
  s1 = string_create("fgh");
  s2 = string_create("fgh");
  is_less = string_less(s1, s2);
  is_eq = string_eq(s1, s2);
  printf("is_less:%d\nis_eq:%d\n", is_less, is_eq);
  s1 = string_destroy(s1);
  s2 = string_destroy(s2);
  return 0;
}
