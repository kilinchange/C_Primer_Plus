#include <stdio.h>
double harmonic_mean(double a, double b);

int main(void)
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", harmonic_mean(a, b));
    return 0;
}

double harmonic_mean(double a, double b)
{
    return 2 / (1/a + 1/b);
}