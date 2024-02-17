#include <stdio.h>

void swapPointers(int* p, int* q)
{
  int* tmp;
  tmp = q;
  q = p;
  p = tmp;
}

void swapPointerValues(int* p, int* q)
{
  int tmp;
  tmp = *q;
  *q = *p;
  *p = tmp;
}

int main(void)
{
  int a, b;
  int *p, *q;
  a = 2;
  b = 4;
  p = &a;
  q = &b;

  printf("a: %d, b: %d\n", *p, *q);
  printf("Doings swap...\n");
  swapPointers(p, q);
  printf("a: %d, b: %d\n", *p, *q);
  return 0;
}
