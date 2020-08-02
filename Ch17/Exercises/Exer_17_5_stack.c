#include<stdio.h>
#include<stdlib.h>
#include "Exer_17_5_stack.h"

void InitializeStack(Stack * ps)
{
    ps->items = 0;
}

bool StackIsFull(const Stack * ps)
{
    return ps->items == MAXSTACK;
}

bool StackisEmpty(const Stack * ps)
{
    return ps->items == 0;
}

int StackItemCount(const Stack * ps)
{
    return ps->items;
}

bool EnStack(Item item, Stack * ps)
{
    if (ps->items == MAXSTACK)
        return false;
    ps->entries[ps->items] = item;
    ps->items++;
    return true;
}

bool DeStack(Item * item, Stack * ps)
{
    if (ps->items == 0)
        return false;
    *item = ps->entries[ps->items - 1];
    ps->items--;
    return true;
}

void EmptyTheStack(Stack * ps)
{
    ps->items = 0;
}