#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
void checkCount(char filename[LEN], char c);

int main(int argc, char* argv[])
{
    FILE *file;
    char c;
    char file_name[LEN];
    int n = argc - 2;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1){
        fprintf(stderr, "argv[1] should be char type!\n");
        exit(EXIT_FAILURE);
    }
    c = argv[1][0];
    if (argc == 2)
    {
        n = 1;
        printf("Input file name:");
        scanf("%s", file_name);
    }
    for (int i = 0; i < n; i++)
    {
        if (argc != 2)
            strcpy(file_name, argv[i+2]);
        checkCount(file_name, c);
    }

    return 0;
}

void checkCount(char filename[LEN], char c)
{
    FILE *f;
    if ((f = fopen(filename, "r")) == NULL)
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                filename);
    long last;
    fseek(f, 0L, SEEK_END);
    last = ftell(f);
    rewind(f);
    int count = 0;
    for (int i = 0; i < last; i++)
        if (getc(f) == c)
            count++;
    printf("filename: %s count: %d\n", filename, count);
}