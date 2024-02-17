#include <stdio.h>

int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x, char *nombre) {
  printf("\n%s --> %d", nombre, x);
}

int devolver_mayor(int x, int y, int z, int m){
  if (x < y) {
    m = x;
  } else if (x >= y) {
    m = y;
  } else if (m >= z) {
    m = z;
  }
  return m;
}

int main(void){
  int x, y, z, m;
  x = pedirEntero("x");
  y = pedirEntero("y");
  z = pedirEntero("z");
  m = pedirEntero("m");

  m = devolver_mayor(x, y, z, m);

  imprimeEntero(x, "x");
  imprimeEntero(y, "y");
  imprimeEntero(z, "z");
  imprimeEntero(m, "m");
  return 0;
}

//Respuestas en "ejercicios.pdf"
