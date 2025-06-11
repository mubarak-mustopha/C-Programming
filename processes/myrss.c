#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *feeds[] = {"http://feeds.nbcnews.com/feeds/topstories",
                        "http://feeds.abcnews.com/abcnews/usheadlines",
                        "http://www.theguardian.com/world/usa/rss"
                        };

    char *pypath = "/home/mubarak/.pyenv/versions/2.7.15/bin/python";
    char *query = argv[1];

    int times = 3;                

    for (int i=0;i < times;i++){
        char var[255]; 

        sprintf(var,"RSS_FEED=%s", feeds[i]);

        char *vars[2] = {var, NULL};
        if(execle(pypath, pypath, "./rssgossip.py",query,NULL,vars) == -1){
            fprintf(stderr, "Can't run program: %s\n", strerror(errno));
        }
    }
}