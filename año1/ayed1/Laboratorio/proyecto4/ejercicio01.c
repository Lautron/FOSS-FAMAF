#include<stdio.h>
#include <assert.h>

int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void holaHasta(int n) {
  int i = 0;
  while (i < n){
    printf("hola\n");
    i++;
  }
}

int main(void){
  int n = pedirEntero("n");
  assert(n > 0);
  holaHasta(n);
  return 0;
}
