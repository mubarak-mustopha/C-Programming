#include <stdio.h>

void print_big(int num){
    if (num > 10){
        printf("%d is big\n", num);
    }
}


int main(){
    print_big(15);
    print_big(9);
    print_big(7);
    print_big(12);
}