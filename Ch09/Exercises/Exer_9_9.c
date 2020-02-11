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
    if (num == 0)
    {
        return 1;
    }
    else if (num > 0)
    {
        return a * power(a, num - 1);
    }
    else
    {
        return a * power(a, num + 1);
    }
    
}