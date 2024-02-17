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
  int horas;
  int minutos;
  int segundos;
} lapso_t;

lapso_t calcular_lapso(int segs)
{
  assert(segs >= 0);
  lapso_t res;
  res.horas = segs / 3600;
  res.minutos = (segs % 3600) / 60;
  res.segundos = (segs % 3600) % 60;
  return res;
}
int main(void)
{
  int segs = pedirEntero("segs");
  lapso_t lapso = calcular_lapso(segs);
  if (segs < 0) {
    printf("ERROR: el valor no puede ser negativo");
    return 0;
  }
  imprimeEntero("Horas", lapso.horas);
  imprimeEntero("Minutos", lapso.minutos);
  imprimeEntero("Segundos", lapso.segundos);
  return 0;
}
