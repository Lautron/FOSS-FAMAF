#include <stdio.h>

int main(void){
  int x, y, z, m;
  printf("Ingrese los valores para x,y,z y m (separandolos con espacios)\n");
  scanf("%d %d %d %d", &x, &y, &z, &m);
  if (x < y) {
    m = x;
  } else if (x >= y) {
    m = y;
  } 
  printf("(x->%d, y->%d, z->%d, m->%d)\n", x, y, z, m);
  if (m >= z) {
    m = z;
  }

  printf("(x->%d, y->%d, z->%d, m->%d)", x, y, z, m);
  return 0;
}

//Respuestas en "ejercicios.pdf"
