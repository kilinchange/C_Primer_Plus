#include <stdio.h>
double power(double a, int num);

int main(void)
{
    double a;
    int num;
    while ((scanf("%lf %d", &a, &num)) == 2)
    {
        printf("%lf\n", power(a, num));
    }
    return 0;
}

double power(double a, int num)
{
    double result = 1;
    int negative = 0;
    if (num < 0)
    {
        negative = 1;
        num = -num;
    }
    while (num--)
    {
        result *= a;
    }
    if (negative)
    {
        return 1 / result;
    }
    else
    {
        return result;
    }
    
}