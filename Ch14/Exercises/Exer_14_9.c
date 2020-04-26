#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define STRLEN  20
#define SEAT_NUMBER 12
#define FLIGHT_NUMBER   4

struct seat_s
{
    int seat_id;
    bool is_ordered;
    bool is_confirmed;
    char firstname[STRLEN];
    char lastname[STRLEN];
};

struct flight_s
{
    struct seat_s seats[SEAT_NUMBER];
    int flight_id;
};

int compare_two_seats_by_name(const void *a, const void* b);

int main(void)
{
    struct flight_s flights[FLIGHT_NUMBER];
    int seat_id;
    char firstname[STRLEN], lastname[STRLEN], buffer[1024];
    flights[0].flight_id = 102;
    flights[1].flight_id = 311;
    flights[2].flight_id = 444;
    flights[3].flight_id = 519;
    for (int j = 0; j < FLIGHT_NUMBER; j++) {
        for (int i = 0; i < SEAT_NUMBER; i++) {
            flights[j].seats[i].seat_id = i + 1;
            flights[j].seats[i].is_ordered = false;
            flights[j].seats[i].is_confirmed = true;
            flights[j].seats[i].firstname[0] = '\0';
            flights[j].seats[i].lastname[0] = '\0';
        }
    }
    while (true) {
        puts("To choose a flight, enter its label:");
        puts("0) 102");
        puts("1) 311");
        puts("2) 444");
        puts("3) 519");
        puts("4) Quit");
        putchar('\n');
        struct flight_s *flight;
        int temp;
        scanf("%d", &temp);
        if (temp == 4) break;
        flight = &(flights[temp]);
        struct flight_s flight_buffer;
        memcpy(&flight_buffer, flight, sizeof flight_buffer);
        gets(buffer);
        while (true) {
            printf("%d flight\n", flight->flight_id);
            puts("To choose a function, enter its letter label:");
            puts("a) Show number of empty seats");
            puts("b) Show list of empty");
            puts("c) Show alphabetical list of seats");
            puts("d) Assign a customer to a seat assignment");
            puts("e) Delete a seat assignment");
            puts("f) Confirm");
            puts("g) Quit");
            putchar('\n');
            char choice = tolower(getchar());
            gets(buffer);
            if (choice == 'g') break;
            if (choice == 'a') {
                int count = 0;
                for (int i = 0; i < SEAT_NUMBER; i++)
                    if (!flight->seats[i].is_ordered) count++;
                printf("The number of empty seats is %d.\n", count);
            }
            else if (choice == 'b') {
                printf("The list of empty seats:\n");
                for (int i = 0; i < SEAT_NUMBER; i++)
                    if (!flight->seats[i].is_ordered)   printf("%d ", flight->seats[i].seat_id);
            }
            else if (choice == 'c') {
                struct seat_s temp[SEAT_NUMBER];
                memcpy(temp, flight->seats, sizeof temp);
                qsort(temp, SEAT_NUMBER, sizeof *temp, compare_two_seats_by_name);
                for (int i = 0; i < SEAT_NUMBER; i++)
                    printf("%02d(%c): %s %s\t is confirmed: %s", temp[i].seat_id, temp[i].is_ordered ? 'x' : 'o', temp[i].firstname, temp[i].lastname, temp[i].is_confirmed ? "Yes" : "No");
            }
            else if (choice == 'd') {
                printf("Please enter the seat id and the customer's name: ");
                scanf("%d %s %s", &seat_id, firstname, lastname);
                int status = 0;
                for (int i = 0; i < SEAT_NUMBER; i++)
                    if (flight_buffer.seats[i].seat_id == seat_id) {
                        if (flight_buffer.seats[i].is_ordered) status = 1;
                        else {
                            status = 2;
                            flight_buffer.seats[i].is_ordered = true;
                            strcpy(flight_buffer.seats[i].firstname, firstname);
                            strcpy(flight_buffer.seats[i].lastname, lastname);
                            flight_buffer.seats[i].is_confirmed = false;
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
                    if (flight_buffer.seats[i].seat_id == seat_id) {
                        flight_buffer.seats[i].is_ordered = false;
                        flight_buffer.seats[i].firstname[0] = '\0';
                        flight_buffer.seats[i].lastname[0] = '\0';
                        found = true;
                        break;
                    }
                if (found) puts("Assignment found and deleted.");
                else puts("Sorry, assignment not found!");
            }
            else if (choice == 'f') {
                memcpy(flight, &flight_buffer, sizeof flight_buffer);
                printf("Successfully confirmed!");
            }
            else puts("Invalid choice!");
            putchar('\n');
        }
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