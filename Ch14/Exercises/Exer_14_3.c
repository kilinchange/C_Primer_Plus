/* manybook.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int compare_two_books_by_title(const void *a, const void *b);
int compare_two_books_by_price(const void *a, const void *b);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books in index order:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        
        qsort(library, count, sizeof *library, compare_two_books_by_title);
        printf("Here is the list of your books in title order:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        
        qsort(library, count, sizeof *library, compare_two_books_by_price);
        printf("Here is the list of your books in price order:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);        
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

char * s_gets(char *st, int n)
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

int compare_two_books_by_title(const void *a, const void *b)
{
    struct book *pa = (struct book *)a, *pb = (struct book *)b;
    return strcmp(pa->title, pb->title);
}

int compare_two_books_by_price(const void *a, const void *b)
{
    struct book *pa = (struct book *)a, *pb = (struct book *)b;
    if (pa->value != pb->value)
        return pa->value > pb->value ? 1 : -1;
    else
        return 0;
}