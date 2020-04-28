#include <stdio.h>

int check_bit(int num, int pos);

int main(void)
{
    printf("%d\n", check_bit(3, 1));
    printf("%d\n", check_bit(34, 3));

    return 0;
}

int check_bit(int num, int pos)
{
    int mask = 0x1;
    while (pos){
        mask <<= 1;
        pos--;
    }
    if (num & mask) return 1;
    else return 0;
}