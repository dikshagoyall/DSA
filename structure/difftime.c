#include <stdio.h>

typedef struct
{
    int hours;
    int mins;
    int sec;
} time;

time difference(time t1,time t2);

int main()
{
    time t1, t2, d;
    printf("Start Time\n");
    printf("Enter hours and mins and seconds: ");
    scanf("%d%d%d", &t1.hours, &t1.mins, &t1.sec);
    printf("\nEnd Time\n");
    printf("Enter hours and mins and seconds: ");
    scanf("%d%d%d", &t2.hours, &t2.mins, &t2.sec);

    printf("\nTime 1: %d:%d:%d", t1.hours, t1.mins, t1.sec);
    printf("\nTime 2: %d:%d:%d", t2.hours, t2.mins, t2.sec);

    d= difference(t1,t2);
    printf("\n\nTime Difference: %d:%d:%d", d.hours, d.mins, d.sec);
    return 0;
}

time difference(time t1,time t2)
{
    time d;
    if (t2.sec > t1.sec)
    {
        --t1.mins;
        t1.sec+= 60;
    }

    d.sec= t1.sec-t2.sec;
    if(t2.mins > t1.mins)
    {
        --t1.hours;
        t1.mins+= 60;
    }

    d.mins= t1.mins-t2.mins;
    d.hours= t1.hours-t2.hours;
    return d;
}