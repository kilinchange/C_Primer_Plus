#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define STRLEN  20
#define SEAT_NUMBER 12

struct seat_s
{
    int seat_id;
    bool is_ordered;
    char firstname[STRLEN];
    char lastname[STRLEN];
};

int compare_two_seats_by_name(const void *a, const void* b);

int main(void)
{
    struct seat_s seats[SEAT_NUMBER];
    int seat_id;
    char firstname[STRLEN], lastname[STRLEN];
    for (int i = 0; i < SEAT_NUMBER; i++) {
        seats[i].seat_id = i + 1;
        seats[i].is_ordered = false;
        seats[i].firstname[0] = '\0';
        seats[i].lastname[0] = '\0';
    }
    while (true) {
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Quit");
        putchar('\n');
        char choice = tolower(getchar());
        char buffer[1024];
        gets(buffer);
        if (choice == 'f') break;
        if (choice == 'a') {
            int count = 0;
            for (int i = 0; i < SEAT_NUMBER; i++)
                if (!seats[i].is_ordered) count++;
            printf("The number of empty seats is %d.\n", count);
        }
        else if (choice == 'b') {
            printf("The list of empty seats:\n");
            for (int i = 0; i < SEAT_NUMBER; i++)
                if (!seats[i].is_ordered)   printf("%d ", seats[i].seat_id);
        }
        else if (choice == 'c') {
            struct seat_s temp[SEAT_NUMBER];
            memcpy(temp, seats, sizeof seats);
            qsort(temp, SEAT_NUMBER, sizeof temp, compare_two_seats_by_name);
            for (int i = 0; i < SEAT_NUMBER; i++)
                printf("%02d(%c): %s %s\n", temp[i].seat_id, temp[i].is_ordered ? 'x' : 'o', temp[i].firstname, temp[i].lastname);
        }
        else if (choice == 'd') {
            printf("Please enter the seat id and the customer's name: ");
            scanf("%d %s %s", &seat_id, firstname, lastname);
            int status = 0;
            for (int i = 0; i < SEAT_NUMBER; i++)
                if (seats[i].seat_id == seat_id) {
                    if (seats[i].is_ordered) status = 1;
                    else {
                        status = 2;
                        seats[i].is_ordered = true;
                        strcpy(seats[i].firstname, firstname);
                        strcpy(seats[i].lastname, lastname);
                    }
                    break;
                }
            if (status == 0) puts("No such seat id!");
            else if (status == 1) puts("Selected seat ordered!");
            else if (status == 2) puts("Seat successfully assigned.");
        }
        else if (choice == 'e') {
            printf("Please enter the seat id of assignment to be deleted: ");
            scanf("%d", &seat_id);
            bool found = false;
            for (int i = 0; i < SEAT_NUMBER; i++)
                if (seats[i].seat_id == seat_id) {
                    seats[i].is_ordered = false;
                    seats[i].firstname[0] = '\0';
                    seats[i].lastname[0] = '\0';
                    found = true;
                    break;
                }
            if (found) puts("Assignment found and deleted.");
            else puts("Sorry, assignment not found!");
        }
        else puts("Invalid choice!");
        putchar('\n');
    }
    puts("Done!");
    return 0;
}

int compare_two_seats_by_name(const void *a, const void *b)
{
    struct seat_s *pa = (struct seat_s *)a, *pb = (struct seat_s*)b;
    int cmp_firstname = strcmp(pa->firstname, pb->firstname), cmp_lastname = strcmp(pa->lastname, pb->lastname);
    return cmp_firstname != 0 ? cmp_firstname : cmp_lastname;
}