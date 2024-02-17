#include <stdio.h>

int main(void){
  int x, y;
  printf("Ingrese los valores para x e y (separandolos con espacios)\n");
  scanf("%d %d", &x, &y);
  if (x >=  y) {
    x = 0;
  }
  else if (x <= y) {
    x = 2;
  }
  printf("(x->%d, y->%d)", x, y);
  return 0;
}

//Respuestas en "ejercicios.pdf"
