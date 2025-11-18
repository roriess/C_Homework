#include <stdio.h>
#include <stdlib.h>

#include "operationsForSortedList.h"
#include "testsForSortedList.c"

int main(int argc, char* argv[])
{
    int flag = 1;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--test") == 0) {
                runTests();
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1) {
        int enteredValue;
        list* numList = createList();

        printf("1 - Add an element\n");
        printf("2 - Delete an element\n");
        printf("3 - Print the list\n");
        printf("0 - Exit\n");
        printf("Enter the command: ");

        scanf("%d", &enteredValue);

        while (enteredValue != 0) {
            if (enteredValue == 1) {
                int newElm;

                printf("Enter new element: ");
                scanf("%d", &newElm);

                addElementToList(numList, newElm);
            }

            if (enteredValue == 2) {
                int delElm;

                printf("Enter del element: ");
                scanf("%d", &delElm);

                deleteElementFromList(numList, delElm);
            }

            if (enteredValue == 3)
                printTheList(numList);

            printf("Enter the command: ");
            scanf("%d", &enteredValue);
        }

        free(numList);
    }
    return 0;
}
