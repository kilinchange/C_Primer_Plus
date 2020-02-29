#include <stdio.h>
#define SIZE 20
char * mystrncpy(char *s1, const char * s2, int n);
int main()
{
    char s1[SIZE];
    char s2[SIZE];
    int n;
    while (fgets(s1, SIZE, stdin) != NULL && s1[0] != '\n')
    {
        fgets(s2, SIZE, stdin);
        scanf("%d", &n);
        mystrncpy(s1, s2, n);
        printf("%s\n", s1);
        while (getchar() != '\n');
    }
    return 0;
}
char * mystrncpy(char * s1, const char * s2, int n)
{
    while (*s1 != '\0' && *s1 != '\n')
        s1++;
    for (int i = 0; i < n; i++)
    {
        *s1 = *s2;
        if (*s2 == '\0')
            break;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return s1;
}