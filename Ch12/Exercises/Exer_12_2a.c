#include <stdio.h>
int mode;
double dis;
double con_fuel;

void get_info()
{
    if (mode == 0)
    {
        printf("Enter distance travled in kilometers: \n");
        scanf("%lf", &dis);
        printf("Enter fuel consumed in liters: \n");
        scanf("%lf", &con_fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: \n");
        scanf("%lf", &dis);
        printf("Enter fuel consumed in gallons: \n");
        scanf("%lf", &con_fuel);
    }
}

void show_info()
{
    if (mode == 0)
        printf("Fuel consumption is %.1f liters per 100 km.\n", 100 * con_fuel / dis);
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", dis / con_fuel);
}

void set_mode(int m)
{
    if (m != 0 && m != 1)
    {
        printf("Invalid mode specified.");
        if (mode == 1)
            printf("Mode 1(US) used.\n");
        else
            printf("Mode 0(metric) used.\n");
    }
    else if (m == 1)
        mode = 1;
    else
        mode = 0;
}