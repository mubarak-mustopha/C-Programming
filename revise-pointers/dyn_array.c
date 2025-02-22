# include <stdio.h>
# include <stdlib.h>

int main(){
    int n = 5;
    char * pvowels = (char *) malloc(n * sizeof(char));

    pvowels[0] = 'A';
    *(pvowels + 1) = 'E';
    pvowels[2] = 'I';
    *(pvowels + 3) = 'O';
    pvowels[4] = 'U';

    int i;
    for (i = 0; i<5; i++) {
        printf("%c", pvowels[i]);
    }

    printf("\n");
    free(pvowels);
}