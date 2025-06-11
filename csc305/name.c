# include <stdio.h>


int main() {
    int size = 20;

    char name[size];
    printf("Type in your name: ");
    fgets(name, size,stdin);

    printf("Welcome to our restaurant %s", name);
}