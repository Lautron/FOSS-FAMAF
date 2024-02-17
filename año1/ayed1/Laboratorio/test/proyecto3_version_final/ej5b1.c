#include <stdio.h>

int main(void){
  int x, y, i;
  printf("Ingrese el valor para x, y e i (Separandolos utilizando espacios)\n");
  scanf("%d %d %d", &x, &y, &i);
  i = 0;
  while (x >= y) {
    x = x-y;
    i = i + 1;
    printf("(x->%d, y->%d, i->%d)\n", x, y, i);
  }
  return 0;
}

//(x->10, y->3, i->1)
//(x->7, y->3, i->2)
//(x->4, y->3, i->3)
//(x->1, y->3, i->4)

//Respuestas en "ejercicios.pdf"
