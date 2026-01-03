#include <stdio.h>
#include <stdlib.h>

void display(int a[], int size) // function for display
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    };
    printf("\n");
}
int maxx(int *a, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void countsort(int *a, int size)
{
    int max = maxx(a, size);
    int *temp = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        temp[a[i]]++;
    }
    int i = 0, j = 0;
    while (i <= max)
    {

        if (temp[i] > 0)
        {
            a[j] = i;
            j++;
            temp[i]--;
        }
        else
        {
            i++;
        }
    }
    free(temp);
}
int main()
{
    int arr[10];
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        printf("Enter the number :");
        scanf("%d", &arr[i]);
    };
    display(arr, size);
    countsort(arr, size);
    display(arr, size);

    return 0;
}