#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exer_17_7_tree.h"

void print_menu();
void print_item(Item item);

int main(void)
{
    FILE *fp;
    char file_name[SLEN] = "words.txt";
    if ((fp = fopen("words.txt", "r")) == NULL)
    {
        printf("Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    char word[SLEN];
    Tree words;
    InitializeTree(&words);
    while (fscanf(fp, "%s", word) == 1)
    {
        puts(word);
        Item temp;
        strcpy(temp.word, word);
        temp.count = 1;
        Item * res;
        if ((res = InTree(&temp, &words)) == NULL)
            AddItem(&temp, &words);
        else
            res->count++;
    }
    fclose(fp);
    char c;
    print_menu();
    while((c = getchar()) != '3')
    {
        switch (c)
        {
        case '1':
            Traverse(&words, print_item);
            break;
        case '2':
            printf("Enter a word: ");
            scanf("%s", word);
            Item temp;
            strcpy(temp.word, word);
            temp.count = 1;
            Item * res = InTree(&temp, &words);
            int count = (res == NULL) ? 0 : res->count;
            printf("%s appears %d times in this file.", word, count);
            break;
        default:
            break;
        }
        while ((c = getchar()) != '\n');
        print_menu();
    }
    return 0;
}

void print_menu()
{
    printf("\n1) show words and theri count.\n");
    printf("2) Query for some word's count.\n");
    printf("3)exit\n\n");
}

void print_item(Item item)
{
    printf("%s: %d\n", item.word, item.count);
}
