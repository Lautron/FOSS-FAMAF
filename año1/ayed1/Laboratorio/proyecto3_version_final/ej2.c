#include <stdio.h>
#include <stdbool.h>
int main(void) {
  int x, y, z;
  bool b, w;
  int temp_b, temp_w;

  char expresiones[3][35] = {
    "x % 4 == 0                     ",
    "x + y == 0 && y - x == (-1) * z",
    "not b && w                     "
  };
  int valores[3] = {
    x % 4 == 0,
    x + y == 0 && y - x == (-1) * z,
    ! b && w
  };

  printf("Ingrese los valores para x, y, z, b y w separando con espacios\n");
  scanf("%d %d %d %d %d", &x, &y, &z, &temp_b, &temp_w); 
  b = temp_b;
  w = temp_w;

  printf("\n(x->%d)\n", x);
  printf("%s --> %d\n", expresiones[0], valores[0]); 

  printf("\n(x->%d, y->%d, z->%d)\n", x, y, z);
  printf("%s --> %d\n", expresiones[1], valores[1]); 

  printf("\n(b->%d, w->%d)\n", b, w);
  printf("%s --> %d\n", expresiones[2], valores[2]); 

  return 0;
 }

// Resultado: (x->4, y->-4, z->8, b->1, w->0)
//Respuestas en "ejercicios.pdf"
