#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next; //self referencing structure
};

void traversal(struct Node *ptr){
    // ptr points to the whole node
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocating memory in heap for nodes of linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second; //linking head node to second node

    second->data = 7;
    second->next = third;

    third->data = 11;
    third->next = NULL; //terminating list as this is our last node
    traversal(head);

    return 0;
}