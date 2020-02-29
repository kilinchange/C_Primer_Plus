#include <stdio.h>
#include <ctype.h>
#define SIZE 20

void getWord(char* words);
int main(void)
{
    char words[SIZE];
    getWord(words);
    printf("%s", words);
    return 0;
}

void getWord(char * words)
{
    while (isspace(words[0] = getchar()));
    int i = 0;
    while (1)
    {
        i++;
        words[i] = getchar();
        if (isspace(words[i]))
        {
            words[i] = '\0';
            break;
        }
    }
    while (getchar() != '\n');
}