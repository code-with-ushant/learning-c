#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};
struct Node *Nodemaker(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("memorry allocation failed ! \n");
    };
    ptr->data = data;
    ptr->height = 1;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
int isbst(struct Node *root)
{
    static struct Node *prev = NULL;

    if (root != NULL)
    {
        if (!isbst(root->left))
        {

            return 0;
        }
        if (prev != NULL && prev->data > root->data)
        {
            return 0;
        }
        prev = root;
        return isbst(root->right);
    }
    return 1;
}
int max(int a,int b){
    return a>b?a:b;
}
void insertion(struct Node *root, int data)
{
    if (isbst(root))
    {

        struct Node *new;
        new = Nodemaker(data);
        if (root != NULL)
        {
            struct Node *prev;

            while (root != NULL)
            {
                prev = root;
                if (root->data == data)
                {
                    printf("data already found in tree .\n");
                    return;
                }
                else if (root->data > data)
                {
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
            if (prev->data > new->data)
            {
                prev->left = new;
            }
            else
            {
                prev->right = new;
            }
        }
        root = new;
    }
    else
    {
        printf("THIS tree is not bst !");
    }
}
struct Node* inorder(struct Node *root)
{   
    if(root !=NULL){

        root= root->left;
        while (root->right != NULL)
        {
            root= root->right;
        }
        return root ;
    }
    return NULL;
    
   
}
void inordertravelsion(struct Node *root){
    if(root!=NULL){
        inordertravelsion(root->left);
        printf("%d ",root->data);
        inordertravelsion(root->right);

    }
}
struct Node* delet(struct Node *root, int data)
{
    struct Node *prev;
    if (root != NULL)
    {  
         if (root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
         }
   
        if (root->data > data)
        {
           root->left = delet(root->left,data);
        }
        else if (root->data < data)
        {
           
            root->right = delet(root->right,data);
        }
        else {
              prev = inorder(root);
              root->data = prev->data;
              root->left = delet(root->left,prev->data);
                
        }
          return root;
            
        

    }
    return NULL;
    
    
    
}
int getbalancefactor(struct Node* n ){
    if(n != NULL){
        return (n->left->height)-(n->right->height);
    }
    return 0;
}
struct Node* rightrotate(struct Node* root ){
      struct Node* x = root->left;
      struct Node* temp = x->right ;
      x->right = root;
      root->left = temp;
     root->height=max((root->right->height),(root->left->height)) +1;
      x->height=max((x->right->height),(x->left->height)) +1;
      return x;
}
struct Node* leftrotate(struct Node* root ){
    struct Node* y = root->right;
    struct Node* temp = y->left ;
    y->left = root;
    root->right = temp;
   root->height=max((root->right->height),(root->left->height)) +1;
    y->height=max((y->right->height),(y->left->height)) +1;
    return y;
}
struct Node * insert(struct Node* node, int key){
    if(node ==NULL)
    return (Nodemaker(key));
    if(key < node->data){
        node->left= insert(node->left,key);

    }else if (key> node->data)
    {
        node->right= insert(node->right,key);
    }
   return node;
   node->height = 1+ max(node->left->height,node->right->height);
    int bf=getbalancefactor(node);
    // left left case
    if(bf>1 && key < node->left->data ){
        rightrotate(node);
    }
    //right right case
    if(bf<-1 && key > node->right->data ){
              return  leftrotate(node);
    }
    //left right case
    if(bf>1 && key > node->left->data){
       node->left= leftrotate(node->left);
       return rightrotate(node);
    }
    //right left case
    if(bf<-1 && key < node->right->data ){
        node->right = rightrotate(node->right);
       return leftrotate(node);
    }
    return node;
}

int main()
{
    struct Node *root = Nodemaker(5);
   root = insert(root,10);
   root = insert(root,15);
   root = insert(root,14);
   root = insert(root,13);
   root = insert(root,17);
   root = insert(root,19);
   //root = insert(root,100);
   //root = insert(root,12);


   inordertravelsion(root);
  printf("%d",root->right->right->height);
  
  
    return 0;
}