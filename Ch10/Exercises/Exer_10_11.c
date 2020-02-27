#include <stdio.h>

void convert_vla(int r, int c, int nums[r][c]);
void output_vla(int r, int c, int nums[r][c]);
int main(void)
{
    int nums[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    convert_vla(3, 5, nums);
    output_vla(3, 5, nums);
    return 0;
}

void convert_vla(int r, int c, int nums[r][c])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            nums[i][j] *= 2;
}

void output_vla(int r, int c, int nums[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", nums[i][j]);
        printf("\n");
    }
}