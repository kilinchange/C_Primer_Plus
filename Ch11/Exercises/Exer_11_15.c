#include <stdio.h>
#include <ctype.h>
#define SIZE 9

int my_atoi(const char* str);
int main(void)
{
    char str1[SIZE];
    char str2[SIZE];
    fgets(str1, SIZE, stdin);
    fgets(str2, SIZE, stdin);
    int num1 = my_atoi(str1);
    int num2 = my_atoi(str2);
    printf("%d\n", num1 + num2);
    return 0;
}

int my_atoi(const char* str)
{
    int result = 0;
    while (*str != '\n' && isdigit(*str))
    {
        result *= 10;
        result += *str - '0';
        str++;
    }
    if (*str != '\n')
        return 0;
    else
        return result;
    
}