#include <stdio.h>
#include <stdlib.h> // exit
#include <sys/wait.h> // wait
#include <unistd.h> // fork

int main(void) {
    int f = fork();
    if (f < 0) { // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (f == 0) { // child
        printf("hello\n");
    } else { // parent
        wait(NULL);
        printf("goodbye\n");
    }
}

/* much easier :)
*/