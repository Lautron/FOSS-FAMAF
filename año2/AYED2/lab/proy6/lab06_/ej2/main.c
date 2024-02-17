#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

int main(int argc, char *argv[]) {
  if(argc < 3) {
    fprintf(stderr, "Missing parameters\n");
    exit(EXIT_FAILURE);
  }
  char *word = argv[1];
  char *word2 = argv[2];
  string str = string_create(word);
  string str2 = string_create(word2);
  if(string_eq(str, str2)) {
    printf("Iguales\n");
  } else if(string_less(str, str2)) {
    printf("<\n"); //para mi es al revez pero asi dice el manual
  } else {
    printf(">\n");
  }

  string_destroy(str);
  string_destroy(str2);
  return 0;
}