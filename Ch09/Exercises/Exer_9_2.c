#include <stdio.h>
void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;
    scanf("%c %d %d", &ch, &i, &j);
    chline(ch, i, j);
    return 0;
}

void chline(char ch, int i, int j)
{
    for (int m = j; m > 0; m--)
    {
        for (int n = i; n > 0; n--)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}