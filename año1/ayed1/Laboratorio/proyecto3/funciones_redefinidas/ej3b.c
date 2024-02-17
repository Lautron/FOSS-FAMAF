#include <stdio.h>
#include <assert.h>

int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x, char *nombre) {
  printf("\n%s --> %d\n", nombre, x);
}

int uno_a(void) {
  int x;
  x = pedirEntero("x");
  assert(x == 1);
  x = 5;
  imprimeEntero(x, "x");
  return 0;
}

int uno_b(void) {
  int x, y;
  x = pedirEntero("x");
  y = pedirEntero("y");
  assert(x == 2 && y == 5);
  x = x + y;
  y = y + y;
  imprimeEntero(x, "x");
  imprimeEntero(y, "y");
  return 0;
}

int uno_c(void) {
  int x, y;
  x = pedirEntero("x");
  y = pedirEntero("y");
  assert(x == 2 && y == 5);
  y = y + y;
  x = x + y;
  imprimeEntero(x, "x");
  imprimeEntero(y, "y");
  return 0;
}

int main(void) {
  uno_a();
  uno_b();
  uno_c();
  return 0;
}
