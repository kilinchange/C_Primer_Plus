#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void function_a();
void function_b();
void function_c();

int main(void)
{
    char buffer[1024];
    void(*pf[3])(void);
    pf[0] = function_a;
    pf[1] = function_b;
    pf[2] = function_c;
    while (true)
    {
        puts("To choose a function, enter its letter label:");
        puts("a) function_a");
        puts("b) function_b");
        puts("c) function_c");
        puts("d) Quit");
        putchar('\n');
        char choice = tolower(getchar());
        gets(buffer);
        if (choice == 'd') break;
        pf[choice-'a']();
    }
    return 0;
}

void function_a()
{
    printf("I am a.\n");
}

void function_b()
{
    printf("I am b.\n");
}

void function_c()
{
    printf("I am c.\n");
}