#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;

    char * pvowels = (char *) malloc(5 * sizeof(char));
    int i;

    pvowels[0] = 'A';
    *(pvowels + 1) = 'E';
    pvowels[2] = 'I';
    *(pvowels + 3) = 'O';
    pvowels[4] = 'U';

    for (i = 0; i < 5; i++){
        printf("%c", pvowels[i]);
    }
    printf("\n");
    free(pvowels);
}