#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversing LinkedList
void LinkedListTraversal(struct Node *ptr) 
{
    while(ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Case - I Insert At First
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case - II Insert in-between
struct Node *insertInBetween(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // Defining pointer p at head
    struct Node *p = head;
    int i = 0;

    // Incrementing pointer p till it reaches index
    while(i != index - 1) {
        p = p->next;
        i++;
    }

    // Assigning data in the Linked list
    ptr->data = data;

    // Assigning values to inserting point 
    ptr->next = p->next;

    // Linking pointer p to inserting pointer 
    p->next = ptr;

    return head;
}

// Case III - Insertion at the End
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    
    while(p->next != NULL) {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL; // same as p->next
    p->next = ptr;

    return head;
}

// Case IV - Insertion after a Node

 //--. Without the use of Head
// struct Node *InsertAfterNode(struct Node *head, struct Node *prevNode, int data) {    

struct Node *InsertAfterNode(struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    // return head;  //--> Incase if Head is used
    return prevNode;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

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

    printf("Before Insertion at Beginning : ");
    LinkedListTraversal(head);

    // Insertion at the Beginning
    printf("After Insertion at Beginning : ");
    head = insertAtFirst(head, 5);
    LinkedListTraversal(head);

    // Insertion at the Index
    printf("After Insertion at Index : ");
    head = insertInBetween(head, 100, 4);
    LinkedListTraversal(head);

    // Insertion at the End
    printf("After Insertion at End : ");
    head = insertAtEnd(head, 12);
    LinkedListTraversal(head);

    //Insertion after Node
    printf("After Insertion after Node : ");
    // head = InsertAfterNode(head, second, 150);   //--> Incase head is used 
    second = InsertAfterNode(second, 150);
    LinkedListTraversal(head);

    return 0;
}