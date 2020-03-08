#include <stdio.h>
#include "test.h"

int main(void)
{
    printf ("%d", count[0]);
    count[0] = 1;
    output();

    return 0;
}