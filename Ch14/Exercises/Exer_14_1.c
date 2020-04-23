#include <stdio.h>
#include <string.h>
#define LEN 20

struct month {
    char name_for_short[LEN];
    char name[LEN];
    int days;
    int id;
};

int main(void)
{
    struct month months[12] = {
        {"Jan", "January", 31, 1},
        {"Feb", "February", 28, 2},
        {"Mar", "March", 31, 3},
        {"Apr", "April", 30, 4},
        {"May", "May", 31, 5},
        {"Jun", "June", 30, 6},
        {"Jul", "July", 31, 7},
        {"Aug", "August", 31, 8},
        {"Sept", "September", 30, 9},
        {"Oct", "October", 31, 10},
        {"Nov", "November", 30, 11},
        {"Dec", "December", 31, 12}
    };
    char name[LEN];
    scanf("%s", name);
    int count = 0;
    for (int i = 0; i < 12; i++) {
        count += months[i].days;
        if (strcmp(months[i].name, name) == 0)
            break;
    }
    printf("Count: %d\n", count);

    return 0;
}