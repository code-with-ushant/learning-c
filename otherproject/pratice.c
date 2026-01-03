#include <stdio.h>
#include <conio.h>
#include <string.h>

struct book
{
    char title[20];
    char author[20];
    char publisher[20];
    float price;
};
void display(struct book books[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Book : %d\n", i + 1);
        printf("Title :%s\n", books[i].title);
        printf("Author :%s\n", books[i].author);
        printf("Publisher :%s\n", books[i].publisher);
        printf("Price : Rs %f\n", books[i].price);
    }
}
    void fbbyaouthor(char *au, struct book books[], int size)
    {

        for (int i = 0; i < size; i++)
        {
            if (strcmp(books[i].author, au) == 0)
            {
                printf("Book : %d\n", i + 1);
                printf("Title :%s\n", books[i].title);
                printf("Author :%s\n", books[i].author);
                printf("Publisher :%s\n", books[i].publisher);
                printf("Price : Rs %f\n", books[i].price);
            }
        }
    }

void main()
{
    int size;
    char author[20];
    printf("How manny books do you have ?\n->");
    scanf("%d", &size);
    struct book books[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the title of %d book : ", i + 1);
        scanf("%s", books[i].title);
        printf("Enter the author of %d book : ", i + 1);
        scanf("%s", books[i].author);
        printf("Enter the publisher of %d book : ", i + 1);
        scanf("%s", books[i].publisher);
        printf("Enter the price of %d book : ", i + 1);
        scanf("%f", &books[i].price);
        printf("%d book stored succesfuly ! \n", i + 1);
    }
    display(books, size);
    printf("which author book do you ant to read ? \n->");
    scanf("%s", author);
    fbbyaouthor(author, books, size);
}
