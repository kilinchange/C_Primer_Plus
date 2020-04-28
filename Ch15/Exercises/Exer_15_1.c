#include <stdio.h>

int bstoint(const char *);

int main(void)
{
    char * pbin = "01001001";

    printf("%d\n", bstoint(pbin));
    return 0;
}

int bstoint(const char * s)
{
    int result = 0;
    while (*s != '\0') {
        result <<= 1;
        result += *s - '0';
        s++;
    }
    return result;
}