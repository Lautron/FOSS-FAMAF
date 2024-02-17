#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "sort.h"
#include "sort_helpers.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length)
{
  unsigned int min_pos = i;
  for (unsigned int j = i + 1; j < length; ++j) {
    if (!goes_before(a[min_pos], a[j])) {
      min_pos = j;
    }
  }
  return (min_pos);
}

void selection_sort(int a[], unsigned int length)
{
  for (unsigned int i = 0u; i < length; ++i) {
    unsigned int min_pos = min_pos_from(a, i, length);
    swap(a, i, min_pos);
  }
}

static void insert(int a[], unsigned int i)
{
  /* copiá acá la implementación que hiciste en el ejercicio 1 */

  unsigned int j = i;
  while (j >= 1 && goes_before(a[j], a[j - 1])) {
    swap(a, j - 1, j);
    j = j - 1;
  }
}

void insertion_sort(int a[], unsigned int length)
{
  for (unsigned int i = 1u; i < length; ++i) {
    insert(a, i);
  }
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der)
{
  /* copiá acá la implementación que hiciste en el ejercicio 3 */
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
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
  /* copiá acá la implementación que hiciste en el ejercicio 2 */
  unsigned int ppiv;
  if (der > izq) {
    ppiv = partition(a, izq, der);
    if (ppiv != 0) {
      quick_sort_rec(a, izq, ppiv - 1);
    }
    quick_sort_rec(a, ppiv + 1, der);
  }
}

void quick_sort(int a[], unsigned int length)
{
  quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
