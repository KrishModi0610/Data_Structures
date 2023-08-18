// Using NESO Academy  --> Use of Tail rather than head  
// Manually Taken Data 
// Insertion as well as Deletion , Searching and Count also

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Initially the Linked List is NULL, so entering the first data.
struct Node* addToEmpty(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

// Case 1 Insert At The Beginning
struct Node* addToBeg(struct Node* tail, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;
    return tail;
}

// Case 2 Insert after a given Position
struct Node *addAfterPos(struct Node* tail, int data, int position) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    // Finding Index and traversing till Index
    struct Node* temp = tail->next;
    
    while(position > 1) {
        temp = temp->next;
        position--;
    }

    // Linking Inserting Node to the Circular Linked List
    ptr->next = temp->next;

    // Linking on going traversing pointer to inserting Node ptr
    temp->next = ptr;

    // If the index is last then we have to assign it as the tail 
    if(ptr == tail) {
        tail = tail->next;
    }

    return tail;
}

// Case III - Insertion at the End
struct Node* addAtEnd(struct Node* tail, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    // Linking inserting node to the tail->next i.e. head
    ptr->next = tail->next;

    // Linking tail to the Inserted Node ptr
    tail->next = ptr;

    // Assigning tail to the inserted Node
    tail = tail->next;

    return tail;
}

// Traversing the Linked List and printing Linked list
void printLinkedList(struct Node *tail) {
    if(tail == NULL){
        printf("No elements present in Linked List.");
    }
    else {
        struct Node* ptr = tail->next;
        do{
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while(ptr != tail->next);
    }
    printf("\n");
}

// Case I - Deleting the first Node of Linked List
struct Node* deleteFirstNode(struct Node* tail) {
    // If no element is present
    if(tail == NULL) {
        return tail;
    }
    
    // If only One Element is present
    if(tail->next == tail) {
        free(tail);
        tail = NULL;
        return tail;
    }

    // Assigning head to the Node ptr
    struct Node* ptr = tail->next;

    // Assigning 2nd Node to the tail->next
    tail->next = ptr->next;

    // Free ptr
    free(ptr);
    ptr = NULL;

    return tail;
}

// Case II - Deleting the Last Node of Linked List
struct Node* delLastNode(struct Node* tail) {
    // If no element is present
    if(tail == NULL) {
        return tail;
    }

    // If only One Element is present
    if(tail->next == tail) {
        free(tail);
        tail = NULL;
        return tail;
    } 

    // Traversing till last Node
    struct Node* temp = tail->next;
    while(temp->next != tail) {
        temp = temp->next;
    }


    temp->next = tail->next;
    free(tail);
    // Assigning tail to the temp
    tail = temp;

    return tail;
}

// Case III - Deleting the intermediate node
struct Node* delGivenPos(struct Node* tail, int position) {
    if(tail == NULL) {
        return tail;
    }

    if(tail->next == tail) {
        tail = NULL;
        free(tail);
        return tail;
    }

    // Traversing till the position is reached
    struct Node* ptr = tail->next;


    // If position is head
    if(position == 1) {
        tail->next = ptr->next;
        free(ptr);
        ptr = NULL;
        return tail;
    }   

    // Position other than head
    int i = 1;
    while(i != position - 1) 
    {
        ptr = ptr->next;
        i++;
    }

    // Once position is reached that node is assigned to temp Node
    struct Node* temp = ptr->next;

    // Linking next of position to the traversing pointer
    ptr->next = temp->next;

    // if position is last ,assigning traversing pointer as tail
    if(temp == tail)
        tail = ptr;

    return tail;
}

// Counting in an Linked List
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

    printf("No. of Elements = %d\n", count);
}

// Searching in an linked list
int search(struct Node* tail, int Number) {
    struct Node* ptr = tail->next;
    int index = 0;

    if(tail == NULL) {
        return -2;
    }

    do{
        if(ptr->data == Number) {
            return index;
        }
        ptr = ptr->next;
        index++;
     
    }while(ptr != tail->next);

    // In case if element is not present
    return -1;
}

int main() {
    struct Node* tail = NULL;
    printf("Before Insertion : ");
    printLinkedList(tail);

    //  Added to the empty Linked List
    tail = addToEmpty(45);
    printf("Insertion in Empty Linked List: ");
    printLinkedList(tail);

    // Case I - Insertion at the beginning
    tail = addToBeg(tail, 100);
    tail = addToBeg(tail, 78);
    printf("Insertion At Beginning : ");
    printLinkedList(tail);

    // Case 2 Insert after a given Position
    tail = addAfterPos(tail, 55, 2);
    tail = addAfterPos(tail, 99, 3);
    printf("Insertion after a given Position : ");
    printLinkedList(tail);

    // Case III - Insertion at the End
    tail = addAtEnd(tail, 2);    
    printf("Insertion At the End : ");
    printLinkedList(tail);

     // Case I - Deleting the first Node of Linked List
    tail = deleteFirstNode(tail);
    printf("Deletion first Node : ");
    printLinkedList(tail);

    // Case II - Deleting the Last Node of Linked List
    tail = delLastNode(tail);
    printf("Deletion last Node : ");
    printLinkedList(tail);

    // Case III - Deleting the intermediate node
    printf("Deletion Given Position : ");
    tail = delGivenPos(tail, 5);
    printLinkedList(tail);

    // Counting Number of elements
    // count(tail);

    // tail == NULL;
    // Searching in a Linked List
    int element;
    printf("Enter the element to search : ");
    scanf("%d", &element);
    int searchElement = search(tail, element);
    if(searchElement == -2) {
        printf("Linked list is empty");
    }
    else if(searchElement == -1) {
        printf("Element is not present.");
    }
    else 
        printf("Index of Element %d = %d", element, searchElement);
    return 0;
} 