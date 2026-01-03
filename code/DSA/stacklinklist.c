#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *push(Node *top, int data)
{
    // Node * ptr=top;
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("memory allocation failed !");
        return top;
    }
    else
    {
        new->data = data;
        new->next = top;

        return new;
    }
}
Node *pop(Node *top)
{
    if (top == NULL)
    {
        printf("stack is empty");
        return NULL;
    }
    Node *ptr = top;

    int data = ptr->data;

    top = top->next;
    free(ptr);
    printf("the pop number is %d\n", data);
    return top;
}
void peek(Node *top, int value)
{
    Node *ptr = top;
    int count = 1;
    while (ptr != NULL)
    {
        if (count == value)
        {

            printf("the peek value in %d is %d\n", value, ptr->data);
            break;
        }
        else if (count > value)
        {
            printf("please enter positive number or getter then 0 !\n");
            break;
        }

        ptr = ptr->next;
        count++;
    }
}
void printNum(Node *top)
{
    Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void freeMemory(Node *current)
{
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{

    Node *top = (Node *)malloc(sizeof(Node));

    if (!top)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    top->data = 8;
    top->next = NULL;
    top = push(top, 5);
    top = push(top, 4);

    top = push(top, 3);

    top = push(top, 3);
    top = push(top, 5);
    top = push(top, 6);

    top = push(top, 4);
    top = pop(top);
    top = pop(top);

    peek(top, 5);
    printNum(top);
    freeMemory(top);

    return 0;
}
