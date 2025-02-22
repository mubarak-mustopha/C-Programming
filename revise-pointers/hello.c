# include <stdio.h>


int main(){
    int a = 10;

    int *p_a = &a;
    *p_a = 40;

    printf("Pointer to a at memory location: %p\n", p_a);
    printf("Data contained in %p is now %d\n", p_a, a);
}