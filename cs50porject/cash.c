#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
    // quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int cents;
    float cash;
    do
    {   printf("Enter -1 for quiting..");
        printf("How much do I owe you?:");//getting input from user.
        scanf("%f", &cash);
    } 

            while (cash < 0);//error handling
            cents= round(cash*100);//converting cash in cents.
                while (cents != 0)
            {
                if (cents >= 25)//checking the owed cents is geater than 25cents or not.
                {
                    cents = cents - 25;
                    quarters++;
                }
                else if ( cents >= 10)//checking the owed cents is geater than 10cents or not.
                {
                    cents = cents - 10;
                    dimes++;
                }
                else if (cents >= 5)//checking the owed cents is geater than 5cents or not.
                {
                    cents = cents - 5;
                    nickels++;
                }
                else if ( cents >= 1)//checking the owed cents is geater than 1cents or not.
                {
                    cents = cents - 1;
                    pennies++;
                }
            }

    printf(" Number of coins is %d \nwhich include \n%d quarters, \n%d dimes, \n%d nickels, \n%d pennies.", (quarters + dimes + nickels + pennies), quarters, dimes, nickels, pennies);//showing how many coins should return and which which coins .

    getch();
}