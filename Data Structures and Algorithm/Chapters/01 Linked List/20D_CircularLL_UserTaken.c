#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* addToEmpty(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

struct Node* addAtBeg(struct Node* tail, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;

    return tail;
}

struct Node* addAtEnd(struct Node* tail, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;

    return tail;
}

struct Node* addAfterPos(struct Node* tail, int data, int position){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* temp = tail->next;

    int i = 1;
    while(i != position) {
        temp = temp->next;
        i++;
    }

    ptr->next = temp->next;
    temp->next = ptr;
    if(temp == tail) {
        tail = tail->next;
    }

    return tail;
}

void printList(struct Node* tail) {
    if(tail == NULL) {
        printf("No elements added in linked List.");
    }
    else {
        struct Node* temp = tail->next;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != tail->next);
        printf("\n");
    }
}

struct Node* CreateLinkedList(struct Node* tail){
    int i, n, data;
    printf("Enter number of Elements enter in Linked List : ");
    scanf("%d", &n);

    if(n <= 0) 
        return tail;
    
    printf("Enter Element 1 : ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for(i = 1; i < n; i++) {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }

    return tail;
}

int main() {
    
    struct Node* tail = NULL;
    tail = CreateLinkedList(tail);
    if(tail != NULL) {
        printf("Elements : ");
    }
    printList(tail);

    return 0;
}