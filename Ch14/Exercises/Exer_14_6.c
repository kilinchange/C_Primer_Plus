#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LENGTH     32
#define PLAYERS_NUMBER  19

struct baseball_player_s
{
    bool initialized;
    int id;
    char firstname[NAME_LENGTH];
    char lastname[NAME_LENGTH];
    int play_count;
    int hit_count;
    int base_count;
    int RBI_count;
    float hit_rate;
};

int main()
{
    struct baseball_player_s baseball_players[PLAYERS_NUMBER];
    for (int i = 0; i < PLAYERS_NUMBER; i++)
        baseball_players[i].initialized = false;
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Can't open file data.txt!\n");
        exit(EXIT_FAILURE);
    }
    int id, play_count, hit_count, base_count, RBI_count;
    char firstname[NAME_LENGTH], lastname[NAME_LENGTH];
    while (fscanf(fp, "%d %s %s %d %d %d %d", &id, firstname, lastname, &play_count, &hit_count, &base_count, &RBI_count) == 7) {
        if (!baseball_players[id].initialized) {
            baseball_players[id].id = id;
            strcpy(baseball_players[id].firstname, firstname);
            strcpy(baseball_players[id].lastname, lastname);
            baseball_players[id].play_count = 0;
            baseball_players[id].hit_count = 0;
            baseball_players[id].base_count = 0;
            baseball_players[id].RBI_count = 0;
            baseball_players[id].hit_rate = 0.0;
        }
        baseball_players[id].play_count += play_count;
        baseball_players[id].hit_count += hit_count;
        baseball_players[id].base_count += base_count;
        baseball_players[id].RBI_count += RBI_count;
    }
    for (int i = 0; i < PLAYERS_NUMBER; i++) {
        baseball_players[i].hit_rate = baseball_players[i].hit_count / (float)baseball_players[i].play_count;
        printf("The baseball player %s %s, whose if is %d, has played %d times, hit %d times, acquired %d bases and %d RBI with hit rate %f.\n",
                baseball_players[i].firstname,
                baseball_players[i].lastname,
                baseball_players[i].id,
                baseball_players[i].play_count,
                baseball_players[i].hit_count,
                baseball_players[i].base_count,
                baseball_players[i].RBI_count,
                baseball_players[i].hit_rate);
    fclose(fp);
    }

    return 0;
}