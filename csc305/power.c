#include <stdio.h>
#include <math.h>

int main() {
    double base, exp, result;

    printf("Enter input the format: base**exp");
    scanf("%lf**%lf", &base, &exp);

    result = pow(base, exp);
    printf("%lf**%lf = %lf\n", base, exp, result);
}