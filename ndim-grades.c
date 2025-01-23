#include <stdio.h>

int main(){
    int i, j;

    int grades[2][5] = {
        {80,76,84,75,82},
        {90,95,86,87,93}
    };

    for (i = 0;i < 2;i++){
        int sum = 0;
        for (j=0;j < 5; j++){
            sum += grades[i][j];
        }
        
        float avg = sum / 5;
        printf("The avg if %d is %f\n", i, avg);
    }
}