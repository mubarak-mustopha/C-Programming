#include <stdio.h>

int main(){
    char vowels[][5] = {
        {'A','E','I','O','U'},
        {'a','e','i','o','u'}
    };

    printf("%c", vowels[0][2]);
}