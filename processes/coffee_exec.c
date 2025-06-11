#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
    char *env[] = {"FOOD=rice and stew;EXTRA=fish and pepsi",NULL};
    if (execle("./coffee", "./coffee", NULL, env) == -1){
        fprintf(stderr, "Can't create order: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}