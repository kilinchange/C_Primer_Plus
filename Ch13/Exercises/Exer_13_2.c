#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 100

int main(int argc, char* argv[])
{  
    FILE *fs, *fd;
    if (argc != 3){
        printf("Please enter source and destination file name.\n");
        exit(EXIT_FAILURE);
    }
    if ((fs = fopen(argv[1], "rb")) == NULL){
        printf("I can not open the file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fd = fopen(argv[2], "wb+")) == NULL){
        printf("I can not open the file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    size_t bytes;
    char temp[BUFSIZE];
    while((bytes = fread(temp, sizeof(char), BUFSIZE, fs)) > 0)
        fwrite(temp, sizeof(char), bytes, fd);

    // int temp1[BUFSIZ] = {1,2,3};
    // fwrite(temp, sizeof(int), BUFSIZ, fd);

    fclose(fd);
    fclose(fs);
    return 0;
}