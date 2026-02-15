#pragma once

#include <stdio.h>

typedef struct {
    const char** data;
    int linesCount;
    int columnCount;
} Data;

// чтение данных из input.csv в массив указателей на строки
Data* readText(const char* fileName);

// подсчет кол-ва столбцов таблицы
const int countColumns(Data* data);

// подсчет ширины столбцов
const int* columnWidth(Data* data);

// подсчет ширины таблицы
const int tableWidth(Data* data, const int* countOfSpaces);

// верхняя часть таблицы
void tableTop(FILE* f, Data* data, const int* countOfSpaces);

// нижняя часть таблицы
void tableBottom(FILE* f, Data* data, const int* countOfSpaces);

// толстый разделитель строк
void dividersForTitle(FILE* f, Data* data, const int* countOfSpaces);

// тонкий разделитель строк
void ordinaryDividers(FILE* f, Data* data, const int* countOfSpaces);

// рисование внутренних границ таблицы
void drawindLine(FILE* f, Data* data, const int* countOfSpaces, int flag, char* titleDivider, char* ordinaryDivider);

// итоговая рисовка
void dataFormatting(Data* data, const char* newFileName, const int* countOfSpaces);
