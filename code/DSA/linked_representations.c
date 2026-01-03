#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *nodemaker(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        fprintf(stderr, "memory allocation failed\n");
    }
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
};

int main()
{
    int size = 5;
    int data;
    struct node *p[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the data for %d node : ", i + 1);
        scanf("%d",&data);
        p[i] = nodemaker(data);
    }

    for (int i = 0; i < size; i++)
    {

        printf("%d \n", p[i]->data);
    }
    for (int i = 0; i<size ; i++){
 
    free(p[i]);
    }
    return 0;
}