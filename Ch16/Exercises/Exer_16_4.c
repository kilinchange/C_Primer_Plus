#include <stdio.h>
#include <time.h>

#define TIME(X, Y) (((Y)-(X))/CLOCKS_PER_SEC)

void loop(double time);

int main(void)
{
    loop(10);
    return 0;
}

void loop(double duration)
{
    clock_t start = clock();
    clock_t end = start;
    while (TIME(start, end) < duration) {
        end = clock();
    }
}