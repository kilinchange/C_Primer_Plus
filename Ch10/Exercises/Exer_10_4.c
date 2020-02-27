#include <stdio.h>

int findIndex(double nums[], int n);
int main(void)
{
    double nums[5] = {4,3,5,7,2};
    printf ("%d\n", findIndex(nums, 5));

    return 0;
}

int findIndex(double nums[], int n)
{
    int i;
    int index = 0, max = nums[0];
    for (i = 0; i < n; i++)
    {
        if (nums[i] > max)
            {
                index = i;
                max = nums[i];
            }
    }
    return index;
}