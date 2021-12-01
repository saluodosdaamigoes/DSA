#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;

void createLinkedList1(struct node *LL1, int x)
{
    if (start1 == NULL)
    {
        struct node *first = (struct node *)malloc(sizeof(struct node));
        first->data = x;
        first->next = NULL;
        start1 = first;
        return;
    }
    struct node *end1 = start1;
    while (end1->next != NULL)
    {
        end1 = end1->next;
    }
    LL1 = (struct node *)malloc(sizeof(struct node));
    LL1->data = x;
    end1->next = LL1;
    LL1->next = NULL;
}

void display1(struct node *LL1)
{
    LL1 = start1;
    while (LL1 != NULL)
    {
        printf("%d - ", LL1->data);
        LL1 = LL1->next;
    }
}

void createLinkedList2(struct node *LL2, int x)
{
    if (start2 == NULL)
    {
        struct node *first = (struct node *)malloc(sizeof(struct node));
        first->data = x;
        first->next = NULL;
        start2 = first;
        return;
    }
    struct node *end2 = start2;
    while (end2->next != NULL)
    {
        end2 = end2->next;
    }
    LL2 = (struct node *)malloc(sizeof(struct node));
    LL2->data = x;
    end2->next = LL2;
    LL2->next = NULL;
}

void display2(struct node *LL2)
{
    LL2 = start2;
    while (LL2 != NULL)
    {
        printf("%d - ", LL2->data);
        LL2 = LL2->next;
    }
}

void add2LinkedList(struct node *LL1, struct node *LL2, struct node *LL3)
{
    LL1 = start1;
    LL2 = start2;
    LL3 = start3;
    while (LL1 != NULL && LL2 != NULL)
    {
        if (start3 == NULL)
        {
            struct node *first = (struct node *)malloc(sizeof(struct node));
            first->data = LL1->data + LL2->data;
            first->next = NULL;
            start3 = first;
            LL1 = LL1->next;
            LL2 = LL2->next;
        }
        else
        {
            struct node *end3 = start3;
            while (end3->next != NULL)
            {
                end3 = end3->next;
            }
            LL3 = (struct node *)malloc(sizeof(struct node));
            LL3->data = LL1->data + LL2->data;
            end3->next = LL3;
            LL3->next = NULL;
            LL1 = LL1->next;
            LL2 = LL2->next;
        }     
    }
}

void display3(struct node *LL3)
{
    LL3 = start3;
    while (LL3 != NULL)
    {
        printf("%d - ", LL3->data);
        LL3 = LL3->next;
    }
}

int main()
{
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct node *list3 = NULL;
    int n;
    int data;
    printf("\nHow many nodes do you want ");
    scanf("%d", &n);
    printf("\nEnter the data for the first list");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &data);
        createLinkedList1(list1, data);
    }
    printf("\nEnter the data for the second list");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &data);
        createLinkedList2(list2, data);
    }    
    display1(list1);
    printf("\n");
    display2(list2);
    add2LinkedList(list1, list2, list3);
    printf("\n");
    display3(list3);
    return 0;
}
