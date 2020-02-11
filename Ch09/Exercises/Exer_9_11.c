#include <stdio.h>
int Fibonacci(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Fibonacci(n));
    return 0;
}

int Fibonacci(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
    {
        int pre = 1;
        int prepre = 1;
        int curr = 0;
        for (int i = 0; i < n - 2; i++)
        {
            curr = pre + prepre;
            prepre = pre;
            pre = curr;
        }
        return curr;
    }
}