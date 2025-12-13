#include "operationsForMergingLists.c"

int main(void)
{
    Node* arr1 = NULL;
    Node* arr2 = NULL;

    int size1 = 10;
    int size2 = 15;

    for (int i = 0; i < size1; i++) {
        addElm(&arr1, i);
    }

    for (int i = 0; i < size2; i++) {
        addElm(&arr2, i);
    }
    print(arr1);
    print(arr2);

    interweaving(arr1, arr2);

    return 0;
}