#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    for (int i = 1; i < argc; i++){
        printf("%03d: ", i);
        fp = fopen(argv[i], "r");
        if (fp == NULL){
            printf("Can't open this file!\n");
            continue;
        }
        printf("The content of the file %s is:\n");
        char ch;
        while (fscanf(fp, "%c", &ch) == 1)
            putchar(ch);
        putchar('\n');
        fclose(fp);
    }
    return 0;
}