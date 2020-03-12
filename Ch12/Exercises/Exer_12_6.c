#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        srand((unsigned int) time(0));
        for (int j = 0; j < 1000; j++)
        {
            int tmp = rand() % 10 + 1;
            count[tmp - 1]++;
        }
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", count[i]);
            count[i] = 0;
        }
        printf("\n");
    }

    return 0;
}