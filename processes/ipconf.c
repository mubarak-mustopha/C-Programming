#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(){
    if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1){
        if(execlp("ipconfig", "ipconfig", NULL) == -1){
            fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));
            return 1;
        }
    }

    return 0;
}