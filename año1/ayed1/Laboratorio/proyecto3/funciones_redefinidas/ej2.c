#include <stdio.h>
#include <stdbool.h>

int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x, char *nombre) {
  printf("\n%s --> %d", nombre, x);
}

int main(void) {
  int x, y, z;
  bool b, w;
  int temp_b, temp_w;

  x = pedirEntero("x");
  y = pedirEntero("y");
  z = pedirEntero("z");
  temp_b = pedirEntero("b");
  temp_w = pedirEntero("w");

  b = temp_b;
  w = temp_w;

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

  imprimeEntero(x, "x");
  imprimeEntero(valores[0], expresiones[0]); 

  imprimeEntero(x, "x");
  imprimeEntero(y, "y");
  imprimeEntero(z, "z");
  imprimeEntero(valores[1], expresiones[1]); 

  imprimeEntero(b, "b");
  imprimeEntero(w, "w");
  imprimeEntero(valores[2], expresiones[2]); 

  return 0;
 }

// Resultado: (x->4, y->-4, z->8, b->1, w->0)
