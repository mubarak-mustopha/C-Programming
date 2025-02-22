# include <stdio.h>


void addOne(int *n){
    *n += 1;
}


int main(){
    int a = 23;

    addOne(&a);
    printf("a is now %d\n", a);
}