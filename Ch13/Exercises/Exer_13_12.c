#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char map[10] = {
        ' ', '.', '*', ':', ';', 
        '?', '&', '%', '@', '#'
    };
    
    int nums[20][30];
    FILE *fp1 = fopen("Exer_13_12_input.txt", "r"), *fp2 = fopen("Exer_13_12_output.txt", "r");
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
    for (int i = 0; i < 20; i++)
        fprintf(fp2, "%s\n", digits[i]);
    fclose(fp1);
    fclose(fp2);

    return 0;
}