#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
} Node;
 void printdoubley(Node*head){
    Node* ptr=head;
   while (ptr!=NULL)
   { printf("%d\n",ptr->data);
    ptr=ptr->next;
   };
   
 }
 void printrevers(Node*head){
     Node* ptr=head;
     while (ptr->next!=NULL)
     {
       ptr=ptr->next;
     }
     
   while (ptr!=NULL)
   { printf("%d\n",ptr->data);
    ptr=ptr->previous;
   };
 }
Node* insertionafterdata(Node*head,int data,int value){
       Node* ptr=head;
       Node*r;
       Node*p=(Node*)malloc(sizeof(Node));
       p->data=value;
   while (ptr->data!=data && ptr != NULL)
   { 
    ptr=ptr->next;
   };
   p->next=ptr->next;
   p->previous=ptr;
   ptr->next->previous=p;
   ptr->next=p;
   
   return head;
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *n1 = (Node *)malloc(sizeof(Node));
    Node *n2 = (Node *)malloc(sizeof(Node));
    Node *n3 = (Node *)malloc(sizeof(Node));
    Node *end = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        printf("memory alocation is fail");
    }
    head->data = 12;
    head->next = n1;
    head->previous = NULL;
    n1->data = 14;
    n1->next = n2;
    n1->previous = head;
    n2->data = 16;
    n2->next = n3;
    n2->previous = n1;
    n3->data = 17;
    n3->next =end;
    n3->previous = n2;
    end->data=18;
    end->next=NULL;
    end->previous=n3;
  printf("printing the nodes data\n");
   insertionafterdata(head,12,13);
   insertionafterdata(head,14,15);

    printdoubley(head);
    printf("revers verson\n");
    printrevers(head);
    return 0;
}