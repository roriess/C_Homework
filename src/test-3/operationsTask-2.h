#pragma once

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create(int nodeValue);

void addNode(Node* node, Node* newNode);

void print(Node* node);

void insertionSort(Node* node);