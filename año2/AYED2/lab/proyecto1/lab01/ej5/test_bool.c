#include <stdio.h>   /* printf()...       */
#include <stdlib.h>  /* EXIT_SUCCESS      */
#include <stdbool.h> /* bool, true, false */

int main(void) {
    bool b1, b2, b3, b4;
    b1 = true;
    b2 = false;
    b3 = b1 || b2;
    b4 = b1 && b2;
    printf("b1: %d\n"
           "b2: %d\n"
           "b3 == b1 or b2: %d\n"
           "b4 == b1 and b2: %d\n"
           "", b1, b2, b3, b4);
    return EXIT_SUCCESS;
}

