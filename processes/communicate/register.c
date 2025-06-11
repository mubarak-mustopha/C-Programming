#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void handle(int sig){
    printf("Egbon why u dey comot na!!\n");
    exit(1);
}

int reg_signal(int sig, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL);
}

int main(){

    if(reg_signal(SIGINT, handle) == -1)
        fprintf(stderr, "Can't register interrupt signal: %s\n", strerror(errno));

    char name[50], course[75];

    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter course name: ");
    fgets(course, 75, stdin);

    printf("Welcome %s. You've requested to register for %s.\n", name, course);
}