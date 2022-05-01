#include<stdio.h>

typedef struct
{
    float real;
    float img;
}complex;

complex add(complex,complex);

int main()
{
    complex c1,c2,sum;
    printf("Complex number 1\n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f%f",&c1.real, &c1.img);
    printf("\nComplex number 2\n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f%f",&c2.real, &c2.img);

    sum= add(c1,c2);
    printf("Sum = %.1f + %.1fi", sum.real, sum.img);
    return 0;
}

complex add(complex c1,complex c2)
{
    complex Sum;
    Sum.real= c1.real+c2.real;
    Sum.img= c1.img+c2.img;
    return Sum;
}