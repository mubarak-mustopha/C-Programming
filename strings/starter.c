#include <stdio.h>
#include <string.h>


int main() {
    char * name = "John Smith";
    int age = 27;

    printf("%s is %d years old.\n", name, age);
    printf("%s is of length %d.", name,strlen(name));
}

