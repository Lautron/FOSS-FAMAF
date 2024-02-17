/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */

void print_help(char* program_name)
{
  /* Print the usage help of this program. */
  printf("Usage: %s <input file path>\n\n",
      program_name);
}

char* parse_filepath(int argc, char* argv[])
{
  /* Parse the filepath given by command line argument. */
  char* result = NULL;

  if (argc < 2) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return (result);
}

abb abb_from_file(const char* filepath)
{
  FILE* file = NULL;
  abb read_tree;

  read_tree = abb_empty();
  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }
  unsigned int i = 0u;
  unsigned int size = 0u;
  int res = 0;
  res = fscanf(file, " %u ", &size);
  if (res != 1) {
    fprintf(stderr, "Invalid format.\n");
    exit(EXIT_FAILURE);
  }
  while (i < size) {
    abb_elem elem;
    res = fscanf(file, " %d ", &(elem));
    if (res != 1) {
      fprintf(stderr, "Invalid array.\n");
      exit(EXIT_FAILURE);
    }
    read_tree = abb_add(read_tree, elem);

    ++i;
  }
  fclose(file);
  return read_tree;
}
unsigned int choose_option()
{
  unsigned int res;
  char message[] = "\n"
		   " 1 ........ Mostrar árbol por pantalla\n"
		   " 2 ........ Agregar un elemento\n"
		   " 3 ........ Eliminar un elemento\n"
		   " 4 ........ Chequear existencia de elemento\n"
		   " 5 ........ Mostrar longitud del árbol\n"
		   " 6 ........ Mostrar raiz, máximo y mínimo del árbol\n"
		   " 7 ........ Salir\n"
		   "Seleccion:";
  printf("%s", message);
  scanf("%u", &res);
  if ((res < 1) | (res > 7)) {
    printf("Invalid option!\n");
    exit(EXIT_FAILURE);
  };
  return res;
}

int ask_for_elem()
{
  int x;
  printf("Ingrese un valor: ");
  scanf("%d", &x);
  return x;
}

abb execute_action(abb tree, unsigned int option)
{
  abb_elem elem;
  switch (option) {
  case 1:
    abb_dump(tree);
    printf("\n");
    break;
  case 2:
    elem = ask_for_elem();
    tree = abb_add(tree, elem);
    break;
  case 3:
    elem = ask_for_elem();
    tree = abb_remove(tree, elem);
    break;
  case 4:
    elem = ask_for_elem();
    char* answer = abb_exists(tree, elem) ? "Element exists" : "Element does not exist";
    printf("%s\n", answer);
    break;
  case 5:
    printf("Longitud: %u\n", abb_length(tree));
    printf("\n");
    break;
  case 6:
    printf("raiz: %d\n minimo: %d\n maximo: %d\n",
	abb_root(tree),
	abb_max(tree),
	abb_min(tree));
    break;
  case 7:
    tree = abb_destroy(tree);
    exit(EXIT_SUCCESS);
    break;

  default:
    printf("Invalid option!\n");
    tree = abb_destroy(tree);
    exit(EXIT_FAILURE);
  }
  return tree;
}
int main(int argc, char* argv[])
{
  char* filepath = NULL;
  unsigned int option;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* parse the file to obtain an abb with the elements */
  abb tree = abb_from_file(filepath);

  /*dumping the tree*/
  abb_dump(tree);
  if (!abb_is_empty(tree)) {
    printf("\n");
    printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
	abb_min(tree),
	abb_max(tree));
  } else {
    printf("\nÁrbol vacío\n");
  }

  /*
   * Modificar e implementar con un ciclo una interfaz que permita al usuario
   * realizar una de las siguientes operaciones en cada iteración:
   *
   * 1 ........ Mostrar árbol por pantalla
   * 2 ........ Agregar un elemento
   * 3 ........ Eliminar un elemento
   * 4 ........ Chequear existencia de elemento
   * 5 ........ Mostrar longitud del árbol
   * 6 ........ Mostrar raiz, máximo y mínimo del árbol
   * 7 ........ Salir
   *
   * Se debe solicitar un número de entrada para realizar una de las acciones.
   *
   * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
   * elemento a agregar, eliminar o chequear respectivamente.
   *
   * Al salir debe liberarse toda la memoria utilizada.
   *
   */
  while (true) {
    option = choose_option();
    tree = execute_action(tree, option);
  }

  return (EXIT_SUCCESS);
}
