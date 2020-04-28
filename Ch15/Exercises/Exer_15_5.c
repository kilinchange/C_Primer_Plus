#include <stdio.h>
#include <limits.h>

typedef unsigned int uint32_t;

uint32_t rotate_I(uint32_t num, int n);
char * itobs(int n, char *ps);

int main(void)
{
    char bin_str[8 * sizeof(uint32_t)];
    printf("original val is %u: %s\n", 123, itobs(123, bin_str));
    uint32_t rotated = rotate_I(123, 30);
    printf("rotated val is %u: %s\n", rotated, itobs(rotated, bin_str));

    return 0;
}

uint32_t rotate_I(uint32_t num, int n)
{
    uint32_t mask = 1 << 31;
    while (n--)
    {
        if (mask & num) num = (num << 1) + 1;
        else num <<= 1;
    }
    return num;
}

char * itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--,n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}