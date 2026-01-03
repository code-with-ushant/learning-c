#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void printNum(Node *ptr) {
    if (ptr == NULL) return;
    Node* head = ptr;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

Node* insertionatfirst(Node* head, int value) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    Node* p = head;
    ptr->data = value;
    if (head == NULL) {
        ptr->next = ptr; // Point to itself if it's the only node
        return ptr;
    }
    while (p->next != head) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

void freeList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    Node* c = (Node*)malloc(sizeof(Node));
    if (head == NULL || a == NULL || b == NULL || c == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    head->data = 5;
    head->next = a;
    a->data = 6;
    a->next = b;
    b->data = 7;
    b->next = c;
    c->data = 8;
    c->next = head;

    head = insertionatfirst(head, 2);
    printNum(head);

    freeList(head);

    return 0;
}
