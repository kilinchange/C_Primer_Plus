#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef struct item
{
    char ch;
} Item;

#define MAXSTACK 20

typedef struct stack
{
    Item entries[MAXSTACK];
    int items;
} Stack;

void InitializeStack(Stack * ps);

bool StackIsFull(const Stack * ps);

bool StackisEmpty(const Stack * ps);

int StackItemCount(const Stack * ps);

bool EnStack(Item item, Stack * ps);

bool DeStack(Item * item, Stack * ps);

void EmptyTheStack(Stack * ps);

#endif