#include <stdio.h>
#include <string.h>

int main(){
    //ex1 char str[] = {'S','c','a','l','a','r', '.','\0'};
    //ex2 char str[] = "Scalar.";
    // ex3 char str[8];
    // strcpy(str, "Scalar.");

    //ex4 char str[50];
    
    // printf("Type your message for scaler: ");
    // fgets(str, sizeof(str),stdin);

    char str[100] = "Gooday";
    int index = 4;
    char ch = 'I';

    int len = strlen(str);
    int i ;

    for (i = len; i > index ;i--) {
        str[i] = str[i - 1];
    }

    str[index] = ch;

    printf("%s has length %ld\n", str, strlen(str));
}