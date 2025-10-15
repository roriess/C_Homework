#pragma once


typedef struct elementFromList {
    int data;
    struct elementFromList* nextElement;
} element;


typedef struct listOfElements {
    element* lastElement;
    element* firstElement;
    int listSize;
} list;


list* createList();

void addElementToList(list* numList, int newElement);

void deleteElementFromList(list* numList, int delElm);

void printTheList(list* numList);
