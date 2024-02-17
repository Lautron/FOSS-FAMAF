#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void print_data(data_t d)
{
  printf("NOMBRE: %s\n"
	 "EDAD  : %d años\n"
	 "ALTURA: %d cm\n\n",
      d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t* d)
{
  /* COMPLETAR */
  for (unsigned int i = 0; i < NAME_SIZE; ++i) {
    d->name[i] = new_name[i];
  }
}

int main(void)
{

  data_t messi = { "Leo Messi", 34, 169 };
  print_data(messi);
  name_t messi_full_name = "Lionel Messi";
  /* COMPLETAR */
  set_name(messi_full_name, &messi);
  print_data(messi);

  return EXIT_SUCCESS;
}
