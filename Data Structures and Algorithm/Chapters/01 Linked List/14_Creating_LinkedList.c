#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraverse(struct Node *ptr)
{
    while(ptr != NULL) 
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // lINKED FIRST AND SECOND NODE
    head->data = 7;
    head->next = second;

    // lINKED SECOND AND THIRD NODE
    second->data = 78;
    second->next = third;

    // LINKED THIRD AND FOURTH NODE
    third->data = 54;
    third->next = fourth;

    // Terminate the list at the THIRD NODE
    fourth->data = 99;
    fourth->next = NULL; 

    linkedListTraverse(head);
    return 0;
}