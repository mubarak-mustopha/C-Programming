#include <stdio.h>

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int factorial = 1;
    int i;

    for (i = 0; i < 10; i++){
        factorial *= arr[i];
    }
    printf("The factorial of the array is %d", factorial);
}