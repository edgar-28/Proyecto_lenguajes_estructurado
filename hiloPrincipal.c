//
// Created by edgar on 17/7/20.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    int pid;
    printf("Parent: Hello, World!\n");
    pid = fork();
    if (pid == 0) {
        printf("Entro en IF\n");
        char *arg[] = {"./progra", "0", "0", "1", "5", "1", ">", "archivo.txt", NULL};
        execvp(arg[0], arg);
    } else if (pid == -1)
        perror("fork error");
}