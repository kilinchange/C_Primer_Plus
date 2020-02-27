#include <stdio.h>

void copy_ptr(double * target, double * source, int n);

int main(void)
{
    double source[7] = {3.4, 2.3, 65.3, 2.3, 5.4, 4.5, 3.5};
    double target[3];
    int i;
    copy_ptr(target, source + 2, 3);
    for (i = 0; i < 3; i++)
    {
        printf ("%.1f ", target[i]);
    }

    return 0;
}

void copy_ptr(double * target, double * source, int n)
{
    int i;
    for (i = 0; i < n; i++)
        *(target + i) = *(source + i);
}