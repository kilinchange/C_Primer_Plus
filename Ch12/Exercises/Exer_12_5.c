#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nums[100];
    int tmp;
    for (int i = 0; i < 100; i++)
        nums[i] = rand() % 10 + 1;
    for (int i = 0; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (nums[i] < nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 100; i++)
        printf("%d ", nums[i]);

    return 0;
}