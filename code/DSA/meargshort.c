#include <stdio.h>
void display(int a[], int size) // function for display
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    };
    printf("\n");
}
void merge(int a[], int high, int mid, int low)
{
    int b[100], k = low, i = low, j = mid + 1;
    while (j <= high && i <= mid)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
   for (int i=low;i<=high;i++){
    a[i]=b[i];
   }
    
}
void mergeshort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeshort(a, low, mid);
        mergeshort(a, mid + 1, high);
        merge(a, high, mid, low);
    }
}
int main()
{
    int a[10];
    int size = 10;
    
    for (int i = 0; i < size; i++)
    {
        printf("Enter the number :");
        scanf("%d",&a[i]);
    };
    
    display(a, size);
   
    mergeshort(a, 0, size-1);
    display(a, size);

    return 0;
}