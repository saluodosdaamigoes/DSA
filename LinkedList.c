#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void node_Insert(int x) {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    if (start == NULL) {
        start = new_node;
        start->data = new_node->data;
        start->next = NULL;
        return;
    }
    new_node->next = start;
    start = new_node;
}

void node_insertAtPos(int x, int pos) {
    struct node *new_node, *p;
    p = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    if (pos == 1) {
        new_node->next = start;
        start = new_node;
        return;
    }
    for (int i = 1; i <= pos - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("\n*****THERE ARE NOT THAT MANY ELEMENTS!!!*****");
        return;
    }
    else {
        new_node->next = p;
        p->next = new_node;
        return;
    }
}

void node_DeleteEnd() {
    struct node *ptr, *preptr;
    if (start == NULL) {
        printf("\n*****EMPTY LIST*****"); 
        return; 
    }
    ptr = start;
    while (ptr != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void node_Delete() {
    struct node *ptr;
    if (start == NULL) {
        printf("\n*****EMPTY LIST*****"); 
        return;      
    }
    ptr = start;
    start = start->next;
    free(ptr);
}

void node_InsertEnd(int x) {
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    ptr = start;
    if (start == NULL) {
        start = new_node;
        start->data = new_node->data;
        start->next = NULL;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}

void node_InsertBeforeX1(int x1, int x) {
    struct node *new_node, *preptr, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    if (start == NULL) {
        printf("\n*****EMPTY LIST*****");
        return;
    }
    ptr = start;
    preptr = ptr;
    if (ptr->data != x1) {
        preptr = ptr;
        ptr = ptr->next;
        return;
    }
    preptr->next = new_node;
    new_node->next = ptr;
}

void node_InsertAfterX1(int x1, int x) {
    struct node *new_node, *preptr, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    if (start == NULL) {
        printf("\n*****EMPTY LIST*****");
        return;
    }
    ptr = start;
    preptr = ptr;
    if (preptr->data != x1) {
        preptr = ptr;
        ptr = ptr->next;
        return;
    }
    preptr->next = new_node;
    new_node->next = ptr;
}

void display() {
    struct node *NODE;
    NODE = start;
    if (NODE == NULL) {
        printf("\n***** LIST IS EMPTY!!!! ******");
        return;
    }
    while (NODE->next != NULL) {
        printf("%d - ", NODE->data);
        NODE = NODE->next;
    }
    printf("%d\n ", NODE->data);
}

int main() {    
    int n, value;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        node_Insert(value);
    }
    node_InsertEnd(23);
    int valX1;
    scanf("%d", &valX1);
    node_InsertBeforeX1(valX1, 77);
    scanf("%d", &valX1);
    node_InsertAfterX1(valX1, 62);
    display();
    node_Delete();
    display();
    node_insertAtPos(23, 2);
    display();
    return 0;
}