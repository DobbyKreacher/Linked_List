#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *p = head; //making p the existing head of linked list
    head = head->next;     // making head->next the new head
    free(p);               // deleting existing head
    return head;
}

struct Node *DeleteByIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *q = ptr->next; // this is the element we want to delete
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node *DeleteLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *DeleteAfterNode(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->data != value && q->data != NULL)
    // the second condition is for a value that is not in linked list. If q reaches last node and still does not find the value then the loop will be terminated
    {
        q = q->next;
        ptr = ptr->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 45;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 68;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    printf("Before Deletion:\n");
    traversal(head);

    printf("\nAfter Deletion:\n");
    // head = DeleteFirst(head);
    // head = DeleteByIndex(head, 1);
    // head = DeleteLast(head);
    head = DeleteAfterNode(head, 68);
    traversal(head);
    return 0;
}