#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main(int argc, char* argv[])
{
    char* choice = "-p";
    if (argc > 1)
        choice = argv[1];
    char str[SIZE];
    FILE *fp = fopen("words.txt", "r");
    while (fgets(str, SIZE, fp) != NULL)
    {
        if (strcmp(choice, "-u") == 0)
        {
            char* ptr = str;
            while (*ptr != EOF)
            {
                *ptr = toupper(*ptr);
                ptr++;
            }
        }
        if (strcmp(choice, "-l") == 0)
        {
            char* ptr = str;
            while (*ptr != EOF)
            {
                *ptr = tolower(*ptr);
                ptr++;
            }
        }
        fputs(str, stdout);
    }
    fclose(fp);
    return 0;
}