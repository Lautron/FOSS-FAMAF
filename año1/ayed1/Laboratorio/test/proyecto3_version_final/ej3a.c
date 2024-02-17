#include <stdio.h>

void uno_a(void) {
  int x;
  printf("\nEjercicio 1a: Ingrese el valor para x\n");
  scanf("%d", &x);
  x = 5;
  printf("(x->%d)\n", x);
}

void uno_b(void) {
  int x, y;
  printf("\nEjercicio 1b: Ingrese el valor para x e y (separandolos con espacios)\n");
  scanf("%d %d", &x, &y);
  x = x + y;
  y = y + y;
  printf("(x->%d, y->%d)\n", x, y);
}

void uno_c(void) {
  int x, y;
  printf("\nEjercicio 1c: Ingrese el valor para x e y (separandolos con espacios)\n");
  scanf("%d %d", &x, &y);
  y = y + y;
  x = x + y;
  printf("(x->%d, y->%d)\n", x, y);
}

int main(void) {
  uno_a();
  uno_b();
  uno_c();
  return 0;
}

