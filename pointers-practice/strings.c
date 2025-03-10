# include <stdio.h>


void print_message(char msg[]){
    printf("%s is located at %p in memory\n", msg, msg);
}

void fortune_cookie(char msg[]){
    printf("Message reads: %s\n", msg);
    printf("Message occupies %li bytes of memory\n", sizeof(msg));
}

int main(){
    char qoute[] = "Cookies make u fat";
    print_message(qoute);
    fortune_cookie(qoute);
}