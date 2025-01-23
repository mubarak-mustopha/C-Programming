# include <stdio.h>

typedef struct {
    char * name;
    int age;
} person;

void birthday(person * p){
    p->age++;
}

int main(){
    person muby;
    muby.name = "Mubaarock";
    muby.age = 21;

    birthday(&muby);
    printf("%d", muby.age);
}