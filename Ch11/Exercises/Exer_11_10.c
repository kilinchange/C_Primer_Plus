#include <stdio.h>
#define SIZE 20
void delete_space(char *s);
int main(void)
{
    char s[SIZE];
    while (fgets(s, SIZE, stdin) != NULL && s[0] != '\n')
    {
        delete_space(s);
        fputs(s, stdout);
    }

    return 0;
}
void delete_space(char *s)
{
    char* curr = s;
    while (*s != '\0')
    {
        if (*s != ' ')
        {
            *curr = *s;
            curr++;
        }
        s++;
    }
    *curr = '\0';
}