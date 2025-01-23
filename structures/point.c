# include <stdio.h>

typedef struct 
{
    int x;
    int y;
    int z;
} point_3d;

int main(){
    point_3d p; 
    p.x = 2;
    p.y = 5;
    p.z = 3;
    printf("x=%d\ny=%d\nz=%d", p.x, p.y, p.z);
}