#include <stdio.h>
#define LEN 20
#define CSIZE 4

struct name_s {
    char first_name[LEN];
    char last_name[LEN];
};

struct student_s {
    struct name_s name;
    double grade[3];
    double avg;
};

void function_d(struct student_s *students);
void function_e(struct student_s *students);
void function_f(const struct student_s *students);
void function_g(const struct student_s *students);

int main(void)
{
    struct student_s students[CSIZE] = {
        {.name={"Chenjie", "Duan"}},
        {.name={"Chenqi", "Duan"}},
        {.name={"Yihan", "Chen"}},
        {.name={"Tianlong", "Fan"}}
    };
    function_d(students);
    function_e(students);
    function_f(students);
    function_g(students);

    return 0;
}

void function_d(struct student_s *students) {
    for (int i = 0; i < CSIZE; i++) {
        printf("Please enter %s %s's grade1, grade2, grade3: ", 
                students[i].name.first_name, students[i].name.last_name);
        for (int j = 0; j < 3; j++)
            scanf("%lf", &(students[i].grade[j]));
    }
}

void function_e(struct student_s *students) {
    for (int i = 0; i < CSIZE; i++)
        (students + i)->avg = (students[i].grade[0] + students[i].grade[1] + students[i].grade[2]) / 3;
}

void function_f(const struct student_s *students) {
    for (int i = 0; i < CSIZE; i++) {
        printf("#%d\n", i+1);
        printf("name: %s %s\n", students[i].name.first_name, students[i].name.last_name);
        printf("grades: %f, %f, %f\n", students[i].grade[0], students[i].grade[1], students[i].grade[2]);
        printf("avg: %f\n", students[i].avg);
    }
}

void function_g(const struct student_s *students)
{
    double sum = 0.0;
    for (int i = 0; i < CSIZE; i++)
        sum += students[i].avg;
    printf("The average grade of all students is: %f\n", sum / CSIZE);
}