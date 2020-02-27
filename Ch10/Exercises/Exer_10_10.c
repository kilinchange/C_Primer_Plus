#include <stdio.h>

void add(int num1[], int num2[], int num3[], int n);
int main(void)
{
    int num1[3] = {1, 2, 3};
    int num2[3] = {2, 3, 4};
    int num3[3];
    add(num1, num2, num3, 3);
    for (int j = 0; j < 3; j++)
        printf("%d ", num3[j]);
    printf("\n");
    return 0;
}

void add(int num1[], int num2[], int num3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        num3[i] = num1[i] + num2[i];
    }
}