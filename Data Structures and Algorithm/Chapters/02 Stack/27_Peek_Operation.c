// Peek and traversing the Stack Operations
// Lec 28 StackTop and stackBottom Operations
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
int peek(struct stack *p, int i) {
    int arrayInd = p->top - i + 1;  
    if(arrayInd < 0) {
        printf("Enter valid Index:");
        return -1;
    }
    else   
        return p->arr[arrayInd];
}

// Traversing the whole Stack
void print(struct stack *p) {
    int val = p->top;
    for(int i = val; i >= 0; i--) {
        printf("%d ", p->arr[i]);
    }
    printf("\n");
}

//  stackTop
int stackTop(struct stack *p) {
    return p->arr[p->top];
}

// stackBottom
int stackBottom(struct stack *p) {
    return p->arr[0];
}
int main() {
    struct stack *sp;
    sp->size = 10;
    sp->top = -1;

    // printf("Enter the size of the Array : ");
    // scanf("%d", &sp->size);
    
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 100);
    push(sp, 45 );
    push(sp, 78);
    push(sp, 12);
    push(sp, 65);
    
    // printf("%d\n", pop(sp));
    // printf("%d\n", pop(sp));
    // printf("%d\n", pop(sp));
    // printf("%d\n", pop(sp));
    // printf("%d\n", pop(sp));

    // Peeking specific Position
    int j;
    printf("Enter the index to peek : ");
    scanf("%d", &j);
    printf("The value at %d is %d\n", j, peek(sp, j));

    // Printing the Whole stack from top
    // print(sp);

    printf("Stack TOP is %d\n", stackTop(sp));
    printf("Stack BOTTOM is %d\n", stackBottom(sp));
    
    return 0;
}