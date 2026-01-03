#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insertionFirst(Node *ptr, int value) {
    Node *head = (Node *)malloc(sizeof(Node));
    if (!head) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    head->data = value;
    head->next = ptr;
    return head;
}

Node *insertionMid(Node *head, int value, int afterValue) {
    Node *ptr = head;
    Node *mid = (Node *)malloc(sizeof(Node));
    if (!mid) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    mid->data = value;

    while (ptr != NULL && ptr->data != afterValue) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        mid->next = ptr->next;
        ptr->next = mid;
    } else {
        printf("Value %d not found in the list\n", afterValue);
        free(mid);
    }
    return head;
}

Node *insertionEnd(Node *head, int value) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (!ptr) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->data = value;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ptr;
    return head;
}

Node *deletionFirst(Node *ptr) {
    if (ptr == NULL) return NULL;
    Node *p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}

Node *deletionMid(Node *head, int value) {
    if (head == NULL) return NULL;
    Node *ptr = head;
    Node *p = NULL;

    while (ptr != NULL && ptr->data != value) {
        p = ptr;
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        if (p != NULL) {
            p->next = ptr->next;
        } else {
            head = ptr->next;
        }
        free(ptr);
    } else {
        printf("%d is not found!\n", value);
    }
    return head;
}

Node *deletionAtEnd(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    Node *p = NULL;
    while (ptr->next != NULL) {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return head;
}

void printNum(Node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void freeMemory(Node *current) {
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *a = (Node *)malloc(sizeof(Node));
    Node *b = (Node *)malloc(sizeof(Node));
    Node *c = (Node *)malloc(sizeof(Node));
    Node *d = (Node *)malloc(sizeof(Node));

    if (!a || !b || !c || !d) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    a->data = 8;
    a->next = b;
    b->data = 5;
    b->next = c;
    c->data = 6;
    c->next = d;
    d->data = 7;
    d->next = NULL;

    a = insertionFirst(a, 3);
    a = insertionMid(a, 5, 8);
    a = insertionEnd(a, 23);
    a = deletionFirst(a);
    a = deletionMid(a, 5);
    a = deletionAtEnd(a);
    printNum(a);
    freeMemory(a);

    return 0;
}
