#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    // We are using do-while loop because in while loop if the condition is (ptr->next != head), then the last element won't print...So using do-while loop, using condition (ptr != head) will be the condition after the last element is printed because in do-while loop the ptr is first incremented and then the condition is checked..Hence, it will print the first element by default without checking the condition preventing (ptr == head) in first iteration of condition check
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        // this loop will make p point to the last node of the circular list
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr; // to make ptr the new head
    return head;
}

struct Node *InsertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->next != head)
    {
        // this loop will make p point to the last node
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *InsertAfterNode(struct Node *head, int data, struct Node *q)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = q->next;
    q->next = ptr;
    return head;
}

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr->next;
    ptr->next = head;
    free(head);
    return p;

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

    second->data = 98;
    second->next = third;

    third->data = 56;
    third->next = fourth;

    fourth->data = 23;
    fourth->next = head;

    printf("Before Operation:\n");
    traversal(head);
    printf("\nAfter Operation:\n");
    // head = InsertAtFirst(head, 100);
    // head = InsertAtLast(head, 900);
    // head = InsertAtIndex(head, 800, 2);
    // head = InsertAfterNode(head, 200, third);
    head = DeleteFirst(head);
    traversal(head);
    return 0;
}