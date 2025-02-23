# include <stdio.h>

int factorial(int n){
    if (n == 0 | n == 1){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main(){
    printf("The factorial of 5 is %d\n", factorial(5));
}