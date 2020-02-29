#include <stdio.h>
#include <ctype.h>
#define SIZE 20

void getWord(char* words, int n);
int main(void)
{
    char words[SIZE];
    getWord(words, 10);
    printf("%s", words);
    return 0;
}

void getWord(char * words, int n)
{
    while (isspace(words[0] = getchar()));
    int i;
    for (i = 0; i < n; i++)
    {
        words[i] = getchar();
        if (isspace(words[i]))
        {
            words[i] = '\0';
            break;
        }
    }
    while (getchar() != '\n');
}