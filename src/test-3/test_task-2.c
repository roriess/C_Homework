#include "operationsTask-2.h"
#include <stdbool.h>
#include <stdio.h>

bool identicalElements(void)
{
    Node* head = create(0);
    Node* cur = head;
    for (int i = 0; i < 10; i++) {
        Node* new = create(0);
        addNode(cur, new);
        cur = new;
    }

    insertionSort(head);
    cur = head;
    for (int i = 0; i < 10; i++) {
        if (cur->value != cur->next->value)
            return 1;
    }
    return 0;
}

bool ordinaryTest(void)
{
    Node* head = create(0);
    Node* cur = head;
    for (int i = 10; i < 0; i--) {
        Node* new = create(i);
        addNode(cur, new);
        cur = new;
    }

    insertionSort(head);
    cur = head;
    for (int i = 0; i < 10; i++) {
        if (cur->value != cur->next->value)
            return 1;
    }
    return 0;
}

void runTests(void)
{
    bool final = identicalElements() && ordinaryTest();

    if (final) {
        printf("Все тесты прошли успешно\n");
    } else {
        if (!identicalElements())
            printf("Ошибка в массиве с одинаковыми элементами\n");
        if (!ordinaryTest())
            printf("Ошибка в обычном тесте\n");
    }
}