#include <stdio.h>
int main(void) {
  printf("Ingrese los valores para x, y, z, separando con espacios\n");
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z); 

  char expresiones[5][30] = {
    "x+y+1", "z*z+y*45-15*x", "y-2 == (x*3+1) % 5", "y/2*x", "y<x*z"
  };
  int valores[5] = {x+y+1, z*z+y*45-15*x, y-2 == (x*3+1) % 5, y/2*x, y<x*z};

  for (int i=0;i<5;i++) {
    printf("%s --> %d\n", expresiones[i], valores[i]); 
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

//Respuestas en "ejercicios.pdf"
