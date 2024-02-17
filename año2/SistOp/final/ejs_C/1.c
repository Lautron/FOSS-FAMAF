#include <stdio.h>
#include <unistd.h>

int main(int argv, char ** argc){
    for(int i =0; i <argv; i++){
        close(argv-i);
        fork();
        putchar('a'); fflush(NULL);
    }
}
