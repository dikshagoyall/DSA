#include<stdio.h>

int sum(int);

int main()
{
    int s,n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    
    s= sum(n);
    printf("Sum of %d terms is: %d",n,s);
    return 0;
}

int sum(int n)
{
    if(n==0)
        return 0;
    return n+ sum(n-1);
}