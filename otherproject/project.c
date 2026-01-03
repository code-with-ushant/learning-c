#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];
    float grades[5];
    int id;
    float gpa;

} st;
void student(st students[], int *studentcount, int n);
void entergrades(st students[], int n);
void calculategpa(st students[], int n);
void displaystudents(st students[], int studentcount);
void student(st students[], int *studentcount, int n)
{
    
    for (*studentcount = 0; *studentcount < n;*studentcount++)
    {

        printf("Enter the name :");
        scanf("%s", &students[*studentcount].name);
        printf("Enter student id :");
        scanf("%d",&students[*studentcount].id);
    }
}
void entergrades(st students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter the grades of %s\n", students[i].name);

        printf("english:");
        scanf("%d", &students[i].grades[0]);        printf("math:");
        scanf("%d", &students[i].grades[1]);
        printf("ecco:");
        scanf("%d", &students[i].grades[2]);
        printf("science:");
        scanf("%d", &students[i].grades[3]);
        printf("account:");
        scanf("%d", &students[i].grades[4]);
    }
}
void calculategpa(st students[], int n)
{
   float gpa;
    for (int i = 0; i < n; i++)
    {

        gpa = ((students[i].grades[0] + students[i].grades[1] + students[i].grades[2] + students[i].grades[3] + students[i].grades[4]) / 5) / 24 ; printf("gpa of %s student is %f", students[i].name, gpa);
        printf("the gpa of %s is %f",students[i].name,gpa);
    }
}
void displaystudents(st students[], int n){
    for (int i = 0; i < n; i++)
                {
                    printf("the name of student is %s\n", students[i].name);
                    printf("english grades of student  is %d\n", students[i].grades[0]);
                    
                    
                }
}
    int main()
    {
        // FILE * ptr = fopen("filev.exe","a");
        int n = 2;
        st students[n];
        int studentcount=0;
        int option;
        do
        {
            printf("1.Add new student.\n");
            printf("2.Enter grades of student.\n");
            printf("3.calculate gpa .\n");
            printf("4.show all student.\n");
            printf("5.exit\n");
            scanf("%d", &option);

            if (option == 1)
            {
                student(students, &studentcount, n);

                
            }

            else if (option == 2)
            {
                entergrades(students, n);
            }
            else if (option == 3)
            {
                calculategpa(students, n);
            }
            else if(option ==4){
                displaystudents(students,n);
            }
            else if(option == 5){
                printf("exiting........");
            }
        }while(option != 5);


        return 0;
    }
