#include <stdio.h>
#include "Exer_12_3a.h"
int main(void)
{
    int mode;
    int pre = 0;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        if (mode == 0 || mode == 1)
            pre = mode;
        set_mode(pre, mode);
        double con = get_info(pre);
        show_info(pre, con);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}