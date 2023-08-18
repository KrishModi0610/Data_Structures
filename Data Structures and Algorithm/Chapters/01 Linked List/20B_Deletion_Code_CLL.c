// Code has a lot of errors
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head) {
    struct Node *ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

// Case 1 : Deleting First Element
struct Node *deleteAtFirst(struct Node *head) {
    struct Node *p = head;
    struct Node* q = (struct Node *)malloc(sizeof(struct Node));

    while(p->next != head) {
        p = p->next;
    }

    q = p->next;
    p->next = head->next;
    free(q);
    head = p->next;

    return head;
}

// Case 2 : Deleting a specific position
struct Node* deleteAfterPos(struct Node* head, int position) {
    struct Node* p = head;
    struct Node* q = (struct Node *)malloc(sizeof(struct Node));
    int i = 1;

    if(position == 1) {
        head = head->next;
        return head;
    }

    while(i != position - 1) {
        p = p->next;
        i++;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;

    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));

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

    // LINKED FIFTH AND SIXTH
    fifth->data = 41;
    fifth->next = sixth;

    // LINKED SIXTH AND SEVENTH
    sixth->data = 70;
    sixth->next = seventh;

    // LINKED SEVENTH TO HEAD
    seventh->data = 36;
    seventh->next = head;

    printf("Before Insertion : ");
    CircularLinkedListTraversal(head);

    // Case I - Deleting the first Node
    printf("After Insertion : ");
    head = deleteAtFirst(head);
    CircularLinkedListTraversal(head);

    // Case II - Deleting a node in-between 
    printf("After Insertion : ");
    head = deleteAfterPos(head, 1);
    CircularLinkedListTraversal(head);

    // Case III - Deleting the last Node

    // Case IV - Deleting a specific value Node


    return 0;
}