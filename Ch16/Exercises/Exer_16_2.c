#include <stdio.h>

#define HARMONY(X, Y) 1/((1.0/(X)+1.0/(Y))/2.0)

int main(void)
{
    printf("%f\n", HARMONY(2, 3));

    return 0;
}