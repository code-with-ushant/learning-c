#include <stdio.h>
#include <string.h>
typedef struct student
{
    char name[23];
} st;
void display(st students[], int ns)
{
    for (int i = 0; i < ns; i++)
    {
        printf("%s ", students[i].name);
    }
}
void shorting(st students[], int ns)
{

    for (int i = 0; i < ns; i++)
    {
        for (int j = (i + 1); j < ns; j++)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                char temp[23];
                strcpy(temp, students[i].name);

                strcpy(students[i].name, students[j].name);
                strcpy(students[j].name, temp);
            }
        }
    }
}
int main()
{
    st students[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the name of student %d : ", (i + 1));
        scanf("%s", students[i].name);
    }
    printf("Name before shorting ! \n");

    display(students, 5);
    printf(" \n name is sorting>>>>>....\n");
    shorting(students, 5);

    printf("Name after shorting ! \n");
    display(students, 5);

    return 0;
}