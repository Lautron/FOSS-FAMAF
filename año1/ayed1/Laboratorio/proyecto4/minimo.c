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

int minimo(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

int main(void){
  int x = pedirEntero("x");
  int y = pedirEntero("y");
  int resultado = minimo(x,y);
  imprimeEntero("resultado", resultado);
  return 0;
}
