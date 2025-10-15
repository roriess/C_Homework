#include <stdio.h>
#include <stdlib.h>

#include "operationsForSortedList.h"


list* createList() 
{
    list* numList = malloc(sizeof(list));
    if (numList == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    numList->firstElement = NULL;
    numList->lastElement = NULL;
    numList->listSize = 0;

    return numList;
}


void addElementToList(list* numList, int newElement) 
{
    element* newElm = malloc(sizeof(element));

    if (newElm == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElm->data = newElement;
    newElm->nextElement = NULL;

    if (numList->firstElement == NULL) {
        numList->firstElement = newElm;
        numList->lastElement = newElm;
    } else {
        element* current = numList->firstElement;
        element* prev = NULL;

        while (current != NULL && newElm->data >= current->data) {
            prev = current;
            current = current->nextElement;
        }

        if (prev == NULL) {
            newElm->nextElement = numList->firstElement;
            numList->firstElement = newElm;
        } else {
            prev->nextElement = newElm;
            newElm->nextElement = current;

            if (current == NULL)
                numList->lastElement = newElm;
        }
    }

    (numList->listSize)++;
}


void deleteElementFromList(list* numList, int delElm)
{
    if (numList->listSize == 0 || numList->firstElement == NULL) {
        printf("Error: list is empty!\n");
        exit(EXIT_FAILURE);
    }

    element* current = numList->firstElement;
    element* prev = NULL;

    while (current != NULL && current->data != delElm) {
        prev = current;
        current = current->nextElement;
    }

    if (current == NULL) {
        printf("Error: Element not found!\n");
        exit(EXIT_FAILURE);
    }

    if (prev == NULL) {
        numList->firstElement = current->nextElement;

        if (current->nextElement == NULL)
            numList->lastElement = NULL;
    } else {
        prev->nextElement = current->nextElement;

        if (current->nextElement == NULL)
            numList->lastElement = prev;
    }

    free(current);
    (numList->listSize)--;
}


void printTheList(list* numList) 
{
    element* current = numList->firstElement;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextElement;
    }

    printf("\n");
}
