// COUNTING NUMBER OF ELEMENTS IN A LINKED LIST AND SEARCHING ELEMENT
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
        printf("No elements present in linked List. \n");
        
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

// Counting
void count(struct Node* tail) {
    if(tail == NULL) {
        printf("Linked List is EMPTY.");
    }

    // Because only 1 element is present i.e. tail->next = tail
    int count = 1; 
    struct Node* temp = tail->next;
    while(temp != tail) {
        temp = temp->next;
        count++;
    }

    printf("No. of Elements = %d \n", count);

}

// Searching in an linked list
int search(struct Node* tail, int Number) {
    struct Node* ptr = tail->next;
    int index = 0;

    if(tail == NULL) {
        return -1;
    }

    do {
        if(ptr->data == Number) {
            return index;
        }
        ptr = ptr->next;
        index++;
    } while(ptr != tail->next);

    return -2;
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
    int element;

    tail = CreateLinkedList(tail);
    if(tail != NULL) {
        printf("Elements : ");
    }
    printList(tail);

    count(tail);

    printf("Enter the element to search : ");
    scanf("%d", &element);
    int searchElement = search(tail, element);
    if(searchElement == -1) {
        printf("Linked list is empty");
    }
    else if(searchElement == -2) {
        printf("Element is not present.");
    }
    else 
        printf("Index of Element %d = %d", element, searchElement);

    return 0;
}