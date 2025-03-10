# include <stdio.h>

int main(){
    char first_name[20];
    char last_name[20];


    printf("Enter first and last name: ");
    scanf("%19s %19s", first_name, last_name);
    printf("Lastname: %s Firstname:%s\n", last_name, first_name);
}