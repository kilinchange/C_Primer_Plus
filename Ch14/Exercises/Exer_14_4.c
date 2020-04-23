#include <stdio.h>
#include <string.h>
#define LEN 20

struct name_s {
    char first_name[LEN];
    char medium_name[LEN];
    char last_name[LEN];
};

struct info_s {
    char social_insurance_id[LEN];
    struct name_s name;
};

void printf_a(struct info_s infos[]);
void printf_b(struct info_s *infos);

int main(void)
{
    struct info_s infos[5] = {
        {"111111", {"Chenjie", "", "Duan"}},
        {"222222", {"Chengqi", "Ji", "Duan"}},
        {"333333", {"Yihan", "", "Chen"}},
        {"444444", {"Hi", "hello", "Ha"}},
        {"555555", {"Jie", "Chen", "Duan"}}
    };
    printf_a(infos);
    printf_b(infos);
    return 0;
}

void printf_a(struct info_s infos[5])
{
    for (int i = 0; i < 5; i++) {
        printf("%s, %s ", infos[i].name.first_name, infos[i].name.last_name);
        if (strlen(infos[i].name.medium_name) != 0)
            printf("%c. ", infos[i].name.medium_name[0]);
        printf("-- %s\n", infos[i].social_insurance_id);
    }
}

void printf_b(struct info_s *infos)
{
    for (int i = 0; i < 5; i++) {
        printf("%s, %s ", (infos + i)->name.first_name, (infos + i)->name.last_name);
        if (strlen((infos + i)->name.medium_name) != 0)
            printf("%c. ", (infos + i)->name.medium_name[0]);
        printf("-- %s\n", (infos + i)->social_insurance_id);
    }    
}