# include <stdio.h>


typedef struct {
    char * name;
    int age;
} person;


int main(){
    person me;
    me.name = "Mubaarock";
    me.age = 22;

    printf("My name is %s and I am %d years old\n", me.name, me.age);
}

