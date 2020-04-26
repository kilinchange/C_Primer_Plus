#include <stdio.h>
#include <math.h>
#define LEN 100

void transform(double *source, double *target, int size, double pf (double));
void print_arr(double *a, int size);
double add_one(double a);
double sub_one(double a);

int main()
{
    double source[LEN], target[LEN];
    for (int i = 0; i < 100; i++)  source[i] = i+1;

    transform(source, target, LEN, sin);
    printf("sin:\n");
    print_arr(target, LEN);

    transform(source, target, LEN, sqrt);
    printf("sqrt:\n");
    print_arr(target, LEN);

    transform(source, target, LEN, add_one);
    printf("add_one:\n");
    print_arr(target, LEN);

    transform(source, target, LEN, sub_one);
    printf("sub_one:\n");
    print_arr(target, LEN);

    return 0;
}

void transform(double *source, double *target, int size, double pf(double))
{
    for (int i = 0; i < size; i++)
        target[i] = pf(source[i]);
}

void print_arr(double *a, int size)
{
    for (int i = 0; i < size; i++)
        printf("%f ", a[i]);
    putchar('\n');
}

double add_one(double a)
{
    return a + 1;
}

double sub_one(double a)
{
    return a - 1;
}
