#include <stdio.h>

#define MAX_STUDENT 5
#define NAME_LEN 50
#define ID_LEN 20

struct Student {
    char name[NAME_LEN];
    char matric[ID_LEN];
};

int main(){
    struct Student students[MAX_STUDENT];
    int i;

    for (i = 0; i < MAX_STUDENT ; i++){
        printf("\nStudent %d:\n", i + 1);

        printf("Enter student name:");
        fgets(students[i].name, NAME_LEN, stdin);

        printf("Enter student matric number:");
        fgets(students[i].matric, ID_LEN, stdin);        
    }   

    printf("\n\nStudent Records: \n");
    printf("%-5s %-30s %-20s\n", "No.", "Name", "Matric Number");

    for (i = 0; i < MAX_STUDENT; i++){
        printf("%-5d %-30s %-20s\n", i + 1, students[i].name, students[i].matric);
    }

    return 0;
}