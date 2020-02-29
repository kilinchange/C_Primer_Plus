#include <stdio.h>
#define SIZE 20
int is_within(const char *s, char ch);
int main(void)
{
    char input[SIZE];
    char ch;
    while (fgets(input, SIZE, stdin) != NULL && input[0] != '\n')
    {
        ch = getchar();
        int result = is_within(input, ch);
        printf("%d\n", result);
        while (getchar() != '\n');
    }

    return 0;
}

int is_within(const char *s, char ch)
{
    while (*s != '\0' && *s != ch)
    {
        s++;
    }
    if (*s == '\0')
        return 0;
    else
        return 1;
}
