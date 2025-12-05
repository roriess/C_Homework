#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int valueElm);

void addToArr(Node** head, int valueElm);

Node* reverseArr(Node* head);

int compare(Node* reversed, Node* original);

int isSymmetric(Node* head);

void freeArr(Node** head);