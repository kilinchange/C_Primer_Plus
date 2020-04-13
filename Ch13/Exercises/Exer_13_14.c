#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char map[10] = {
        ' ', '.', '*', ':', ';', 
        '?', '&', '%', '@', '#'
    };
    
    int nums[20][30];
    FILE *fp1 = fopen("Exer_13_12_input.txt", "r"), *fp2 = fopen("Exer_13_12_output.txt", "w");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 30; j++)
            fscanf(fp1, "%d", &nums[i][j]);
    char digits[20][31];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++)
            digits[i][j] = map[nums[i][j]];
        digits[i][30] = '\0';
    }            
    for (int i = 1; i < 19; i++)
        for (int j = 1; j < 29; j++) {
            if (min(abs(nums[i][j] - nums[i][j-1]), abs(nums[i][j] - nums[i][j+1]), 
                abs(nums[i][j] - nums[i-1][j-1]), abs(nums[i][j] - nums[i+1][j]) > 1))
                digits[i][j] = map[div_and_round(nums[i][j-1] + nums[i][j+1] + nums[i-1][j] + nums[i+1][j], 4)];
        }

    for (int i = 0; i < 20; i++)
        fprintf(fp2, "%s\n", digits[i]);
    fclose(fp1);
    fclose(fp2);

    return 0;
}

int div_and_round(int a, int b)
{
    int p = a / b;
    return a - b * p < b * (p + 1) - a ? p : p + 1;
}