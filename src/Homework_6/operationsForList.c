#include <stdio.h>
#include <stdlib.h>

#include "operationsForList.h"


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