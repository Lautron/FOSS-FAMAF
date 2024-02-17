#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _s_string {
  char* content;
  unsigned int length;
};

string string_create(const char* word)
{
  string str = NULL;
  str = malloc(sizeof(struct _s_string));
  str->length = strlen(word);
  str->content = calloc(str->length + 1, sizeof(char));
  str->content = strncpy(str->content, word, str->length + 1);
  return (str);
}

unsigned int string_length(string str)
{
  return (str->length);
}

bool string_less(const string str1, const string str2)
{
  /* needs implementation */
  char *s1, *s2;
  s1 = str1->content;
  s2 = str2->content;
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 >= *s2) {
      return false;
    }
    s1++;
    s2++;
  }
  return true;
}

bool string_eq(const string str1, const string str2)
{
  int cmp = strcmp(str1->content, str2->content);
  return (cmp == 0);
}

string string_clone(const string str)
{
  return (string_create(str->content));
}

string string_destroy(string str)
{
  free(str->content);
  free(str);
  str = NULL;
  return (str);
}

void string_dump(string str, FILE* file)
{
  fprintf(file, "%s", str->content);
}

const char* string_ref(string str)
{
  return (str->content);
}
