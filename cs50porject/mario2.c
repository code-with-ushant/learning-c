#include <stdio.h>


int main()
{
    int length; // how many height and width do you want ?
    printf("how many height and width do you want ? \n");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("please! Enter positive number or getter then 0\n");
        return 0;
    }
    for (int i = 0; i < length; i++) // Print leading spaces for alignment
    {
        printf("%*s", length - i, "");

        for (int k = 0; k <= i; k++) // Print left side of the pyramid
        {
            printf("#");
        }
        printf(" "); // Print gap between pyramids

        for (int l = 0; l <= i; l++) // Print right side of the pyramid
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}