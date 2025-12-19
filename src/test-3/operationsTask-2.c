#include "operationsTask-2.h"
#include <stdio.h>
#include <stdlib.h>

Node* create(int nodeValue)
{
    Node* node = malloc(sizeof(Node));
    if (!node)
        printf("Ошибка выделения памяти\n");
    node->value = nodeValue;
    node->next = NULL;

    return node;
}

void addNode(Node* node, Node* newNode)
{
    node->next = newNode;
}

void print(Node* node)
{
    while (node->next) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("%d\n", node->value);
}

void insertionSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* sorted = NULL;
    Node* cur = head;

    while (cur != NULL) {
        Node* next = cur->next;

        if (sorted == NULL || sorted->value >= cur->value) {
            cur->next = sorted;
            sorted = cur;
        } else {
            Node* tmp = sorted;
            while (tmp->next != NULL && tmp->next->value < cur->value)
                tmp = tmp->next;

            cur->next = tmp->next;
            tmp->next = cur;
        }
        cur = next;
    }

    head = sorted;
}