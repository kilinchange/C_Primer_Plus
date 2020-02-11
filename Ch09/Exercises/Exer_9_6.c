#include <stdio.h>
void larger_of(double * a, double * b, double * c);

int main(void)
{
    double num1, num2, num3;
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    larger_of(&num1, &num2, &num3);
    printf ("%lf %lf %lf\n", num1, num2, num3);
    return 0;
}

void larger_of(double * a, double * b, double * c)
{
    double tmp1, tmp2, tmp3;
    if (*a > *b)
    {
        if (*a > *c)
        {
            tmp1 = *a;
            if (*b > *c)
            {
                tmp2 = *b;
                tmp3 = *c;
            }
            else
            {
                tmp2 = *c;
                tmp3 = *b;
            }
        }
        else
        {
            tmp1 = *c;
            tmp2 = *a;
            tmp3 = *b;
        }
    }
    else
    {
        if (*c < *b)
        {
            tmp1 = *b;
            if (*a < *c)
            {
                tmp2 = *c;
                tmp3 = *a;
            }
            else
            {
                tmp2 = *a;
                tmp3 = *c;
            }
        }
        else
        {
            tmp1 = *c;
            tmp2 = *b;
            tmp3 = *a;
        }
    }
    *a = tmp3;
    *b = tmp2;
    *c = tmp1;
}