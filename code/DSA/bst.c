

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
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
int checking(struct node *root)
{
    static struct node *prev = NULL;

    if (root != NULL)
    {
        if(!checking(root->left)){
            return 0;
        };

        if (prev != NULL && root->data <= prev->data)
        {

            return 0;
        }
  
       prev = root;
       return checking(root->right);
      
    } 
    return 1;
}

int main()
{
    struct node *p1 = newNode(10);
    struct node *p2 = newNode(2);
    struct node *p3 = newNode(40);
    struct node *p4 = newNode(1);

    struct node *p5 = newNode(5);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    // checking(p1);
    if(checking(p1)){

        printf("this is bts!\n");
    }else{
        printf("this is not a bts!\n");

    }

    free(p1);

    return 0;
}
