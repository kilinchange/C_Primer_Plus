/* scan_str.c */
#include <stdio.h>
int main(void)
{
    char name1[11], name2[11];
    int count;

    printf("Please enter 2 name.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s ad %s.\n", count, name1, name2);

    return 0;
}