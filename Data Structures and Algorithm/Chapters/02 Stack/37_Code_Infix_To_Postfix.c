#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LIMIT 100

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *sp) {
    if(sp->top == -1) 
        return 1;
    else    
        return 0;
}

int isFull(struct stack *sp) {
    if(sp->top == sp->size - 1) 
        return 1;
    else    
        return 0;
}

int push(struct stack *sp, char data) {
    if(!isFull(sp)) {
        sp->top++;
        sp->arr[sp->top] = data;
        return 1;
    }
    else 
        printf("Stack OverFlow!!");
    return 0;
}

char pop(struct stack *sp) {
    if(!isEmpty(sp)) 
        return sp->arr[sp->top--];
    else 
        printf("Stack UnderFlow!!");
    return 0;
}

char stackTop(struct stack *sp) {
    return sp->arr[sp->top];
}

int precedence(char infix) {
    if(infix == '/' || infix == '*' || infix == '%') 
        return 2;
    else if(infix == '-' || infix == '+')
        return 1;
    else 
        return 0;
}

int operator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')  
        return 1;
    else 
        return 0;
}

char *infixToPostfix(char *infix) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track Infix
    int j = 0; // Track Postfix

    while(infix[i] != '\0') {
        if(!operator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else {
            if(precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main() {
    char *infix  = "a-b+c*d/e%f-g";
    
    // printf("Enter String : ");
    // fgets(infix, MAX_LIMIT, stdin);
    printf("Postfix : %s", infixToPostfix(infix));

    return 0;
}