#include "truco.h"
#include <stdio.h>

truco_card ask_for_card()
{
  unsigned int num;
  char palo;
  printf("Ingrese el numero y el palo de la carta separados por un espacio\n Posibles palos: (e)espada, (b)ast, (c)opa, (o)ro\n");
  scanf("%u %c", &num, &palo);
  return truco_card_new(num, palo);
}

int main(void)
{
  truco_card c1, c2;
  c1 = ask_for_card();
  c2 = ask_for_card();
  if (truco_card_win(c1, c2)) {
    truco_card_dump(c1);
    truco_card_dump(c2);
  } else if (truco_card_tie(c1, c2)) {
    printf("!La mano está parda!\n");
    truco_card_dump(c1);
    truco_card_dump(c2);
  } else {
    truco_card_dump(c2);
    truco_card_dump(c1);
  }
  c1 = truco_card_destroy(c1);
  c2 = truco_card_destroy(c2);
  return 0;
}
