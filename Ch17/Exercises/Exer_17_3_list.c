/* list_c */
#include <stdio.h>
#include <stdlib.h>
#include "Exer_17_3_list.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List * plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else    
        return false;
}

bool ListIsFull(const List *plist)
{
    bool full;
    if (plist->items == MAXSIZE)
        full = true;
    else    
        full = false;

    return full;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
        return false;
    plist->entries[plist->items] = item;
    plist->items++;
    return true;
}

void Traverse(const List * plist, void(*pfun)(Item item))
{
    for (int i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);
}

void EmptyTheList(List * plist)
{
    plist->items = 0;
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}