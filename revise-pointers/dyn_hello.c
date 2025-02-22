# include <stdio.h>
# include <stdlib.h>

typedef struct {
    char * name;
    int age;
} person;


int main(){
    person * jay = (person *) malloc(sizeof(person));

    (*jay).name = "Jalal";
    (*jay).age = 8;

    printf("%s is %d now, Laahummo baarik\n", jay->name, jay->age);
    free(jay);
}