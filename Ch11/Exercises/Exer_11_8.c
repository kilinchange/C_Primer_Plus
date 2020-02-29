#include <stdio.h>
#define SIZE 20
const char *string_in(const char *s1, const char *s2);
int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    while (fgets(s1, SIZE, stdin) != NULL && s1[0] != '\n')
    {
        fgets(s2, SIZE, stdin);
        const char *result = string_in(s1, s2);
        fputs(result, stdout);
    }
    return 0;
}

const char *string_in(const char *s1, const char *s2)
{
    while (*s1 != '\0')
    {
        const char *ptr1 = s1;
        const char *ptr2 = s2;
        while (*ptr1 != '\0' && *ptr2 != '\0' && *ptr1 == *ptr2)
        {
            ptr1++;
            ptr2++;
        }
        if (*ptr2 == '\n')
            return s1;
        s1++;
    }
    return NULL;
}