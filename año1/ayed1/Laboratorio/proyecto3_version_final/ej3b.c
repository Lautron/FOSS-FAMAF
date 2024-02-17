#include <stdio.h>
#include <assert.h>

int uno_a(void) {
  int x;
  printf("\nEjercicio 1a: Ingrese el valor para x\n");
  scanf("%d", &x);
  assert(x == 1);
  x = 5;
  printf("(x->%d)\n", x);
  return 0;
}

int uno_b(void) {
  int x, y;
  printf("\nEjercicio 1b: Ingrese el valor para x e y (separandolos con espacios)\n");
  scanf("%d %d", &x, &y);
  assert(x == 2 && y == 5);
  x = x + y;
  y = y + y;
  printf("(x->%d, y->%d)\n", x, y);
  return 0;
}

int uno_c(void) {
  int x, y;
  printf("\nEjercicio 1c: Ingrese el valor para x e y (separandolos con espacios)\n");
  scanf("%d %d", &x, &y);
  assert(x == 2 && y == 5);
  y = y + y;
  x = x + y;
  printf("(x->%d, y->%d)\n", x, y);
  return 0;
}

int main(void) {
  uno_a();
  uno_b();
  uno_c();
  return 0;
}

//Respuestas en "ejercicios.pdf"
