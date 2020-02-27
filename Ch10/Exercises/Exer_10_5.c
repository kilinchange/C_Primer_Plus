#include <stdio.h>

double findDiff(double nums[], int n);
int main(void)
{
    double nums[5] = {4.3, 3.2, 5.4, 2.3, 4.5};
    printf("%.1f\n", findDiff(nums, 5));
    return 0;
}

double findDiff(double nums[], int n)
{
    double max = nums[0], min = nums[0];
    int i;
    for (i = 0; i < n; i++)
    {
        max = max > nums[i] ? max : nums[i];
        min = min < nums[i] ? min : nums[i];
    }
    printf("%.1f %.1f\n", max, min);
    return max - min;
}