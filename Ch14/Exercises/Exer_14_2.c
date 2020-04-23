#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LEN 20

struct month {
    char name_abbr[LEN];
    char name[LEN];
    int days;
    int id;
};

bool is_lunar_year(int year);

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
    int day, month, year;
    printf("Please enter the day, month, year seperately: ");
    scanf("%d", &day);
    if ((scanf("%d", &month)) != 1) {
        char temp[LEN];
        scanf("%s", temp);
        for (int i = 0; i < 12; i++)
            if (strcmp(months[i].name, temp) == 0 || strcmp(months[i].name_abbr, temp) == 0) {
                month = months[i].id;
                break;
            }
    }
    scanf("%d", &year);
    int count = 0;
    for (int i = 0; i < 12; i++) {
        if (month == months[i].id) break;
        count += months[i].days;
        if (months[i].id == 2 && is_lunar_year(year)) count++;
    }
    printf("Count: %d\n", count + day);

    return 0;
}

bool is_lunar_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}