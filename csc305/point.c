#include <stdio.h>

struct Point {
    int x;
    int y;
};

void move(struct Point * p) {
    p->x++;
    p->y++;
}

int main() {
    struct Point p;
    p.x = 5;
    p.y = 8;
    
    move(&p);
    
    printf("x: %d, y: %d\n",p.x, p.y);
}