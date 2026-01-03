#include <stdio.h>
#include <conio.h>

void main()
{
    int length; // how many height and width do you want ?
    printf("how many height and width do you want ? \n");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("please! Enter positive number or getter then 0\n");
        return ;
    }
    for (int i = 0; i < length; i++) // Print leading spaces for alignment
    {
        printf("%*s", length - i, "");

        for (int k = 0; k <= i; k++) // Print left side of the pyramid
        {
            printf("#");
        }
       
        printf("\n");
    }
   getch();
}