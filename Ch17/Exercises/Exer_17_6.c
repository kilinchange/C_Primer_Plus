#include <stdio.h>

int if_find(int * nums, int n, int num);

int main(void)
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", if_find(nums, 10, 7));
    return 0;
}

int if_find(int * nums, int n, int num)
{
    int low = 0, high = n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > num)
            high = mid;
        else if (nums[mid] < num)
            low = mid + 1;
        else
            return 1;
    }
    return 0;
}