# include <stdio.h>

struct Person {
    char name[50];
    int age;
    int houseNumber;
    float height;
};


int main() {
    struct Person user;

    printf("Enter your info in the format specified below:\nname, age, houseNumber, height: ");
    scanf("%49s, %d, %d, %f", user.name, &user.age, &user.houseNumber, &user.height);

    printf("You name is %s with height %f, living in street number %d and youre %d years old",user.name,user.height, user.houseNumber, user.age);
}