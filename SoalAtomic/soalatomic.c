#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define size 25

int main(){
    int p1[2], p2[2];
    char shadow[] = "i am shadow";
    char atomic[] = "i am atomic";

    pipe(p1);
    pipe(p2);

    pid_t child = fork();
    if(child > 0) {
        char msg[size + 1];

        write(p1[1], shadow, strlen(shadow) + 1);

        read(p2[0], msg, size);
        printf("%s\n", msg);
    }
    else {
        char msg[size + 1];

        read(p1[0], msg, size);
        printf("%s\n", msg);

        write(p2[1], atomic, strlen(atomic) + 1);
    }
}