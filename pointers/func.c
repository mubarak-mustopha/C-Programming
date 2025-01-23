# include <stdio.h>

void addOne(int *n){
    *n  += 1; 
}

int main(){
    int num = 4;

    printf("Before, num = %d\n", num);
    addOne(&num);
    printf("After, num = %d\n", num);
}