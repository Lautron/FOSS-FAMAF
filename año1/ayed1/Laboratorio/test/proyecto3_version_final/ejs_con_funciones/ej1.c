#include <stdio.h>
int pedirEntero(char *nombre){
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x, char *nombre) {
  printf("\n%s --> %d", nombre, x);
}

int main(void) {
  printf("Ingrese los valores para x, y, z, separando con espacios\n");
  int x, y, z;
  x = pedirEntero("x");
  y = pedirEntero("y");
  z = pedirEntero("z");

  char expresiones[5][30] = {
    "x+y+1", "z*z+y*45-15*x", "y-2 == (x*3+1) % 5", "y/2*x", "y<x*z"
  };
  int valores[5] = {x+y+1, z*z+y*45-15*x, y-2 == (x*3+1) % 5, y/2*x, y<x*z};

  for (int i=0;i<5;i++) {
    imprimeEntero(valores[i], expresiones[i]); 
  };

  return 0;
 }

//|    Expresion    | (x -> 7, y -> 3, z -> 5) | (x -> 1, y -> 10, z -> 8) |
//|:---------------:|:------------------------:|:-------------------------:|
//|      x+y+1      |            11            |             12            |
//| z* z+y* 45-15*x |            55            |            499            |
//|  y-2==(x*3+1)%5 |             0            |             0             |
//|     y/2 * x     |             7            |             5             |
//|     y < x*z     |             1            |             0             |
