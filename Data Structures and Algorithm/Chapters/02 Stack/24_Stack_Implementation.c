// IsEmpty and IsFull Operations
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

// Stack is Empty
int isEmpty(struct stack *ptr) {
    if(ptr->top == -1) 
        return 1;
    else 
        return 0;
}

// Stack is FULL
int isFull(struct stack *ptr) {
    if(ptr->top == ptr->size - 1) 
        return 1;
    else 
        return 0;
}

int main() {
    // struct stack s;
    // s.top = -1;
    // printf("Enter the size of the Array : ");
    // scanf("%d", &s.size);
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *s;
    s->top = -1;

    printf("Enter the size of the Array : ");
    scanf("%d", &s->size);
    
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Manually Entering Data
    s->arr[0] = 45;
    s->top++;

    // Check whether stack is empty
    if(isEmpty(s))
        printf("Stack is Empty! \n");
    else 
        printf("Stack is not Empty! \n");

    // Check whether stack is full
    if(isFull(s))
        printf("Stack is Full! \n");
    else 
        printf("Stack is not Full! \n");

    return 0;
}