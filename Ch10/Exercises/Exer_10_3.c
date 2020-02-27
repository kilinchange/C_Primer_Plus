#include <stdio.h>

int findMax(int * nums, int n);
int main(void)
{
    int nums[5] = {4,3,5,2,1};
    printf("%d\n", findMax(nums, 5));

    return 0;
}

int findMax(int * nums, int n)
{
    int ans = nums[0];
    int i;
    
    for (i = 0; i < n; i++)
        if (nums[i] > ans)
            ans = nums[i];
    
    return ans;
}