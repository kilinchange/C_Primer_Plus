// reducto.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main()
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
    int n;
    char filename[LEN];

    if (scanf("%s", filename) < 1)
    {
        fprintf(stderr, "Please input filename\n");
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                filename);
        exit(EXIT_FAILURE);
    }
    strncpy(name, filename, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}