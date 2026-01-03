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
    struct node *p1;
    struct node *p2;
    struct node *p3;
    struct node *p4;
    struct node *p5;

    p1 = nodemaker(1);
    p2 = nodemaker(2);
    p3 = nodemaker(3);
    p4 = nodemaker(4);
    p5 = nodemaker(5);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    printf("%d \n", p1->data);
    printf("%d \n", p1->left->data);

    printf("%d \n", p1->left->left->data);
    printf("%d \n", p1->right->data);
    printf("%d \n", p1->right->right->data);


    free(p1);

    return 0;
}