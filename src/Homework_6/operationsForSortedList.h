#pragma once

#include "operationsForSortedList.c"


list* createList();

void addElementToList(list* numList, int newElement);

void deleteElementFromList(list* numList, int delElm);

void printTheList(list* numList);
