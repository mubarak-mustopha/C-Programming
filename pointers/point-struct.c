# include <stdio.h>

typedef struct {
    int x;
    int y;
} point;


void move(point * p){
    (*p).x++;
    (*p).y++;
}

int main(){
    point p;
    p.x = 2;
    p.y = 5;

    move(&p);

    printf("%d\n", p.x);
    printf("%d\n", p.y);
}