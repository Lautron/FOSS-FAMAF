#include<stdio.h>

int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(char *nombre, int x) {
  printf("\n%s --> %d", nombre, x);
}

int main(void){
  int x = pedirEntero("x");
  int y = pedirEntero("y");

  int z = x;
  x = y;
  y = z;

  imprimeEntero("x", x);
  imprimeEntero("y", y);
  
  return 0;
}
