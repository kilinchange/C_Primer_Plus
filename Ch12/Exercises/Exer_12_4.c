#include <stdio.h>
int count;
int call_func();

int main()
{
    int n;
    scanf("%d", &n);
    int result = 0;
    while (n--)
        result = call_func();
    printf("%d\n", result);

    return 0;
}

int call_func()
{
    count++;
    return count;
}