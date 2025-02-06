# include <stdio.h>

int main(){
    int a = 1;

    int * a_pointer = &a;

    a += 1;
    *a_pointer += 4;

    printf("%d\n", a);
    printf("%d\n", a_pointer); // memory address
    printf("%d\n", *a_pointer); // value of a
}