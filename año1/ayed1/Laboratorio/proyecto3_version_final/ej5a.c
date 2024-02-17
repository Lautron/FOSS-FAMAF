#include <stdio.h>

int ejercicio_h(void){
  int i;
  printf("Ejercicio 1h: Ingrese el valor para i\n");
  scanf("%d", &i);
  while (i != 0) {
    i = i-1;
    printf("(i->%d)\n", i);
  }
  return 0;
}

int ejercicio_i(void){
  int i;
  printf("Ejercicio 1i: Ingrese el valor para i\n");
  scanf("%d", &i);
  while (i != 0) {
    i = 0;
    printf("(i->%d)\n", i);
  }
  return 0;
}

int main(void){
  ejercicio_h();
  ejercicio_i();
  return 0;
}

//Respuestas en "ejercicios.pdf"
