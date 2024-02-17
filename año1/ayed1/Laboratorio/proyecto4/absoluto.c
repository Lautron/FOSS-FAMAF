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

int absoluto(int x) {
  if (x >= 0) {
    return x;
  } else {
    return -x;
  }
}

int main(void){
  int x = pedirEntero("x");
  int resultado = absoluto(x);
  imprimeEntero("resultado", resultado);
  return 0;
}
