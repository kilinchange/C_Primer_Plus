#include <stdio.h>
int get_position(char ch);

int main(void)
{
    int c;
    while ((c = getchar()) != -1)
    {
        printf("%d\n", get_position(c));
        while ((c = getchar()) != '\n'){}
    }
    return 0;
}

int get_position(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 1;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 1;
    }
    else
    {
        return -1;
    }
    
}