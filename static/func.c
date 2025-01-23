#include <stdio.h>

static void func(void){
    printf("I am a static function.\n");
}


int main(){
    func();
    return 0;
}