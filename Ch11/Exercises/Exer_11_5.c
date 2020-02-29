#include <stdio.h>
#define SIZE 20
const char * my_strchr(const char *s, char ch);
int main(void)
{
    char input[SIZE];
    char ch;
    while (fgets(input, SIZE, stdin) != NULL && input[0] != '\n')
    {
        ch = getchar();
        const char * ptr = my_strchr(input, ch);
        fputs(ptr, stdout);
        while (getchar() != '\n');
    }

    return 0;
}

const char * my_strchr(const char *s, char ch)
{
    while (*s != '\0' && *s != ch)
    {
        s++;
    }
    if (*s == '\0')
        return NULL;
    else
        return s;
}
