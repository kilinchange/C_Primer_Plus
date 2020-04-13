#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char map[10] = {
        ' ', '.', '*', ':', ';', 
        '?', '&', '%', '@', '#'
    };
    
    int n, m;
    scanf("%d %d", &n, &m);
    int nums[n][m];
    FILE *fp1 = fopen("Exer_13_12_input.txt", "r"), *fp2 = fopen("Exer_13_12_output.txt", "r");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(fp1, "%d", &nums[i][j]);
    char digits[n][m+1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            digits[i][j] = map[nums[i][j]];
        digits[i][m] = '\0';
    }
    for (int i = 0; i < n; i++)
        fprintf(fp2, "%s\n", digits[i]);
    fclose(fp1);
    fclose(fp2);

    return 0;
}