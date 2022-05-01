#include<stdio.h>
#include<stdlib.h>

//structure definition
typedef struct
{
    int roll;
    char name[30];
    char stream[30];
}student;

int details(student *, FILE *, FILE *, FILE *);
void sort(student *,int , FILE *, FILE *, FILE *);

//main starts
int main()
{
    FILE *n,*r,*s;
    int nos,i,N;
    char copy[100];

    //opening of the texts files in read mode
    n = fopen("name.txt", "r");
    r = fopen("roll.txt", "r");
    s = fopen("stream.txt", "r");

    student record[50];

    //storing the number of students in nos
    nos= details(record,n,r,s);

    printf("Enter the number of new students: ");
    scanf("%d", &N);
    printf("\nEnter the details of new students\n");
    while(N!=0)
    {
        printf("Enter the roll number: ");
        fscanf(stdin, "%lu", &(record[nos].roll));
        printf("Enter the name: ");
        fgets(record[nos].name, 30, stdin);
        printf("Enter the stream: ");
        fgets(record[nos].stream, 30, stdin);
        nos++;
        N--;
    }

    //close the text files from read mode
    fclose(n);
    fclose(r);
    fclose(s);
    
    sort(record, nos, n, r, s);
    printf("\nSUCESSFULLY UPDATED!\n");

    printf("\nThe Updated Records are: \n");
    for(i=0;i<nos;i++)
    {
        printf("%s%lu\n%s",record[i].name, record[i].roll, record[i].stream);
        printf("\n");
    }

    //closing the text files from write mode
    fclose(n);
    fclose(r);
    fclose(s);
    return 0;
}//main ends

//function to store the student detais in a structure frrom a file
int details(student *S, FILE *n, FILE *r, FILE *s)
{
    int z = 0,i;
    for(i=0;i<5;i++)
    {
        fgets(S[z].name, 30, n);
        fscanf(r, "%lu", &(S[z].roll));
        fgets(S[z].stream, 30, s);
        z++;
    }
    return z;
}

//bubble sort
void sort(student *S,int z, FILE *n, FILE *r, FILE *s)
{
    int i,j,k;
    n = fopen("name.txt", "w");
    r = fopen("roll.txt", "w");
    s = fopen("stream.txt", "w");
    student t;
    for(i=1;i<z;i++)
    {
        for(j=0;j<z-i;j++)
        {
            if(S[j].roll > S[j+1].roll)
            {
                t = S[j];
                S[j] = S[j+1];
                S[j+1] = t;
            }
        }
    }
    for(i=0;i<z;i++)
    {
        fputs(S[i].stream, s);
        fputs(S[i].name, n);
        fprintf(r, "%lu\n", S[i].roll);
    }
}