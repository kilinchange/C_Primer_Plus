#include <stdio.h>

int count_1s_in_a_number(int number);

int main(void)
{
    printf("%d\n", count_1s_in_a_number(12));
    printf("%d\n", count_1s_in_a_number(2));

    return 0;
}

int count_1s_in_a_number(int number)
{
    int mask = 0x1, count = 0;
    while (mask != 0x0) {
        if (number & mask) count++;
        mask <<= 1;
    }
    return count;
}