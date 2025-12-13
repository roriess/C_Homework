#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createElm(int elm);

void addElm(Node** head, int elm);

Node* interweaving(Node* arr1, Node* arr2);

void print(Node* arr);

void freeArr(Node* arr);