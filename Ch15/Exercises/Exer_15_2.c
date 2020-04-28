#include <stdio.h>

int bstoint(const char *);

int main(int argc, char *argv[])
{
    int a1 = bstoint(argv[1]), a2 = bstoint(argv[2]);
    printf("~%s = %d\n", argv[1], ~a1);
    printf("~%s = %d\n", argv[2], ~a2);
    printf("%s & %s = %d\n", argv[1], argv[2], a1 & a2);
    printf("%s | %s = %d\n", argv[1], argv[2], a1 | a2);
    printf("%s ^ %s = %d\n", argv[1], argv[2], a1 ^ a2);
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