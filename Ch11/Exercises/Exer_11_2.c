#include <stdio.h>
#define SIZE 20

void getWords(int n, char* words);
int main(void)
{
    char words[SIZE];
    getWords(10, words);
    printf("%s", words);
    return 0;
}

void getWords(int n, char * words)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        words[i] = getchar();
        if (isspace(words[i]))
        {
            words[i] = '\0';
            break;
        }
    }
}