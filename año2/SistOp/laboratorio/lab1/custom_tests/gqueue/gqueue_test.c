#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

// Compilation and execution options:
// - To view program output and fails
//      gcc gqueue_test.c -o ejecutable_gqueue_test `pkg-config --cflags --libs glib-2.0` && ./ejecutable_gqueue_test
// - To view memory leaks and heaps (only for us)
//      gcc gqueue_test.c -o ejecutable_gqueue_test `pkg-config --cflags --libs glib-2.0` && valgrind --leak-check=full ./ejecutable_gqueue_test
// - To view memory leaks and all heaps information
//      gcc gqueue_test.c -o ejecutable_gqueue_test `pkg-config --cflags --libs glib-2.0` && valgrind --leak-check=full -v --track-origins=yes ./ejecutable_gqueue_test

int main(void){
    GQueue * test = NULL;
    test = g_queue_new();
    g_queue_free_full(test,free);
    return 0;
}