// useheader.c
#include <stdio.h>
#include "List_16_6_names_st.h"

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    return 0;
}