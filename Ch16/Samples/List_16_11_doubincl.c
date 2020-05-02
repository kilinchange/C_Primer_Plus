// doubincl.c
#include <stdio.h>
#include "List_16_10_names.h"
#include "List_16_10_names.h"

int main()
{
    names winner = { "Less", "Ismoor" };
    printf("The winner is %s %s.\n", winner.first,
        winner.last);
    return 0;
}