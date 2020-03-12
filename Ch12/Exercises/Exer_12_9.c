#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    char** ar = (char**)malloc(n * sizeof(char*));
    printf("Enter %d words now:\n", n);
    printf("I enjoyed doing this exercise\n");
    for (int i = 0; i < n; i++)
    {
        char tmp[100];
        scanf("%s", tmp);
        ar[i] = (char*)malloc(strlen(tmp) * sizeof(char));
        strcpy(ar[i], tmp);
    }
    printf("Here are your words:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", ar[i]);
    return 0;
}