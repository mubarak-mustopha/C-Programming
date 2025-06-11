#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

void error(char *msg){
    fprintf(stderr,"%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]){

    char *phrase = argv[1];
    char *pypath = "/home/mubarak/.pyenv/versions/2.7.15/bin/python";
    char *vars[] = {"RSS_FEED=http://www.theguardian.com/world/usa/rss", NULL};
    FILE *fp = fopen("stories.txt", "w");

    if(!fp){
        error("Can't open  stories.txt");
    }

    pid_t pid = fork();

    if(pid == -1){
        error("Can't create process");
    }

    if(pid==0){ 
        // child process
        if(dup2(fileno(fp),1) == -1){
            error("Can't redirect standard output");
        }

        if (execle(pypath, pypath, "../rssgossip.py",phrase, NULL, vars) == -1){
            error("Can't run script");
        }
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1){
        error("Error waiting for child process.");
    }

    if(WEXITSTATUS(pid_status))
        puts("Error status non-zero");

    return 0;
}