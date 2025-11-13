#include "implementationOfStack.h"

Stack stack;

void initStack(Stack* stack)
{
    stack->top = -1;
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
