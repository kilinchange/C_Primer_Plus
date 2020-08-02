/* films2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE   45

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
    struct film * pre;
};
char * s_gets(char * st, int n);
void show_by_positive_order(struct film * head);
void show_by_negtive_order(struct film * head);

int main(void)
{
    struct film * head = NULL, *tail = NULL;
    struct film * prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
            tail = current;
            current->pre = NULL;
        }
        else
        {
            prev->next = current;
            current->pre = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    if (head == NULL)
        printf("No data entered.");
    else {
        printf("Here is the movie list:\n");
        printf("\nShow by positive order:\n");
        show_by_positive_order(head);
        printf("\nshow by negtive order:\n");
        show_by_negtive_order(tail);
    }

    current = head;
    while (current != NULL)
    {   
        head = current->next;
        free(current);
        current = head;
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

void show_by_positive_order(struct film * head)
{
    struct film * current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n",
            current->title, current->rating);
        current = current->next;
    }
}

void show_by_positive_order(struct film * tail)
{
    struct film * current = tail;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n",
            current->title, current->rating);
        current = current->pre;
    }
}