/*
StackTop = Returns the value of the topmost element of the stack - O(1)
StackBottom = Returns the value of the bottommost Element of the Stack - O(1)

Worst Time Complexity  ==> O(1) in Stack
isEmpty() = O(1);
isFull() = O(1);
push() = O(1);
pop() = O(1);
peek() = O(1);
stackTop() = O(1);
stackBottom() = O(1);

===> Code are in previous 27_Peek_Operation.c

A GENERAL STACK OPERATIONS USING STRUCTURE DYNAMICALLY IMPLEMENTING
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
} *sp1;

// isEmpty
int isEmpty(struct stack *p) {
    if(p->top == -1) 
        return 1;
    else 
        return 0;
}

// isFull
int isFull(struct stack *p) {
    if(p->top == p->size - 1) 
        return 1;
    else 
        return 0;
}

// push
int push(struct stack *p, int data) {
    if(!isFull(p)) {
        p->top++;
        p->arr[p->top] = data;
        return 1;
    }
    else 
        printf("Stack OverFlow!! \n");
}

// pop
int pop(struct stack *p) {
    if(!isEmpty(p)) {
        return p->arr[p->top--];
    }
    else 
        printf("Stack UnderFlow!! \n");
}

// peek
int peek(struct stack *p, int index) {
    int arrayInd = p->top - index + 1;
    if(arrayInd < 0) {
        printf("Enter proper index : \n");
    }
    else
        return p->arr[arrayInd];
}

//print the stack
void print(struct stack *p) {
    int val = p->top;
    for(int i = val; i >= 0; i--) {
        printf("%d ", p->arr[i]);
    }
    printf("\n");
}

// stackTop
int stackTop(struct stack *p) {
    return p->arr[p->top];
}

// stackBottom
int stackBottom(struct stack *p) {
    return p->arr[0];
}

int main()
{   
    struct stack *sp1;
    int i, data, index;
    sp1->top = -1;
    printf("Enter the size of the Stack : ");
    scanf("%d", &sp1->size);
    sp1->arr = (int *)malloc(sp1->size * sizeof(int));

    printf("1. push\n2. pop\n3. peek\n4. print the stack\n5. stackTop\n6. stackBottom\n7. isEmpty\n8. isFull\n9. Exit \nEnter the code : ");
    scanf("%d", &i);

    while (i > 0 && i <= 8)
    {
        switch (i)
        {
        case 1:
            printf("Enter data to push : ");
            scanf("%d", &data);
            push(sp1, data);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 2:
            printf("The data is popped out : %d \n", pop(sp1));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 3:
            printf("Enter the index : ");
            scanf("%d", &index);
            printf("The data at the index %d is %d\n", index, peek(sp1, index));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 4:
            print(sp1);

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 5:
            printf("Stack Top : %d \n", stackTop(sp1));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 6:
            printf("Stack Bottom : %d \n", stackBottom(sp1));

            printf("Enter the code : ");
            scanf("%d", &i);
            break;

        case 7:
            if(isEmpty(sp1)) 
                printf("Stack is Empty!!\n");
            else 
                printf("Stack is Not-Empty\n");

            printf("Enter the code : ");
            scanf("%d", &i);
            break;
        
        case 8:
            if(isFull(sp1)) 
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
