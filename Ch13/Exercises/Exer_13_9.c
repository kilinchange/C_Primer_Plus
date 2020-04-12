/* addaword.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];

    if ((fp = fopen("13_9_wordy.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    char string[MAX + 10];
    int idx = 1;
    while ((fgets(string, MAX + 10, fp)) != NULL){
        idx++;
    }
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d %s\n", idx++, words);
    
    puts("File cotents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}