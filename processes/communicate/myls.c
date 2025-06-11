#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    char *dir = argv[1];
    FILE *fp = fopen("output.txt", "w");

    pid_t pid = fork();
    if (pid == -1){
        fprintf(stderr,"Can't create child process: %s", strerror(errno));
        return 1;
    }

    if (pid == 0){
        if (dup2(fileno(fp), 1) == -1){
            fprintf(stderr,"Can't redirect standard ouput: %s", strerror(errno));
            return 1;
        }
        if (execlp("ls","ls", dir, NULL) == -1){
            fprintf(stderr,"Can't run program: %s", strerror(errno));
            return 1;
        }
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1){
        fprintf(stderr,"Error waiting for child process: %s", strerror(errno));
        return 1;
    }

    if(WEXITSTATUS(pid_status))
        puts("Error status non-zero");

    printf("We done!!\nCheckout output.txt\n");
}