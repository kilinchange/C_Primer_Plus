#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 10

int output_menu(void);
void output_str(char* strings [], int num);
void str_sort_by_ascii(char *strings [], int num);
void str_sort_by_len(char *strings [], int num);
void str_sort_by_first_word_len(char *strings [], int num);

int main(void)
{
    char input[LIM][SIZE];
    char *ptr_ascii[LIM];
    char *ptr_len[LIM];
    char *ptr_word_len[LIM];
    int count = 0;

    while (count < LIM && fgets(input[count], SIZE, stdin) != NULL)
    {
        ptr_ascii[count] = input[count];
        ptr_len[count] = input[count];
        ptr_word_len[count] = input[count];
        count++;
    }
    str_sort_by_ascii(ptr_ascii, count);
    str_sort_by_len(ptr_len, count);
    str_sort_by_first_word_len(ptr_word_len, count);
    int choice = output_menu();
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            for (int i = 0; i < count; i++)
                fputs(input[i], stdout);
            break;
        case 2:
            output_str(ptr_ascii, count);
            break;
        case 3:
            output_str(ptr_len, count);
            break;
        case 4:
            output_str(ptr_word_len, count);
            break;
        default:
            break;
        }
        choice = output_menu();
    }

    return 0;
}

int output_menu(void)
{
    printf("***************************************\n");
    printf("1. output original strings\n");
    printf("2. output strings by ascii order\n");
    printf("3. output strings by length order\n");
    printf("4. output strings as the first word\n");
    printf("5. quit\n");
    printf("***************************************\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void output_str(char* strings [], int num)
{
    for (int i = 0; i < num; i++)
        fputs(strings[i], stdout);
}

void str_sort_by_ascii(char *strings [], int num)
{
    char *temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void str_sort_by_len(char *strings [], int num)
{
    char *temp;
    int top, seek;
    
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strlen(strings[top]) > strlen(strings[seek]))
            {
                //printf("%d\n%d\n", strlen(strings[top]), strlen(strings[seek]));
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }  
}

int first_word_len(char* str)
{
    int j = 0;
    while (str[j] != ' ' && str[j] != '\n')
        j++;
    return j;
}
void str_sort_by_first_word_len(char *strings [], int num)
{
    char *temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (first_word_len(strings[top]) - first_word_len(strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }    
}