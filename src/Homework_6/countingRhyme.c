#include <stdio.h>

#include <stdlib.h>

#include "operationsForList.h"

int main(void)
{
    int warriorsNum, killNum;
    printf("Enter the number of warriors and the serial number of the warrior to be killed: ");
    if (scanf("%d %d", &warriorsNum, &killNum) != 2) {
        printf("Failed to read integer.\n");
        return 1;
    }

    list* warriorsList = createList();
    for (int i = 1; i <= warriorsNum; i++)
        addElementToList(warriorsList, i);

    warriorsList->lastElement->nextElement = warriorsList->firstElement; // make the list cyclical

    element* current = warriorsList->firstElement;
    element* prev = warriorsList->lastElement; // because the last one is in front of the first in the circle
    element* toKill = NULL;

    while (warriorsList->listSize > 1) {
        for (int i = 1; i < killNum; i++) { // moving to the next warrior to be killed
            prev = current;
            current = current->nextElement;
            if (current  == NULL)
                current = warriorsList->firstElement;
        }
        toKill = current;
        current = current->nextElement;
        prev->nextElement = current;

        if (toKill == warriorsList->firstElement)
            warriorsList->firstElement = current;
        (warriorsList->listSize)--;
        free(toKill);
        toKill = NULL;
    }

    printf("The last alive warrior number: %d\n", warriorsList->firstElement->data);

    free(warriorsList->firstElement);
    free(warriorsList);

    return 0;
}
