# include <stdio.h>

int main(){
    char food[5];

    printf("Enter your favorite food: ");
    // scanf("%s", food);
    fgets(food, sizeof(food), stdin);

    printf("Favorite food: %s\nSize in memory: %li\n", food, sizeof(food));
}