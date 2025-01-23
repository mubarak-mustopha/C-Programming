#include <stdio.h>

int main(){
    int i;
    int arr[5] = {0,1,2,3,4};
    int sum = 0;

    for (i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("The sum equals %d\n", sum);
}