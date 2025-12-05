#include "operationsTask2.h"

void createNode(int valueElm)
{
    Node* elm = malloc(sizeof(Node));
    elm->value = valueElm;
    elm->next = NULL;
}

void addToArr(Node** head, int valueElm)
{
    Node* elm = createNode(valueElm);
    if (*head == NULL) {
        *head = elm;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = elm;
}

Node* reverseArr(Node* head)
{
    Node* reversed = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* elm = createNode(current->value);
        elm->next = reversed;
        reversed = elm;
        current = current->next;
    }
    return reversed;
}

int compare(Node* reversed, Node* original)
{
    int rev = reversed->value;
    int orig = original->value;
    while (rev != NULL && orig != NULL) {
        if (rev != orig)
            return 0;
        rev = reversed->next->value;
        orig = original->next->value;
    }
    return (rev == NULL && orig == NULL);
}

int isSymmetric(Node* head)
{
    Node* reversed = reverseArr(head);
    int result = compare(reversed, head);
    freeArr(&head);
    return result;
}

void freeArr(Node* head)
{
    Node* current = *head;
    Node* nextElm;

    while (current != NULL) {
        nextElm = current->next;
        free(current);
        current = nextElm;
    }
    *head = NULL;
}