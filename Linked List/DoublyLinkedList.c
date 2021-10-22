#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insertAtBeg(int x) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    if (start == NULL) {
        start = newNode;
        start->data = newNode->data;
        start->next = NULL;
    }
    newNode->next = start;
    newNode->prev = NULL;
    start->prev = newNode;
    start = newNode;
}

void insertAtEnd(int x) {
    struct node *newNode, *ptr;
    ptr = start;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    if (start == NULL) {
        start = newNode;
        start->data = newNode->data;
        start->next = NULL;
    }
    while (ptr != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL; 
}

void display() {
    struct node *NODE;
    NODE = start;
    while (NODE != NULL) {
        printf("%d - ", NODE->data);
        NODE = NODE->next;
    }
}

int main() {
    insertAtBeg(23);
    insertAtBeg(69);
    display();
    return 0;
} 