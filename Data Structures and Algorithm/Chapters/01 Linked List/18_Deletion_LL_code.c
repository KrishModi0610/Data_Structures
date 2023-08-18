#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraverse(struct Node *ptr) 
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Case I - Deletion the first Node
struct Node *deleteAtFirst(struct Node *head){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    head = head->next;
    free(ptr);
    return head;
}

// Case II - Deletion in-between Node
struct Node *deleteInBetween(struct Node *head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;
    
    for(int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case III - Deletion the last node
struct Node *deleteLastNode(struct Node *head) {
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }   
    p->next = q->next;
    free(q);
    return head;
}

// Case IV - Deletion node with a specific value
struct Node *deleteSpecificValue(struct Node *head, int number){
    struct Node *p = head;
    struct Node *q = head->next;

    // Checking Whether number is head or not.
    // if head then return head as q = head->next and free p.
    while(head->data == number) {
        free(p);
        return q;
    }

    // Checking Whether number is present or not.
    while(q->data != number && q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    // if present number other then free(q).
    if(q->data == number) {
        p->next = q->next;
        free(q);
    }

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
    sixth->data = 23;
    sixth->next = seventh;

    // Terminate the list at the END NODE
    seventh->data = 16;
    seventh->next = NULL; 

    printf("Before Deletion : ");
    linkedListTraverse(head);

    // Case I Deletion at first/head node
    printf("After Deletion in the Beginning : ");
    head = deleteAtFirst(head);
    linkedListTraverse(head);

    // Case II Deletion a node in-between
    printf("After Deletion in-between : ");
    head = deleteInBetween(head, 4);
    linkedListTraverse(head);

    // Case III Deletion a last node
    printf("After Deletion the last Node : ");
    head = deleteLastNode(head);
    linkedListTraverse(head);

    // Case IV Deletion a node with specific value
    printf("After Deletion a node with specific Value : ");
    head = deleteSpecificValue(head, 41);
    linkedListTraverse(head);

    return 0;
}