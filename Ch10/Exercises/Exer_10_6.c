#include <stdio.h>

void reverse(double nums[], int n);
int main(void)
{
    double nums[5] = {4.1, 5.3, 2.3, 6.3, 2.2};
    int i;
    reverse(nums, 5);
    for (i = 0; i < 5; i++)
    {
        printf ("%.1lf ", nums[i]);
    }
    return 0;
}

void reverse(double nums[], int n)
{
    int i = 0, j = n - 1;
    double tmp;
    while (i < j)
    {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}