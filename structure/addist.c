#include<stdio.h>

typedef struct  
{
    int inch;
    float feet;
}distance;

int main()
{
    distance d1, d2, sum;
    printf("Distance 1\n");
    printf("Enter feet and inch: ");
    scanf("%f%d",&d1.feet,&d1.inch);
    printf("\nDistance 2\n");
    printf("Enter feet and inch: ");
    scanf("%f,%d",&d2.feet,&d2.inch);

    sum.feet= d1.feet+d2.feet;
    sum.inch= d1.inch+d2.inch;

    while(sum.inch>=12)
    {
        sum.inch= sum.inch%12;
        sum.feet= sum.feet+ sum.inch/12;
    }

    printf("Sum= %.1f, %d",sum.feet,sum.inch);
    return 0;
}