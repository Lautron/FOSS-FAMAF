#include <stdio.h>
#include <unistd.h>

int main(int argv, char ** argc){
    close(0);
    fork();
    putchar('a'); fflush(NULL);
    close(1);
    fork();
    putchar('a'); fflush(NULL);
    close(2);
    fork();
    putchar('a'); fflush(NULL);
}
