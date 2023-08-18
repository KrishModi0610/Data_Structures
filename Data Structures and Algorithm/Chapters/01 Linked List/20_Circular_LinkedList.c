#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Traversing Circular Linked List
void CircularLinkedListTraversal(struct Node *head) {
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

// Insertion At First
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;

    while(p->next != head) {
        p = p->next;
    }
    // P is at the last node at this point of time


    // Pointing p to the insertion node
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

// Insertion in-between
struct Node *insertInBetween(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    // Finding Index
    int i = 0;
    while(i != index - 1) {
        p = p->next;
        i++;
    }

    // Setting Data
    ptr->data = data;

    // Linking link of inserting pointer to the p->next pointer
    ptr->next = p->next;

    // Linking p->next to the inserting pointer
    p->next = ptr;

    return head;
}

// Case III - Insertion at Last
struct Node *insertAtLast(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // Setting data
    ptr->data = data;

    struct Node *p = head;

    while(p->next != head) {
        p = p->next;
    }

    // Linking inserting node to the p->next
    ptr->next = p->next; // i.e. head

    // Linking p->next to the inserting Node
    p->next = ptr;

    return head;
}

// Case IV - Inserting after a specific Node
struct Node *insertAfterNode(struct Node *ptr, int data) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    p->data = data;
    p->next = ptr->next;
    ptr->next = p;

    return ptr;
}

// Case V - Inserting after a specific value
struct Node *insertAfterValue(struct Node *head, int value, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;  

    while(p->data != value) {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // lINKED FIRST AND SECOND NODE
    head->data = 7;
    head->next = second;

    // lINKED SECOND AND THIRD NODE
    second->data = 78;
    second->next = third;

    // LINKED THIRD AND FOURTH NODE
    third->data = 54;
    third->next = fourth;

    // LINKED FOURTH AND FIFTH
    fourth->data = 99;
    fourth->next = fifth; 

    // LINKED FIFTH TO HEAD
    fifth->data = 41;
    fifth->next = head;

    printf("Before Insertion : ");
    CircularLinkedListTraversal(head);

    // Case 1 - Insertion At First
    printf("Insertion at First : ");
    head = insertAtFirst(head, 88);
    CircularLinkedListTraversal(head);

    // Case 2 - Insertion in-between
    printf("Insertion in-between : ");
    head = insertInBetween(head, 10, 2);
    CircularLinkedListTraversal(head);

    // Case 3 - Insertion ar Last
    printf("Insertion at-last : ");
    head = insertAtLast(head, 12);
    CircularLinkedListTraversal(head);

    // Case IV - Inserting after specific Node
    printf("Insertion after specific Node : ");
    second = insertAfterNode(second, 66);
    CircularLinkedListTraversal(head);

    // Case V - Inserting after specific value
    printf("Insertion after specific Node : ");
    head = insertAfterValue(head, 7, 6);
    CircularLinkedListTraversal(head);

    return 0;
}