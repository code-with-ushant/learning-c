#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    int size;
    int top;
    char *arr;
} stack;

void push(stack *s, char value)
{
    if (s->size - 1 == s->top)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("%c pushed successfully\n", value);
    }
}

int pop(stack *s)
{
    if (s->top < 0)
    {
        printf("Stack is empty\n");
        return 0;
    }
    char data = s->arr[s->top];
    s->top--;
    printf("Popped data is %c\n", data);
    return 1;
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *a = "1()()()";
    int leanth= strlen(a);

    for (int i = 0; i < leanth; i++)
    {
        if (a[i] == '(')
        {
            push(s, a[i]);
        }
        else if (a[i] == ')')
        {
            if (pop(s) == 0)
            {
                printf("parenthesis is not matching\n");
            
                free(s->arr);
                free(s);

                return 0;
            }
        }
    }

if (s->top == -1)
{
    printf("parenthesis are matching\n");
}
else
{
    printf("parenthesis are not matching\n");
}
// Free allocated memory
free(s->arr);
free(s);

return 0;
}
