#include <stdio.h>

void input(int r, int c, double nums[r][c]);
double ave_single(int n, double nums[n]);
double ave_all(int r, int c, double nums[r][c]);
double find_max(int r, int c, double nums[r][c]);
double output(int n, double ave_each_group[n], double ave_all_nums, double max);
int main(void)
{
    double nums[3][5];
    double ave_each_group[3];
    input(3, 5, nums);
    for (int i = 0; i < 3; i++)
        ave_each_group[i] = ave_single(3, nums[i]);
    double ave_all_nums = ave_all(3, 5, nums);
    double max = find_max(3, 5, nums);
    output(3, ave_each_group, ave_all_nums, max);
    return 0;
}

void input(int r, int c, double nums[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            scanf("%lf", &nums[i][j]);
    }
}
double ave_single(int n, double nums[n])
{   
    double tot = 0;
    for (int i = 0; i < n; i++)
        tot += nums[i];
    return tot / n;
}
double ave_all(int r, int c, double nums[r][c])
{
    double tot = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tot += nums[i][j];
    return tot / (r * c);
}
double find_max(int r, int c, double nums[r][c])
{
    double max = nums[0][0];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            max = max > nums[i][j] ? max : nums[i][j];
    return max;
}
double output(int n, double ave_each_group[n], double ave_all_nums, double max)
{
    printf("ave each group:\n");
    for (int i = 0; i < n; i++)
        printf ("%.1f ", ave_each_group[i]);
    printf("\n");
    printf("ave_all_nums: %.1f\n", ave_all_nums);
    printf ("max:%.1f\n", max);
}