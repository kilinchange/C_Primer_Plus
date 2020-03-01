#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    char *end1;
    char *end2;
    long power = strtol(argv[2], &end1, 10);
    double basic = strtod(argv[1], &end2);
    double result = 1;
    for (long i = 0; i < power; i++)
        result *= basic;
    printf("%.3f\n", result);

    return 0;
}