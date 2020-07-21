#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void select(int* nums, int size, int count);

int main(void)
{
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    select(nums, 10, 5);

    return 0;
}

void select(int* nums, int size, int count)
{
    int record[size];
    // for (int i = 0; i < size; i++)
    //     record[i] = 0;
    memset(record, 0, sizeof(record));
    srand((unsigned int) time(0));
    for (int i = 0; i < count; i++) {
        int idx = -1;
        while (idx == -1 || record[idx] == 1)
            idx = rand() % size;
        printf("%d ", nums[idx]);
    }
}