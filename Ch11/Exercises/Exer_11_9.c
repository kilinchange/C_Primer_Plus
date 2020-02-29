#include <stdio.h>
#include <string.h>
#define SIZE 20
void reverse_str(char *s);
int main(void)
{
    char s[SIZE];
    while (fgets(s, SIZE, stdin) && s[0] != '\n')
    {
        reverse_str(s);
        fputs(s, stdout);
    }

    return 0;
}
void reverse_str(char* s)
{
    char* end = &s[strlen(s)-2];
    while (s < end)
    {
        char tmp = *s;
        *s = *end;
        *end = tmp;
        s++;
        end--;
    }
}