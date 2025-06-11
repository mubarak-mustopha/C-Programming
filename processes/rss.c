#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void error(char *msg){
    fprintf(stderr,"%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]){
        char *feeds[] = {"http://feeds.nbcnews.com/feeds/topstories",
                        "http://feeds.abcnews.com/abcnews/usheadlines",
                        "http://www.theguardian.com/world/usa/rss"
                        };

        int times = 3;
        char *pypath = "/home/mubarak/.pyenv/versions/2.7.15/bin/python";
        char *phrase = argv[1];
        int i;

        for(i=0;i<times;i++){
            char var[255];
            sprintf(var, "RSS_FEED=%s", feeds[i]);

            char *vars[] = {var, NULL};

            pid_t pid = fork();
            if (pid == -1){
                error("Can't fork process");
            }
            if (pid == 0){
                if (execle(pypath, pypath,"./rssgossip.py",phrase,NULL,vars) == -1){
                    error("Can't run script");
                }
            }
        }
        return 0;
}