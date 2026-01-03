

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
int isbst(struct node *root)
{
    static struct node *prev = NULL;

    if (root != NULL)
    {
        if(!isbst(root->left)){
            return 0;
        };

        if (prev != NULL && root->data <= prev->data)
        {

            return 0;
        }
  
       prev = root;
       return isbst(root->right);
      
    } 
    return 1;
}
struct node* search(struct node* root,int data){
    if(root !=NULL){
        if(root->data==data){
           return root;
        }else if(root->data > data){
              search(root->left,data);    
        }else
          search(root->right,data);
    }else
        return NULL;
    
}

int main()
{
    struct node *root = newNode(50);
    struct node *p1 = newNode(25);
    struct node *p2 = newNode(75);
    struct node *p3 = newNode(10);
    struct node *p4 = newNode(30);
    struct node *p5 = newNode(60);
    struct node *p6 = newNode(80);
    struct node *p7 = newNode(5);
    struct node *p8 = newNode(15);
    struct node *p9 = newNode(27);


    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right =p6;
   p3->left =p7;
    p3->right =p8;
    p4->left =p9;
    
    // isbst(root);
    if(isbst(root)){

        printf("this is bts!\n");
    }else{
        printf("this is not a bts!\n");

    }
     struct node *ptr = search(root,5);
     printf("%d",ptr->data);
    free(root);

    return 0;
}
