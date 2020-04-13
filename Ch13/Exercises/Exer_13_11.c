#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256

int main(int argc, char* argv[])
{
    if (argc < 3){
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }
    char string[LEN];
    while (fgets(string, LEN - 1,fp) != NULL)
    {
        if (strstr(string, argv[1]) != NULL)
            fputs(string, stdout);
    }

    return 0;
}