/*
Lecture 32
Condition for the Balanced Equation
1.While popping stack, stack should not OverFlow, else unbalanced.
2.At EndOfExpression, the stack shoukd be empty, else unbalanced.
*/

// Lecture 33
// Push and Pop Operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LIMIT 100  // -> Global Vaariable

struct stack{
    int size;
    int top;
    char *arr;
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
int push(struct stack *p, char data) {
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
char pop(struct stack *p) {
    if(!isEmpty(p)) {
        return p->arr[p->top--];
    }
    else 
        printf("Stack is Empty / Stack Underflow\n");
    return 0;
}

// Parenthesis Matching
int parenthesisMatch(char *exp) {

    // Creating a stack
    struct stack* sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    //Running the stack
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push(sp, '(');
        }
        else if(exp[i] == ')') {
            if(isEmpty(sp)) {
                return 0;
            }
            pop(sp);
        }
    }

    return isEmpty(sp); 
}
int main() {
    
    char *exp;
    
    printf("Enter String : ");
    fgets(exp, MAX_LIMIT, stdin);

    if(parenthesisMatch(exp)) {
        printf("Parenthesis is Matching.\n");
    }
    else 
        printf("Parenthesis is not Matching.\n");
    return 0;
}