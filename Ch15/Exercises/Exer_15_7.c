/* copy from dragondavion */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long uint32_t;
typedef uint32_t      font_t;

#define FONT_ID_OFFSET          0
#define FONT_SIZE_OFFSET        8
#define FONT_ALIGN_OFFSET       16
#define FONT_BOLD_OFFSET        18
#define FONT_ITALIC_OFFSET      19
#define FONT_UNDERLINE_OFFSET   20

#define FONT_ID_MASK        ((uint32_t) 0xFF)
#define FONT_SIZE_MASK      ((uint32_t) 0x7F00)
#define FONT_ALIGN_MASK     ((uint32_t) 0x30000)
#define FONT_BOLD_MASK      ((uint32_t) 0x40000)
#define FONT_ITALIC_MASK    ((uint32_t) 0x80000)
#define FONT_UNDERLINE_MASK ((uint32_t) 0x100000)

#define ALIGN_LEFT      ((uint32_t) 0x0)
#define ALIGN_CENTER    ((uint32_t) 0x1)
#define ALIGN_RIGHT     ((uint32_t) 0x2)
char *states_alignment[3] = { "left", "center", "right" };
char *states_on_or_off[2] = { "off", "on" };

char buffer[1024];

void output_font_settings(font_t font);
char output_menu_and_get_choice();

void set_font_id(font_t *pfont, uint32_t id);
void set_font_size(font_t *pfont, uint32_t size);
void set_font_align(font_t *pfont, uint32_t align);
void set_font_bold(font_t *pfont, bool is_bold);
void set_font_italic(font_t *pfont, bool is_italic);
void set_font_underlined(font_t *pfont, bool is_underlined);
void reverse_font_bold(font_t *pfont);
void reverse_font_italic(font_t *pfont);
void reverse_font_underlined(font_t *pfont);

int main()
{
    font_t font;
    set_font_id(&font, 1);
    set_font_size(&font, 12);
    set_font_align(&font, ALIGN_RIGHT);
    set_font_bold(&font, false);
    set_font_italic(&font, false);
    set_font_underlined(&font, false);
    while (true) {
        output_font_settings(font);
        char choice = output_menu_and_get_choice();
        if (choice == 'q') break;
        uint32_t id, size;
        char alignment, set;
        switch (choice) {
        case 'f':
            printf("Enter font id (0-255): ");
            gets(buffer);
            sscanf(buffer, "%u", &id);  // 用sscanf就避免了'\n'被留在缓冲区，又可以把字符串存储为数字类型，太巧妙了~ 
            set_font_id(&font, id);
            break;
        case 's':
            printf("Enter font size (0-127): ");
            gets(buffer);
            sscanf(buffer, "%u", &size);
            set_font_size(&font, size);
            break;
        case 'a':
            while (true) {
                puts("Select alignment:");
                puts("l)left    c)center    r)right");
                alignment = getchar();
                if (alignment != '\n') gets(buffer);
                if (alignment == 'l' || alignment == 'c' || alignment == 'r') break; else puts("Invalid alignment!\n");
            }
            switch (alignment) {
            case 'l': set_font_align(&font, ALIGN_LEFT); break;
            case 'c': set_font_align(&font, ALIGN_CENTER); break;
            case 'r': set_font_align(&font, ALIGN_RIGHT); break;
            default: break;
            }
            break;
        case 'b':
            reverse_font_bold(&font);
            break;
        case 'i':
            reverse_font_italic(&font);
            break;
        case 'u':
            reverse_font_underlined(&font);
            break;
        default:
            break;
        }
        putchar('\n');
    }
    puts("Bye!");
    return 0;
}

void output_font_settings(font_t font)
{
    printf(" ID SIZE ALIGNMENT  B   I   U\n");
    printf("%3u %4u    %-6s  %-3s %-3s %-3s\n\n",
            (font & FONT_ID_MASK) >> FONT_ID_OFFSET,
            (font & FONT_SIZE_MASK) >> FONT_SIZE_OFFSET,
            states_alignment[(font & FONT_ALIGN_MASK) >> FONT_ALIGN_OFFSET],
            states_on_or_off[(font & FONT_BOLD_MASK) >> FONT_BOLD_OFFSET],
            states_on_or_off[(font & FONT_ITALIC_MASK) >> FONT_ITALIC_OFFSET],
            states_on_or_off[(font & FONT_UNDERLINE_MASK) >> FONT_UNDERLINE_OFFSET]);
}

char output_menu_and_get_choice()
{
    char choice;
    while (true) {
        puts("f)change font     s)change size       a)change alignment");
        puts("b)toggle bold     l)toggle italic     u)toggle underline");
        puts("q)quit");
        choice = getchar();
        if (choice != '\n') gets(buffer);
        if (choice == 'f' || choice == 's' || choice == 'a' || choice == 'b' || choice == 'i' || choice == 'u' || choice == 'q')
            return choice;
        else
            puts("Invalid choice!\n");
    }
}

void set_font_id(font_t *pfont, uint32_t id)
{
    *pfont &= ~FONT_ID_MASK;
    *pfont |= id << FONT_ID_OFFSET;
}

void set_font_size(font_t *pfont, uint32_t size)
{
    *pfont &= ~FONT_SIZE_MASK;
    *pfont |= size << FONT_SIZE_OFFSET;
}

void set_font_align(font_t *pfont, uint32_t align)
{
    *pfont &= ~FONT_ALIGN_MASK;
    *pfont |= align << FONT_ALIGN_OFFSET;
}

void set_font_bold(font_t *pfont, bool is_bold)
{
    if (is_bold) *pfont |= FONT_BOLD_MASK; else *pfont &= ~FONT_BOLD_MASK;
}

void set_font_italic(font_t *pfont, bool is_italic)
{
    if (is_italic) *pfont |= FONT_ITALIC_MASK; else *pfont &= ~FONT_ITALIC_MASK;
}

void set_font_underlined(font_t *pfont, bool is_underlined)
{
    if (is_underlined) *pfont |= FONT_UNDERLINE_MASK; else *pfont &= ~FONT_UNDERLINE_MASK;
}

void reverse_font_bold(font_t *pfont)
{
    *pfont ^= FONT_BOLD_MASK;
}

void reverse_font_italic(font_t *pfont)
{
    *pfont ^= FONT_ITALIC_MASK;
}

void reverse_font_underlined(font_t *pfont)
{
    *pfont ^= FONT_UNDERLINE_MASK;
}