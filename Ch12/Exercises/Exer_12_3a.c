#include <stdio.h>

double get_info(int mode)
{
    double dis, con_fuel;
    if (mode == 0)
    {
        printf("Enter distance travled in kilometers: \n");
        scanf("%lf", &dis);
        printf("Enter fuel consumed in liters: \n");
        scanf("%lf", &con_fuel);
        return 100 * con_fuel / dis;
    }
    else
    {
        printf("Enter distance traveled in miles: \n");
        scanf("%lf", &dis);
        printf("Enter fuel consumed in gallons: \n");
        scanf("%lf", &con_fuel);
        return dis / con_fuel;
    }
}

void show_info(int mode, double con)
{
    if (mode == 0)
        printf("Fuel consumption is %.1f liters per 100 km.\n", con);
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", con);
}

void set_mode(int pre, int mode)
{
    if (mode != 0 && mode != 1)
    {
        printf("Invalid mode specified.");
        if (pre == 1)
            printf("Mode 1(US) used.\n");
        else
            printf("Mode 0(metric) used.\n");
    }
}