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

// this function will return a pointer of type struct Node
struct Node *InsertAtFirst(struct Node *head, int data)
{
    // creating new pointer
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // making ptr the new head
    ptr->next = head;
    ptr->data = data;
    return ptr; // returning our new head
}

struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head; // to keep original head safe
    int i = 0;
    while (i != index - 1)
    {
        p = p->next; // for reaching till index-1
        i++;
    }
    ptr->data = data;    // inserting data in new node
    ptr->next = p->next; // for linking the new node to next node
    p->next = ptr;       // for linking the previous node to new node
    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;    // linking last node to new node
    ptr->next = NULL; // linking new node to null
    return head;
}

// inserting after a specific node
struct Node *InsertAfterNode(struct Node *head, int data, struct Node *prevNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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

    printf("Before Insertion\n");
    traversal(head);
    // head = InsertAtFirst(head, 78);
    // head = InsertAtIndex(head, 78,3);
    // head = InsertAtEnd(head, 98);
    head = InsertAfterNode(head, 100, second);
    printf("After Insertion:\n");
    traversal(head);
    return 0;
}