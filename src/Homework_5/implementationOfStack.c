#include <stdio.h>
#include <stdlib.h>

#include "implementationOfStack.h"


Stack* new(void) 
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation error for stack structure\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}


void push(Stack *stack, int element)
{
    if (stack->top + 1 >= STACK_SIZE) {
        printf("Error: stack is overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}


int pop(Stack *stack) 
{
    if (stack->top == -1) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}


int peek(Stack *stack) 
{
    if (stack->top == -1) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}


void del(Stack *stack) 
{
    if (stack)
        free(stack);
}
