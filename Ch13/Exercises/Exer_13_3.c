#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SLEN 100

int main(void)
{
    puts("Enter filename: ");
    char file_name[SLEN];
    scanf("%s", file_name);
    FILE *fp;
    if ((fp = fopen(file_name, "rb+")) == NULL){
        printf("Can't open the source file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    int length = ftell(fp);
    char ch;
    for (long i = 0L; i < length; i++){
        fseek(fp, i, SEEK_SET);
        ch = getc(fp);
        fseek(fp, i, SEEK_SET);
        if (ch != '\n')
            ch = toupper(ch);
        putc(ch, fp);
    }
    fclose(fp);
    return 0;
}