#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int score = 0;

void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

int reg_sig(int sig, void (*handler) (int)){
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL);
}

void end_game(){
    printf("Game over!!\nFinal score is %i\n", score);
    exit(0);
}

void times_up(){
    printf("\nTime's up\n");
    raise(SIGINT);
}

int main(){
    reg_sig(SIGALRM, times_up);
    reg_sig(SIGINT, end_game);

    srand(time(NULL));

    while(1){
        int num1 = rand() % 13;
        int num2 = rand() % 13;
        char answer[4];

        alarm(5);
        printf("%i times %i equals: ", num1, num2);
        fgets(answer, 4, stdin);

        if (atoi(answer) != num1 * num2)
            end_game();
        score++;
    }
}