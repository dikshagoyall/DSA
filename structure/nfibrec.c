#include<stdio.h>

int fibonacci(int);

int main()
{
    int n,fib;
    printf("Enter a number: ");
    scanf("%d", &n);
    fib= fibonacci(n);
    printf("The %dth fibonacci number is: %d", n, fib);
    return 0;
}

int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return (fibonacci(n-1)+fibonacci(n-2));
}