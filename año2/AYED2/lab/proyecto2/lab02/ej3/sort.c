#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "sort.h"
#include "sort_helpers.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der)
{
  /* Needs implementation */
  unsigned int i, j;
  i = izq + 1u;
  j = der;
  while (i <= j) {
    if (goes_before(a[i], a[izq])) {
      i += 1u;
    } else if (goes_before(a[izq], a[j])) {
      j -= 1u;
    } else {
      swap(a, i, j);
    }
  }
  swap(a, izq, j);

  return j;

  /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
     */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
  /* copiá acá la implementación que hiciste en el ejercicio 3 */
  unsigned int ppiv;
  if (der > izq) {
    ppiv = partition(a, izq, der);
    if (ppiv > 0) {
      quick_sort_rec(a, izq, ppiv - 1u);
    }
    quick_sort_rec(a, ppiv + 1u, der);
  }
}

void quick_sort(int a[], unsigned int length)
{
  quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
