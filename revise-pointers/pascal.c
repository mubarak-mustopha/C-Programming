#include <stdio.h>
#include <stdlib.h>

int main() {
    int nrows = 3;
    int i,j;

    int **pascal = (int **) malloc(nrows * sizeof(int *));

    
    for (i = 0; i < nrows; i++){
        pascal[i] = (int *) malloc((i + 1) * sizeof(int));
    }

    pascal[0][0] = 1;

    pascal[1][0] = 1;
    pascal[1][1] = 1;

    pascal[2][0] = 1;
    pascal[2][1] = 2;
    pascal[2][2] = 1;

    for(i = 0; i < nrows; i++){
        // check learn-c.org implementation
        for(j =0;j <= i ; j++){
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    free(pascal[0]);
    free(pascal[1]);
    free(pascal[2]);

    free(pascal);
}