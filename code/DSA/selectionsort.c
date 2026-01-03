#include <stdio.h>
void selectionsort(int a[], int size)
{
    for (int i = 0; i < (size - 1); i++) //i refers to minimum number in index //
    {
        for (int j = (i + 1); j < (size); j++)
        {
            if (a[i] > a[j])//swaping the data or value
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
};
void display(int a[], int size)// function for display
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    };
}
int main()
{
    int a[100];
    int size=100;
    for (int i = 0; i < size; i++)// taking the numbers from user
    {
        printf("enter the number : ");
        scanf("%d", &a[i]);
    };
    display(a,size);
    printf("\n");
    selectionsort(a, size);
    display(a, size);

    return 0;
}