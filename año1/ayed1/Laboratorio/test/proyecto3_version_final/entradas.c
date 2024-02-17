#include <stdio.h>
int pedirEntero(void) {
  int x;
  printf("Ingrese un numero entero\n");
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x) {
  printf("El entero es: %d", x);
}

int main(void) {
  int entero = pedirEntero();  
  imprimeEntero(entero);
  return 0;
}

//Respuestas en "ejercicios.pdf"
