// In this approach always a new node is taken in parameters rather than taking head
#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head, *tail;

// Traversing and printing the Linked List
void traverse(struct Node *head)
{
    if (head == 0)
    {
        printf("The linked list is empty.\n");
    }

    else
    {
        struct Node *ptr = head;

        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}

void reverseTraverse(struct Node* tail) {
    struct Node* p = tail;
    do{
        printf("%d ", p->data);
        p = p->prev;
    } while(p != tail);
    printf("\n");
}

// Add to an Empty List
struct Node *addToEmpty(struct Node *newNode, int data)
{

    newNode = (struct Node *)malloc(sizeof(struct Node));
    head = tail = newNode;
    newNode->prev = head;
    newNode->next = tail;
    newNode->data = data;

    size++;

    return head;
}

// Case I - Insertion at the Beginning
struct Node *addAtBeginning(struct Node *newNode, int data)
{
    if (head == 0)
    {
        head = addToEmpty(newNode, data);
        return head;
    }
    else
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;

        size++;

        return head;
    }
}

// Case II - Insert at the End
struct Node* addAtEnd(struct Node* newNode, int data) {

    if(head == 0) {
        head = addToEmpty(newNode, data);
        return head;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = data;
    
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail = newNode;

    size++;

    return head;
}

// Case III : Add in between at specific index
struct Node* addAtIndex(struct Node* newNode, int index, int data) {
    if(index == 0) {
        head = addAtBeginning(newNode, data);
        return head;
    }

    else if(index > size) {
        printf("Enter valid Index.\n");
        return head;
    }

    else{
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;

        struct Node* p = head;
        int i = 0;
        while(i != index - 1) {
            p = p->next;
            i++;
        }

        if(p->next == head) {
            head = addAtEnd(newNode, data);
            return head;
        }

        newNode->next = p->next;
        newNode->prev = p;
        p->next = newNode;
        (p->next)->prev = newNode;
    }

    size++;
    
    return head;
}

// Case IV - Deleting the first Node
struct Node* delAtFirst(struct Node* head, struct Node* tail) {
    if(size == 0) {
        printf("Enter element first in the Linked List.\n");
        return head;
    }

    if(size == 1) {
        head = tail = NULL;
        size--;
        return head;
    }

    struct Node* ptr = head;
    head = ptr->next;
    free(ptr);
    ptr = NULL;
    tail->next = head;
    head->prev = tail;

    size--;
    return head;
}

// Case V - Delete the last node of the Linked List
struct Node* delAtLast(struct Node* head, struct Node* tail) {
    struct Node* temp;
    temp = tail->prev;
    if(tail == NULL){
        printf("No elements in the LinkedList.\n");
        return tail;
    }
    
    if(temp == tail) {
        free(tail);
        tail = NULL;
        size--;
        return tail;
    }
    
    temp->next = tail->next;
    tail->next->prev = temp;
    free(temp->next);
    tail = temp;

    return tail;
}

int main()
{
    int data, i, index;

    printf("Doubly Linked List : \n1--> Insert At The Beginning \n2--> Insert At the end \n3-->Insert in-between \n4--> Delete The Beginning \n5--> Delete the end\n6--> Delete in-between \n7--> Print the List \n8--> Size of Linked List \n9--> Search an element in the Linked List \n10-->Exit. \nEnter the code : ");
    scanf("%d", &i);

    while (i >= 1 && i <= 5)
    {
        switch (i)
        {
        case 1:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            head = addAtBeginning(head, data);
            traverse(head);
            reverseTraverse(tail);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 2:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            head = addAtEnd(head, data);
            traverse(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 3:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            printf("Enter the index : ");
            scanf("%d", &index);
            head = addAtIndex(head, index, data);
            traverse(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 4:
            head = delAtFirst(head, tail);
            traverse(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 5:
            head = delAtLast(head, tail);
            traverse(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        default:
            printf("Enter proper Value.");

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        }
        
    }
    return 0;
}