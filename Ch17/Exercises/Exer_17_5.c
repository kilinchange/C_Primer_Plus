#include <stdio.h>
#include "Exer_17_5_stack.h"

int main(void)
{
    char * str[MAXSTACK];
    Stack s;
    Item temp;

    InitializeStack(&s);
    printf("Please enter a string:\n");
    while (s_gets(str, MAXSTACK) != NULL && str[0] != '\0')
    {
        for (int i = 0; str[i] !='\0'; i++)
        {
            temp.ch = str[i];
            if (StackIsFull(&s))
            {
                printf("Putting %c in stack.", temp.ch);
                EnStack(temp, &s);
            }
            else
                printf("Stack is full!\n");

        }

        printf("Show characters by negtivate order:\n");

        while (DeStack(&temp, s))
        {
            printf("%c", temp.ch);
        }
        printf("\nFinish showing!\n");
    }
    printf("Bye!\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}