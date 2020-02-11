#include <stdio.h>
double min(double a, double b);

int main(void)
{
    double num1, num2;
    scanf("%lf %lf", &num1, &num2);
    printf("%lf\n", min(num1, num2));
    return 0;
}

double min(double a, double b)
{
    return a < b ? a : b;
}