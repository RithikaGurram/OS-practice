#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    int var = 2;
    printf("(pid:%d) var = %d\n", (int) getpid(), var);
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("(pid:%d) var = %d\n", (int) getpid(), var);
        var = var * 2;
        printf("(pid:%d) var = %d\n", (int) getpid(), var);
    }

    else {
        wait(NULL);
        printf("(pid:%d) var = %d\n", (int) getpid(), var);
        var = 1;
        printf("(pid:%d) var = %d\n", (int) getpid(), var);
    }
    return 0;
}