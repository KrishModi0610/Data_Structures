// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Case VII - printing the data
// Traversing FRONT
void traverseInFront(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Linked List Is Empty.");
    }

    else
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

// void traverseBack(struct Node* head) {
//     struct Node* ptr = head;
//     struct Node* p = (struct Node*)malloc(sizeof(struct Node));

//     while(ptr != NULL){
//         if(ptr->next != NULL){
//             p = ptr;
//         }
//         ptr = ptr->next;
//     }

//     while(ptr != NULL) {
//         printf("%d ", ptr->data);
//         ptr = ptr->prev;
//     }
// }

// Inserting Node in an Empty List
struct Node* addToEmpty(struct Node* head, int data) {
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    size++;

    return head;
}

// Case I - Insert at the Beginning
struct Node *addAtBeg(struct Node *head, int data)
{
    // Inserting node at the beginning
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;

    size++;

    return head;
}

// Case II - Inserting at the End
struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;

    size++;

    return head;
}

// Case III - Inserting in-between at specific Index
struct Node* addInBetween(struct Node* head, int index, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* temp = head;
    struct Node* temp2 = NULL;

    int i = 0;
    while(i != index){
        temp = temp->next;
        i++;
    }

    // If insertion is at the last
    if(temp->next == NULL) {
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
    }

    // Any place other than last
    else {
        temp2 = temp->next;
        ptr->next = temp2;
        temp2->prev = ptr;
        temp->next = ptr;
        ptr->prev = temp;
    }

    size++;

    return head;
}   

// Case IV - Deleting the first Node
struct Node* delAtBeg(struct Node* head) {

    // If only one element is present 
    if(size == 1) {
        head = NULL;
        size--;
        return head;
    }

    // More than one element is present 
    struct Node* ptr = head;
    head = ptr->next;
    head->prev = NULL;
    free(ptr);
    ptr = NULL;

    size--;

    return head;
}

// Case V - Deleting the last Node
struct Node* delAtEnd(struct Node* head) {
    if(size == 1) {
        head = NULL;
        size--;
        return head;
    }

    struct Node* temp = head;
    struct Node* ptr = head->next;

    while(ptr->next != NULL){
        ptr = ptr->next;
        temp = temp->next;
    }
    
    temp->next = ptr->next;
    free(ptr);
    ptr = NULL;

    size--;
    return head;
}

// Case VI - Deleting a specific index
struct Node* delAtIndex(struct Node* head, int index) {
    if(size == 1){
        head = NULL;
        size--;

        return head;
    }
    else if(index >= size || index < 0) {
        printf("Inapropriate Index : ");
        return head;
    }
    else if(index == 0) {
        struct Node* ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        ptr = NULL;

        size --;
        return head;
    }
    else {
        struct Node* ptr = head;
        struct Node* temp = head->next;

        int i = 0;
        while(i != index - 1) {
            ptr = ptr->next;
            temp = temp->next;
            i++;
        }

        if(temp->next == NULL) {
            ptr->next = NULL;
            free(temp);
            temp = NULL;
        }

        else{
            ptr->next = temp->next;
            (temp->next)->prev = ptr;
            free(temp);
            temp = NULL;
        }
        
        size--;
        return head;
    }
}

// Case VIII - Getting size of the Linked
int getSize(struct Node* head) {
    return size;
}

// Case IX - Finding the specific element in the Linked list
int searchElement(struct Node* head, int number) {
    struct Node* ptr = head;
    int index = 0;
    if(ptr == NULL) {
        return -1;
    }
    while(ptr != NULL) {
        if(ptr->data == number) {
            return index;
        }
        ptr = ptr->next;
        index++;
    }

    return -2;
}

int main()
{
    struct Node *head = NULL;

    int i, data, index;

    printf("Doubly Linked List : \n1--> Insert At The Beginning \n2--> Insert At the end \n3-->Insert in-between \n4--> Delete The Beginning \n5--> Delete the end\n6--> Delete in-between \n7--> Print the List \n8--> Size of Linked List \n9--> Search an element in the Linked List \n10-->Exit. \nEnter the code : ");
    scanf("%d", &i);

    if(i > 10 || i <= 0) {
        printf("Enter Valid Input.");
    } 

    while (i > 0 && i <= 9)
    {
        switch (i)
        {
        case 1:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            if(size == 0) 
                head = addToEmpty(head, data);
            else
                head = addAtBeg(head, data);
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 2:
            printf("Enter data You want to insert : ");
            scanf("%d", &data);
            if(size == 0) 
                head = addToEmpty(head, data);
            else
                head = addAtEnd(head, data);
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 3:
            printf("Enter data , respectively : ");
            scanf("%d", &data); 
            printf("Enter the index : ");
            scanf("%d", &index);
            if(index <= size) {
                if(size == 0) {
                    head = addToEmpty(head, data);
                }
                else if(index == 0) {
                    head = addAtBeg(head, data);
                }  
                else
                    head = addInBetween(head, index, data);
            } 
            else{
                printf("Index is larger than size.\n");
            }
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 4:
            if(size == 0) {
                printf("Enter data before deletion");
            }
            else 
                head = delAtBeg(head);
            traverseInFront(head);
            
            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 5:
            if(size == 0) 
                printf("Enter data before deletion");
            else 
                head = delAtEnd(head);
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 6:
            if(size == 0) 
                printf("Enter data before deletion.");
            else {
                printf("Enter index to delete : ");
                scanf("%d", &index);
                head = delAtIndex(head, index);
            }
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 7: 
            traverseInFront(head);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        

        case 8:
            size = getSize(head);
            printf("The size of Linked List : %d\n", size);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 9:
            int number;
            printf("Enter number to check : ");
            scanf("%d", &number);
            int search = searchElement(head, number);
            if(search == -1) {
                printf("Zero data in Linked List \n");
            }
            else if(search == -2) {
                printf("Element is not present in Linked List. \n");
            }
            else {
                printf("The index of element %d is %d\n", number, search);
            }

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        }

    }
    return 0;
}