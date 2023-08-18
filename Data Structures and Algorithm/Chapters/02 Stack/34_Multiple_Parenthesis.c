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

int Match(char a, char b) {
    if(a == '(' && b == ')') {
        return 1;
    }
    if(a == '{' && b == '}') {
        return 1;
    }
    if(a == '[' && b == ']') {
        return 1;
    }
    
    return 0;
}
int parenthesisMatching(char *exp) {

    int out;
    // Creating a stack
    struct stack *pc;
    pc->size = strlen(exp);
    pc->top = -1;
    pc->arr = (char *)malloc(pc->size * sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(pc, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(isEmpty(pc)) {
                return 0;
            }
            else 
                // out = pop(pc);
            if(!Match(pop(pc), exp[i])) {
                return 0;   
            }
        }

    }
    return isEmpty(pc);
}

int main() {
    char *exp;
    
    printf("Enter String : ");
    fgets(exp, MAX_LIMIT, stdin);

    if(parenthesisMatching(exp)) {
        printf("Parenthesis is balanced.\n");
    }
    else 
        printf("Parenthesis is not balanced.\n");

    return 0;
}