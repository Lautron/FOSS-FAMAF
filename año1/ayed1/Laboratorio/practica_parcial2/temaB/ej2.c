#include <assert.h>
#include <stdio.h>

int pedirEntero(char* nombre)
{
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(char* nombre, int x)
{
  printf("\n%s --> %d", nombre, x);
}

typedef struct {
  int rojo;
  int verde;
  int azul;
} color_t;
color_t calcular_color(int color_id)
{
  assert(color_id >= 0 && color_id < 16777215);
  color_t res;
  res.azul = color_id / 65536;
  res.verde = (color_id % 65536) / 256;
  res.rojo = (color_id % 65536) % 256;
  return res;
}
int main(void)
{
  int color_id = pedirEntero("color_id");
  if (color_id < 0 || color_id > 16777215) {
    printf("ERROR: id no valida");
    return 0;
  };
  color_t res = calcular_color(color_id);
  imprimeEntero("res.rojo", res.rojo);
  imprimeEntero("res.verde", res.verde);
  imprimeEntero("res.azul", res.azul);
  return 0;
}
