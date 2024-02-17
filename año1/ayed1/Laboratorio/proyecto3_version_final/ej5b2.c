#include <stdio.h>
#include <stdbool.h>

int main(void){
  int x, i, temp_res;
  bool res;
  printf("Ingrese el valor para x, i, res (Separandolos utilizando espacios)\n");
  scanf("%d %d %d", &x, &i, &temp_res);
  res = temp_res;
  i = 2;
  res = true;
  while (i < x && res) {
    res = res && (x % i) != 0;
    i = i + 1;
    printf("(x->%d, i->%d, res->%d)\n", x, i, res);
  }
  return 0;
}

//(x->5, i->3, res->1)
//(x->5, i->4, res->1)
//(x->5, i->5, res->1)

//Respuestas en "ejercicios.pdf"
