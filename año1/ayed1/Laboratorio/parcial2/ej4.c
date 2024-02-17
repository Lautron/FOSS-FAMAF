#include <stdbool.h>
#include <stdio.h>
#define N 3

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
  int hash;
  int likes;
  int dislikes;
} video_t;

void pedirArreglo(video_t a[], int n_max)
{
  printf("Ingrese %d trios de hash, likes y dislikes (separando con espacios)\n", n_max);
  int i = 0;
  while (i < n_max) {
    scanf("%d %d %d", &a[i].hash, &a[i].likes, &a[i].dislikes);
    i++;
  }
}

bool gusta(int hash, video_t a[], int tam)
{
  int i = 0;
  bool res = false;
  while (i < tam) {
    if (a[i].hash == hash) {
      res = (a[i].likes > a[i].dislikes);
    }
    i++;
  }
  return res;
}

int main(void)
{
  video_t array[N];
  pedirArreglo(array, N);
  printf("Ingrese el hash del video que quiera analizar\n");
  int hash = pedirEntero("hash");
  bool res = gusta(hash, array, N);
  imprimeEntero("res", res);
  return 0;
}
