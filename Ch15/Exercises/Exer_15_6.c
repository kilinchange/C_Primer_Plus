#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int uint32;

#define LEFT    0
#define CENTER  1
#define RIGHT   2

const char * alignments[3] = { "left", "center", "right" };

struct word_type {
    uint32 id : 8;
    uint32 size : 7;
    uint32 alignment : 2;
    bool black : 1;
    bool italic : 1;
    bool underline: 1;
};

void show_settings(const struct word_type * pb);
char print_menu();

int main(void)
{
    struct word_type word = { 1, 12, LEFT, false, false, false};
    uint32 id, size, alignments;

    printf("Original word settings:\n");
    show_settings(&word);

    while (true)
    {
        char choice = print_menu();
        switch (choice)
        {
        case 'f':
            puts("Enter font id (0-255):");
            scanf("%d", &id);
            while (getchar() != '\n');
            word.id = id;
            break;
        case 's':
            puts("Enter font size (0-127):");
            scanf("%d", &size);
            while (getchar() != '\n');
            word.size = size;
            break;
        case 'a':
            puts("Select alignment");
            puts("l) left   c) center   r)right");
            char temp;
            scanf("%c", &temp);
            while (getchar() != '\n');
            switch (temp)
            {
            case 'l':
                word.alignment = LEFT;
                break;
            case 'c':
                word.alignment = CENTER;
                break;
            case 'r':
                word.alignment = RIGHT;
                break;
            default:
                puts("Invalid choice!");
                break;
            }
        case 'b':
            word.black = true;
            break;
        case 'i':
            word.italic = true;
            break;
        case 'u':
            word.underline = true;
            break;
        case 'q':
            puts("Bye!");
            exit(0);
            break;
        default:
            puts("Invalid choice!");
            break;
        }
        show_settings(&word);
    }

    return 0;
}

void show_settings(const struct word_type * pb)
{
    puts("  ID    SIZE    ALIGNMENT   B   I   U");
    printf("   %u    %u      %s       %s  %s  %s\n\n", pb->id, pb->size, 
        alignments[pb->alignment], pb->black ? "on" : "off", 
        pb->italic ? "on" : "off", pb->underline ? "on" : "off");
}
char print_menu()
{
    char temp;
    puts("f)change font     s)change size       a)change alignment");
    puts("b)toggle bold     i)toggle italic     u)toggle underline");
    puts("q)quit");
    scanf("%c", &temp);
    while (getchar() != '\n');
    return temp;
}