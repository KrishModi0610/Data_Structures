// Push and Pop Operations
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

// Pushing Data => Nothing needs to be return
int push(struct stack *p, int data) {
    if(!isFull(p)) {
        p->top++;
        p->arr[p->top] = data;
        return 1;
    }
    else 
        printf("Stack Overflow, Cannot insert %d to the stack\n", data);
    return -1;
    
}

// Popping Data => Value is returned
int pop(struct stack *p) {
    if(!isEmpty(p)) {
        return p->arr[p->top--];
    }
    else 
        printf("Stack is Empty / Stack Underflow\n");
    return 0;
}

// Peeking the data

int main() {
    struct stack *sp;
    sp->size = 10;
    sp->top = -1;

    // printf("Enter the size of the Array : ");
    // scanf("%d", &sp->size);
    
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 100);
    push(sp, 10);
    push(sp, 110);
    push(sp, 120);
    push(sp, 101);
    push(sp, 41);
    push(sp, 42);
    push(sp, 43);
    push(sp, 44);
    push(sp, 45); // Pushed 10 Values
    push(sp, 46); // Stack Overflow
    push(sp, 56); // Stack Overflow

    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp));
    printf("%d\n", pop(sp)); // Popped 10 Values
    printf("%d\n", pop(sp)); // Popped UnderFlow

    return 0;
}