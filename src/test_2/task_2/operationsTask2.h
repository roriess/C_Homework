#pragma once

typedef struct Node() {
    int value;
    struct Node* next;
} Spisok;

void createNode(int valueElm);

void addToArr(Node** head, int valueElm);

void reverseArr(Node* head);

void compare(Node* reversed, Node* original);

int isSymmetric(Node* head);

void freeArr(Node** head);