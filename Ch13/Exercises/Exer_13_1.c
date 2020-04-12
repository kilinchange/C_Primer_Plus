#include <stdio.h>
#include <stdlib.h>
#define SLEN 50

int main(void)
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char file_name[SLEN];
    puts("Please enter file name: ");
    gets(file_name);
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file_name, count);

    return 0;
}