#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


void error(char *msg){
    fprintf(stderr, "%s:, %s", msg, strerror(errno));
}

void open_url_v1(char *url){
    char *browser_open_commands[] = {
        "cmd /c start",
        "x-www-browser",
        "open"
    };

    for (int i=0;i < 3; i++){
        pid_t pid = fork();
        if (pid==-1)
            error("Can't create child process");

        if (pid == 0){
            if(execlp(browser_open_commands[i], browser_open_commands[i], url, NULL)==-1)
                error("Can't open browser");
            
        }    
    }
}

void open_url(char *url){
    char launch[255];
    sprintf(launch, "cmd /c start %s", url);
    system(launch);
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
    sprintf(launch, "open '%s'", url);
    system(launch);
}


int main(int argc, char *argv[]){
    char *phrase = argv[1];
    char *pypath = "/home/mubarak/.pyenv/versions/2.7.15/bin/python";
    char *vars[] = {"RSS_FEED=http://feeds.abcnews.com/abcnews/usheadlines", NULL};
    int fd[2];

    if (pipe(&fd) == -1)
        error("Can't create pipe");

    pid_t pid = fork();

    if (pid==-1)
        error("Can't create child process");

    if (!pid){
        // child process
        close(fd[0]);
        dup2(fd[1],1);

        if (execle(pypath,pypath, "../rssgossip.py", "-u",phrase, NULL, vars)==-1)
            error("Can't run script");
    }

    close(fd[1]);
    dup2(fd[0], 0);

    char line[255];
    while(fgets(line, 255, stdin)){
        if(line[0] == '\t'){
            open_url(line + 1);
        }
            // open_url(line + 1);
    }

    return 0;
}
