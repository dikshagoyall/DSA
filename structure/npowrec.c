#include<stdio.h>

int power(int,int);

int main()
{
    int n,p,b;
    printf("Enter the base: ");
    scanf("%d", &b);
    printf("Enter the power: ");
    scanf("%d", &n);

    p= power(b,n);
    printf("%dth power of 2 is: %d", n,p);
    return 0;
}

int power(int b, int n)
{
    if(n==0)
        return 1;
    return b*power(b,n-1);
}