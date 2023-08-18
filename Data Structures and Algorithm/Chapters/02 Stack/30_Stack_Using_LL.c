// Stack using Linked List 
// Lecture 30 -> isFull, isEmpty, Push, Pop
// Lecture 31 -> peek, stackTop, stackBottom

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversing the Linked List
void printLL(struct Node *top) {

    if(top == NULL) 
        printf("No element in the Linked List!! \n");
    
    else {
        while(top != NULL) {
            printf("%d ", top->data);
            top = top->next;
        }
        printf("\n");
    }
}

// IsEmpty Code
int isEmpty(struct Node* top) {
    if(top == NULL) 
        return 1;
    else  
        return 0;
}

// IsFull Code
int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
        return 1;
    else    
        return 0; 
}

// Pushing the Linked List
struct Node *push(struct Node *top, int data) {

    if(!isFull(top)) {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = top;
        top = p;
        return top;     
    }

    else {
        printf("Stack Overflow!! \n");
        return 0;
    }
}

// Popping the data

 //=> Here directly the address of top is sent so ** is used (CASE 1)
// int pop(struct Node **top) {
//     if(!isEmpty(*top)) {
//         struct Node *ptr = *top;
//         *top = (*top)->next;
//         int x = ptr->data;
//         free(ptr);
//         ptr = NULL;
//         return x;
//     }
//     else 
//         printf("Stack UnderFlow!! \n");
// }

// (CASE 2)
struct Node *pop(struct Node *top) {
    if(!isEmpty(top)) {
        struct Node *ptr = top;
        top = top->next;
        printf("Popped element : %d\n", ptr->data);
        free(ptr);
        ptr = NULL;
        return top;
    }
    else 
        printf("Stack UnderFlow!! \n");
}

// Peeking the data
int peek(struct Node* top, int index) {
    struct Node *ptr = top;
    for(int i = 1; (i < index) && (ptr != NULL); i++) {
        ptr = ptr->next;
    }
    if(ptr!=NULL) 
        return ptr->data;
    else 
        return -1;
}

// Stack Top
int stackTop(struct Node *top) {
    if(top == NULL){
        printf("Enter Element in stack\n");
    }
    return top->data;
}

// Stack Bottom
int stackBottom(struct Node *top) {
    if(top == NULL){
        printf("Enter Element in stack\n");
    }
    struct Node *ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node *TOP = NULL;
    int i, data, index;

    printf("1. push\n2. pop\n3. peek\n4. print the stack\n5. stackTop\n6. stackBottom\n7. isEmpty\n8. isFull\n9. Exit \nEnter the code : ");
    scanf("%d", &i);

    while(i > 0 && i <= 8) {
        switch(i) 
        {
        case 1:
            printf("Enter the data you want to push : ");
            scanf("%d", &data);
            TOP = push(TOP, data);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 2:
            // (CASE 1)
            // printf("Data popped out : %d\n",pop(TOP)); // address of top is passed 

            // (CASE 2)
            TOP = pop(TOP);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 3:
            printf("Enter positon : ");
            scanf("%d", &index);
            int val = peek(TOP, index);
            printf("The data at position %d is %d\n", index, val);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 4: 
            printLL(TOP);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 5:
            printf("Stack Top : %d\n", stackTop(TOP));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 6:
            printf("Stack Bottom : %d\n", stackBottom(TOP));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 7:
            if(isEmpty(TOP)) 
                printf("Stack is Empty!!\n");
            else 
                printf("Stack is Not-Empty\n");

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 8:
            if(isFull(TOP)) 
                printf("Stack is Full!!\n");
            else 
                printf("Stack is Not-Full\n");

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        }
    }

    return 0;
}