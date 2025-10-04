#pragma once

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct
{
    int data[STACK_SIZE];
    int top;
} Stack;

Stack* new(void);

void push(Stack *stack, int element);

int pop(Stack *stack);

int peek(Stack *stack);

void del(Stack *stack);
