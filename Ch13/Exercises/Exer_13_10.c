#include <stdio.h>
#include <stdlib.h>
#define LEN 40

int main(void)
{
    FILE *fp;
    char file_name[LEN];
    scanf("%s", file_name);
    long pos;
    if ((fp = fopen(file_name, "r")) == NULL){
        fprintf(stderr, "Can't open file \"%s\"\n");
        exit(EXIT_FAILURE);
    }
    while ((scanf("%ld", &pos)) == 1 && pos > 0){
        fseek(fp, pos, SEEK_SET);
        char c;
        while ((c = getc(fp)) != EOF && c != '\n'){
            putchar(c);
        putchar('\n');
        }
    }
    return 0;
}