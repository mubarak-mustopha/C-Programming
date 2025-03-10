# include <stdio.h>

int main() {
    char name[40];
    int age;

    printf("Enter your name: ");
    scanf("%39s", name);
    printf("Enter your age: ");
    scanf("%i", &age);


    printf("Welcome %s\n", name);
    printf("You're %i years old\n", age);
}