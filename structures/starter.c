# include <stdio.h>

struct point {
    int x;
    int y;
};

int main() {
    struct point p;
    p.x = 3;
    p.y = 8;
    printf("%d\n", p.x);
    printf("%d\n", p.y);
}
