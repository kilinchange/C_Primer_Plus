#include <stdio.h>
void copy_vla(int r, int c, double target[r][c], double source[r][c]);
void output_vla(int r, int c, double array[r][c]);
int main()
{
    double source[3][5] = {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 }
    };
    double target[3][5];
    copy_vla(3, 5, target, source);
    output_vla(3, 5, source);
    output_vla(3, 5, target);
    return 0;
}
void copy_vla(int r, int c, double target[r][c], double source[r][c])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            target[i][j] = source[i][j];
}
void output_vla(int r, int c, double array[r][c])
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%5.2f ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}
