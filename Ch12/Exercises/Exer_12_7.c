/* manydice.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Samples/List_12_12_diceroll.h"

int main(void)
{
    int dice, roll;
    int sides;
    int status;
    int sets;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");
        while ((status = scanf("%d %d", &sides, &dice)) != 2)
        {
            if (status == EOF)
                break; 
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                printf("How many sides and how many dice? ");
            }
        }        
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        while (sets--){
            roll = roll_n_dice(dice, sides);
            printf("%d ", roll);
        }
        printf("\n");
        printf("Enter the number of sets; enter q to stop: ");
    }
    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}