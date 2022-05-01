#include <stdio.h>

typedef struct
{
    char name[30];
    int rollno;
    int age;
    float marks;
} student;

int main()
{
    int n, i;
    printf("Enter total of students:");
    scanf("%d", &n);
    student s[n];

    printf("Enter information of %d students:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("Student %d :\n", (i + 1));
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].rollno);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("Students Information:\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d :\n", (i + 1));
        printf("\t Name:%s\n ", s[i].name);
        printf("\t Age:%d\n ", s[i].age);
        printf("\t Roll number: %d\n", s[i].rollno);
        printf("\t Marks: %.1f\n\n", s[i].marks);
    }
    return 0;
}