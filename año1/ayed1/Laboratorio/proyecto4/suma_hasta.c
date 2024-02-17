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

int suma_hasta(int N) {
  return N*(N+1)/2;
}

int main(void){
  int N = pedirEntero("N");
  if (N < 0){
    printf("Error: argumento negativo");
  } else {
    int resultado = suma_hasta(N);
    imprimeEntero("resultado", resultado);
  }
  return 0;
}
