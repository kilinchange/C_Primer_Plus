#include <stdio.h>

void input(double nums[3][5]);
double ave_single(double nums[5]);
double ave_all(double nums[3][5]);
double find_max(double nums[3][5]);
double output(double ave_each_group[3], double ave_all_nums, double max);
int main(void)
{
    double nums[3][5];
    double ave_each_group[3];
    input(nums);
    for (int i = 0; i < 3; i++)
        ave_each_group[i] = ave_single(nums[i]);
    double ave_all_nums = ave_all(nums);
    double max = find_max(nums);
    output(ave_each_group, ave_all_nums, max);
    return 0;
}

void input(double nums[3][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            scanf("%lf", &nums[i][j]);
    }
}
double ave_single(double nums[5])
{   
    double tot = 0;
    for (int i = 0; i < 5; i++)
        tot += nums[i];
    return tot / 5;
}
double ave_all(double nums[3][5])
{
    double tot = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            tot += nums[i][j];
    return tot / 15;
}
double find_max(double nums[3][5])
{
    double max = nums[0][0];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            max = max > nums[i][j] ? max : nums[i][j];
    return max;
}
double output(double ave_each_group[3], double ave_all_nums, double max)
{
    printf("ave each group:\n");
    for (int i = 0; i < 3; i++)
        printf ("%.1f ", ave_each_group[i]);
    printf("\n");
    printf("ave_all_nums: %.1f\n", ave_all_nums);
    printf ("max:%.1f\n", max);
}