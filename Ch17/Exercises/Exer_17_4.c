// mall.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "List_17_6_queue.h"
#define MIN_PER_HR  60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    Queue line1, line2;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0, wait_time2 = 0;
    double min_per_cust;
    long line_wait = 0;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if (line1.items < line2.items)
                    EnQueue(temp, &line1);
                else
                    EnQueue(temp,&line2);
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait = cycle - temp.arrive;
            served++;
        }
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait = cycle - temp.arrive;
            served++;
        }        
        if (wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;
        sum_line += QueueItemCount(&line1);
        sum_line += QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("customers accepted: %d\n", customers);
        printf(" customers served: %d\n", served);
        printf("    turnaways: %d\n", turnaways);
        printf("average queue size: %.2f\n",
            (double)sum_line / (2*cyclelimit));
        printf(" average wait time: %.2f minutes\n",
            (double)line_wait / served);
    }
    else
        puts("No customes!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}