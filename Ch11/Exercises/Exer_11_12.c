#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int words_ct = 0;
    int upper_ct = 0;
    int lower_ct = 0;
    int punct_ct = 0;
    int digit_ct = 0;
    int c;
    int pre = -1;
    while ((c = getchar()) != -1)
    {
        if (isspace(c) && pre != -1 && !isspace(pre))
            words_ct++;
        else if (isupper(c))
            upper_ct++;
        else if (islower(c))
            lower_ct++;
        else if (ispunct(c))
            punct_ct++;
        else if (isdigit(c))
            digit_ct++;
        pre = c;
    }
    printf("words count: %d\nupper characters count: %d\n"
            "lower characters count: %d\npunctuation characters count: %d\n"
            "digit characters count: %d\n", words_ct, upper_ct, lower_ct, punct_ct, digit_ct);
    return 0;
}

