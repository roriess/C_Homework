#include "operationsTask-2.c"
#include "test_task-2.c"
#include <stdbool.h>
#include <stdio.h>


void main(int argc, char* argv[])
{
    bool flag = 1;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--test") == 0) {
                runTests();
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        Node* head = create(0);
        Node* cur = head;
        for (int i = 5; i > 1; i--) {
            Node* new = create(i);
            addNode(cur, new);
            cur = new;
        }
        print(head);

        insertionSort(head);
        print(head);
    }
}