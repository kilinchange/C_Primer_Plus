#include <stdio.h>

void copy_arr(double target[], double source[], int n);

int main(void)
{
    double source[2][3] = {{1.3,2.2,3.3}, {3.5,4.4,5.7}};
    double target[2][3];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        copy_arr(target[i], source[i], 3);
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.1lf ", target[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void copy_arr(double target[], double source[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        target[i] = source[i];
}