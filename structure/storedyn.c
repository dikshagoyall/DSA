#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int marks;
    char grade;
} info;

int main()
{
    int s, i;
    info *arr,t;
    char buffer;

    printf("Enter the number of students:");
    scanf("%d", &s);

    arr = (info*)malloc(s * sizeof(info));

    for (i = 0; i < s; i++)
    {
        scanf("%c", &buffer);
        printf("\nEnter the grade of the student %d: ", i + 1);
        scanf("%c", &t.grade);
        printf("Enter the marks of the student %d: ", i + 1);
        scanf("%d", &t.marks);
        arr[i]= t;
    }
    for(i=0;i<s;i++)
    {
        printf("\nThe marks of student %d is %d and the grade is %c\n", i+1, arr[i].marks, arr[i].grade);
    }
    return 0;
}