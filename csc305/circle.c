# include <stdio.h>
# include <stdlib.h>

int main(){
    const float pi = 3.142;

    float r, area;

    printf("Enter the redius of the circle: ");
    scanf("%f", &r);
    area = pi * r * r;

    printf("The area of the circle is %f with memory size %ld", area, sizeof(area));

    return 0;
}