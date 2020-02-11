#include <stdio.h>
void larger_of(double * a, double * b);

int main(void)
{
    double num1, num2;
    scanf("%lf %lf", &num1, &num2);
    larger_of(&num1, &num2);
    printf ("%lf %lf\n", num1, num2);
    return 0;
}

void larger_of(double * a, double * b)
{
    double tmp;
    tmp = *a > *b ? *a : *b;
    *a = tmp;
    *b = tmp;
}