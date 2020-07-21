/* qsorter.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct names {
    char first[40];
    char last[40];
};

void showarray(const struct names* staff, int n);
int comp(const void * p1, const void * p2);

int main(void)
{
    struct names staff[4] = {{"chenjie", "duan"}, {"chenqi", "duan"}, {"yihan", "chen"}, {"tianlong", "fan"}};    
    showarray(staff, 4);
    qsort(staff, 4, sizeof(struct names), comp);
    showarray(staff, 4);
    return 0;
}

void showarray(const struct names* staff, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", staff[i].last, staff[i].first);
    }
    printf("\n");
}

int comp(const void * p1, const void * p2)
{
    const struct names *ps1 = (const struct names *)p1;
    const struct names *ps2 = (const struct names *)p2;
    int res;
    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}