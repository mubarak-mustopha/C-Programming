# include <stdio.h>

typedef struct {
    char * name;
    int age;
}person; 


void birthday(person * p){
    p->age++;
}

int main(){
    person me;

    me.name = "Msquare";
    me.age = 21;

    birthday(&me);
    printf("I will be %d years old by Sept 11\n", me.age);
}