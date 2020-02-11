#include <stdio.h>
void to_base_n(int num, int base);

int main(void)
{
    int num, base;
    scanf("%d %d", &num, &base);
    to_base_n(num, base);
    return 0;
}

void to_base_n(int num, int base)
{
    int tmp = num % base;
    if (num >= base)
        to_base_n(num / base, base);
    printf("%d", tmp);
}