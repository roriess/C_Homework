#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "operationsForSortedList.h"

bool addOneElement()
{
    list* numList = createList();
    int oldSize = numList->listSize;
    addElementToList(numList, 5);
    bool result = (numList->listSize == oldSize + 1) && (numList->lastElement->data == 5) && (numList->lastElement->nextElement == NULL);
    free(numList);
    return result;
}

bool addLargeNumberOfElements()
{
    list* numList = createList();

    for (int i = 20; i > 0; i--) {
        addElementToList(numList, i);
    }

    bool result = 1;
    element* currentElm = numList->firstElement;
    for (int i = 1; i <= 20; i++) {
        if (currentElm->data == i) {
            currentElm = currentElm->nextElement;
        } else {
            result = 0;
        }
    }
    free(numList);
    return result;
}

bool deleteOneElement()
{
    list* numList = createList();
    addElementToList(numList, 3);
    addElementToList(numList, 5);
    addElementToList(numList, 7);
    int oldSize = numList->listSize;

    deleteElementFromList(numList, 5);
    bool result = (numList->listSize == oldSize - 1);
    free(numList);
    return result;
}

bool deleteUncorrectElement()
{
    list* numList = createList();
    addElementToList(numList, 3);
    addElementToList(numList, 5);
    addElementToList(numList, 7);
    int oldSize = numList->listSize;

    deleteElementFromList(numList, 8);

    bool result = (numList->listSize == oldSize);
    free(numList);
    return result;
}

bool emptyList()
{
    list* numList = createList();
    bool result = (numList->listSize == 0) && (numList->lastElement == NULL) && (numList->firstElement == NULL);
    free(numList);
    return result;
}

void runTests()
{
    bool addOneElm = addOneElement();
    bool delete = deleteOneElement();
    bool emptyLst = emptyList();
    bool uncorrectElm = deleteUncorrectElement();
    bool addLargeNumberOfElm = addLargeNumberOfElements();

    bool result = addOneElm && delete && emptyLst && uncorrectElm && addLargeNumberOfElm;
    if (result) {
        printf("All tests passed successfully!\n");
    } else {
        printf("Some tests failed:\n");
        if (!addOneElm)
            printf("- Adding one element failed\n");
        if (!delete)
            printf("- Deleting elements failed\n");
        if (!emptyLst)
            printf("- Creating empty list failed\n");
        if (!uncorrectElm)
            printf("- Handling incorrect deletion failed\n");
        if (!addLargeNumberOfElm)
            printf("- Adding multiple elements failed\n");
    }
    return;
}
