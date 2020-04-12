#include <stdio.h>
#include <stdlib.h>
#define LEN 50

int main(int argc, char* argv[])
{
    FILE *file1, *file2;
    char words[LEN];

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \" %s\"\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \" %s\"\n",
                argv[2]);
        exit(EXIT_FAILURE);
    }
    int flag = -1;
    while (flag != 0)
    {
        flag = 0;
        if ((fgets(words, LEN, file1)) != NULL){
            fputs(words, stdout);
            flag++;
        }
        if ((fgets(words, LEN, file2)) != NULL){
            fputs(words, stdout);
            flag++;
        }
    }
    fclose(file1);
    fclose(file2);

    return 0;
}