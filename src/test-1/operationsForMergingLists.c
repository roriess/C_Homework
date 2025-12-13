#include "operationsForMergingLists.h"

Node* createElm(int elm)
{
    Node* newElm = malloc(sizeof(Node*));
    newElm->value = elm;
    newElm->next = NULL;

    return newElm;
}

void addElm(Node** head, int elm)
{

    Node* newElm = createElm(elm);

    if (*head == NULL) {
        *head = newElm;
        return;
    }

    Node* cur = *head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = newElm;
}

Node* interweaving(Node* arr1, Node* arr2)
{
    Node* cur1 = arr1;
    Node* cur2 = arr2;
    Node *next1, *next2;

    while (cur1->next != NULL && cur2->next != NULL) {
        next1 = cur2;
        next2 = cur1->next;
        cur1->next = next1;
        cur2->next = next2;

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    cur1->next = cur2;

    if (cur2 != NULL) {
        while (cur2 != NULL) {
            cur1->next = cur2;
            cur2 = cur2->next;
        }
    }
    return cur1;
}

void print(Node* arr)
{
    while (arr->next != NULL) {
        printf("%d ", arr->value);
        arr = arr->next;
    }
    printf("%d\n", arr->value);
}

void freeArr(Node* arr)
{
    Node* tmp;
    while (arr->next != NULL) {
        tmp = arr->next;
        free(arr);
        arr = tmp;
    }
    free(arr);
    free(tmp);
}