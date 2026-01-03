#include <stdio.h>
typedef struct student //making structure for student
{
    char name[20];
    int id;
    float grade[4];
    float gpa;

} st;

void newstudent(st students[], int *studentcount, int n); //declearing function
void gradeofst(st students[], int studentcount);
void calculategpa(st students[], int studentcount);
void savedata(st students[], int studentcount);
void loaddata(st students[], int *studentcount);

void newstudent(st students[], int *studentcount, int n) // function for adding student in data base
{
    int x;
    if (*studentcount < n)
    {
        while (*studentcount < n)
        {   printf("fill student detils !\n");
            printf("NAME : ");
            scanf("%s", students[*studentcount].name);
            printf("ID : ");
            scanf("%d", &students[*studentcount].id);
            (*studentcount)++;
            printf("1 for Next\n2 for Exit\n");
            scanf("%d", &x);
            if (x == 1)
            {
                printf("Next student :\n");
            }
            else if (x == 2)
            { 
                printf("exiting...........!");
                return;
            }
            else
            {
                printf("Choose 1 or 2\n");
            }
        }
    }
    else
    {
        printf("No space available for student..!\n");
    }
}

void gradeofst(st students[], int studentcount)// storing grade of student in every subject
{
    if (studentcount > 0)
    {
        int id;
        printf("Student ID : ");
        scanf("%d", &id);
        int found = 0;
        for (int i = 0; i < studentcount; i++)
        {
            if (id == students[i].id)
            {
                found = 1;
                printf("NAME : %s \n grades \n", students[i].name);
                printf("English :");
                scanf("%f", &students[i].grade[0]);
                printf("Nepali :");
                scanf("%f", &students[i].grade[1]);
                printf("Science :");
                scanf("%f", &students[i].grade[2]);
                printf("Math :");
                scanf("%f", &students[i].grade[3]);
                break;
            }
        }
        if (!found)
        {
            printf("Try again, ID not found!\n");
        }
    }
    else
    {
        printf("No student available!\n");
    }
}

void calculategpa(st students[], int studentcount)// it calculate gpa of student
{
    float sum;
    for (int i = 0; i < studentcount; i++)
    {
        sum = students[i].grade[0] + students[i].grade[1] + students[i].grade[2] + students[i].grade[3];
        students[i].gpa = (sum / 4)/25;
    }
    printf("GPA calculated successfully!\n");
}

void savedata(st students[], int studentcount)// it helps to store data in file 
{
    FILE *ptr;
    ptr = fopen("mef.bin", "wb");
    if (ptr == NULL)
    {
        printf("Error saving data\n");
        return;
    }
    fwrite(&studentcount, sizeof(int), 1, ptr);
    fwrite(students, sizeof(st), studentcount, ptr);
    fclose(ptr);
    printf("Data stored successfully!\n");
}

void loaddata(st students[], int *studentcount) // it helps to used store data in file
{
    FILE *ptr;
    ptr = fopen("mef.bin", "rb");
    if (ptr == NULL)
    {
        printf("No data available\n");
        return;
    }
    fread(studentcount, sizeof(int), 1, ptr);
    fread(students, sizeof(st), *studentcount, ptr);
    fclose(ptr);
    printf("Data loaded successfully!\n");
}

int main()
{
    int n = 10;
    st students[n];
    int u;
    int studentcount = 0;
    int option;
    loaddata(students, &studentcount);
    do
    {
        printf("1. Add new student.\n");
        printf("2. Enter grades of student.\n");
        printf("3. Calculate GPA.\n");
        printf("4. Show  students details.\n");
        printf("5. Delet student details\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            newstudent(students, &studentcount, n);
            break;
        case 2:
            gradeofst(students, studentcount);
            break;
        case 3:
            calculategpa(students, studentcount);
            break;
        case 4:
            
            printf("Do you want to see all student info or one of them?\n1 for individual\n2 for all students\n");
            scanf("%d", &u);
            if (u == 1)
            {
                int id;

                printf("Student ID : ");
                scanf("%d", &id);
                for (int i = 0; i < studentcount; i++)
                {
                    if (id == students[i].id)
                    {
                        printf("NAME : %s\n", students[i].name);
                        printf("ID: %d\n", students[i].id);
                        printf("Subjects Grades:\n English : %f\n Nepali : %f\n Science : %f\n Math : %f\n", students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].grade[3]);
                        printf("GPA : %f\n", students[i].gpa);
                        break;
                    }
                }
            }
            else if (u == 2)
            {
                for (int i = 0; i < studentcount; i++)
                {
                    printf("NAME : %s\n", students[i].name);
                    printf("ID: %d\n", students[i].id);
                    printf("Subjects Grades:\n English : %f\n Nepali : %f\n Science : %f\n Math : %f\n", students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].grade[3]);
                    printf("GPA : %f\n", students[i].gpa);
                }
            }
            else
            {
                printf("Please choose between 1 and 2 only\n");
            }
            break;
        case 5:
          printf("work in progess");
          break;
          /*
         printf("Do you want to delete all student info or one of them?\n1 for individual\n2 for all students\n");
            scanf("%d", &u);
            if (u == 1)
            {
                int id;

                printf("Student ID : ");
                scanf("%d", &id);
                for (int i = 0; i < studentcount; i++)
                {
                    if (id == students[i].id)
                    {
                      students[i] = NULL;
                        break;
                    }
                }
            }
            else if (u == 2)
            {   char sure;
                printf("Are you sure ? Do you want to delete all data \n y for yess and n for no /n")
                scanf("%c",sure);
                if(sure == 'y' || 'Y'){
                    fscanf
                }
                else{
                break ;
                }
            }
            else
            {
                printf("Please choose between 1 and 2 only\n");
            }
            break;  
            */

        case 6:
            savedata(students, studentcount);
            printf("\nExited..!\n");
            break;
        default:
            printf("Error! Choose a correct option\n");
            break;
        }
    } while (option != 5);

    return 0;
}
