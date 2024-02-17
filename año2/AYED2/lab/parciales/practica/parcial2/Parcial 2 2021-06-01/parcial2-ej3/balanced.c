#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

static bool is_left_delimiter(char c)
{
  return (c == '(' || c == '[' || c == '{' || c == '<');
}

static bool is_right_delimiter(char c)
{
  return (c == ')' || c == ']' || c == '}' || c == '>');
}

static bool is_delimeter(char c)
{
  return is_left_delimiter(c) || is_right_delimiter(c);
}

static char match(char c)
{
  char m;
  if (c == '(') {
    m = ')';
  } else if (c == '[') {
    m = ']';
  } else if (c == '{') {
    m = '}';
  } else if (c == '<') {
    m = '>';
  }
  return (m);
}

static void print_help(char* program_name)
{
  /* Print the usage help of this program. */
  printf("Usage: %s <expression-to-check>\n\n"
	 "Check if the expression has balanced delimeters (parenthesis, brackets, braces and <>).\n",
      program_name);
}

static char* parse_expression(int argc, char* argv[])
{
  /* Parse the expression given by command line argument. */
  char* result = NULL;
  /* Program takes exactly one argument */
  if (argc != 2) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }
  /* Use the first argument ass the expression */
  result = argv[1];
  /* return expression */
  return result;
}
queue take_delimeters(char* expression)
{
  assert(expression != NULL);
  size_t i = 0;
  queue only_delimeters = queue_empty();
  while (expression[i] != '\0') {
    if (is_delimeter(expression[i])) {
      only_delimeters = queue_enqueue(only_delimeters, expression[i]);
    }
    i++;
  }
  return only_delimeters;
}

int main(int argc, char* argv[])
{
  stack s;
  bool balanced = true;
  char* expression = NULL; //, *delimeters = NULL;
  // size_t i = 0;

  // Parse arguments and get the expression to be analysed
  expression = parse_expression(argc, argv);

  queue delim_fifo; // Cola de delimitadores
  /*
   * Completar: Crear una cola con todos los delimitadores de `expression`
   */
  delim_fifo = take_delimeters(expression);
  s = stack_empty();
  while (!queue_is_empty(delim_fifo) && balanced) {
    char delim;
    /*
     * Completar: en `delim` debe estar el primer delimitador
     * de la cola. Luego de procesarlo se lo debe quitar de
     * `delim_fifo`.
     */
    delim = queue_first(delim_fifo);
    delim_fifo = queue_dequeue(delim_fifo);
    if (is_left_delimiter(delim)) {
      s = stack_push(s, match(delim));
    } else {
      assert(is_right_delimiter(delim));
      if (!stack_is_empty(s) && delim == stack_top(s)) {
	s = stack_pop(s);
      } else {
	balanced = false;
      }
    }
  }
  balanced = balanced && stack_is_empty(s);
  printf(balanced ? "la expresión está balanceada\n" : "la expresión NO esta balanceada\n");
  s = stack_destroy(s);
  // la cola queda vacia pero por si acaso aplico el destroy
  delim_fifo = queue_destroy(delim_fifo);

  return 0;
}
