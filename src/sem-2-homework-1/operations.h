#pragma once

typedef struct {
    const char** data;
    int linesCount;
} Data;

// подсчет кол-ва столбцов таблицы
const int countColumns(Data* data);

// подсчет ширины столбцов
const int* spacesCount(Data* data);

// чтение данных из input.csv в массив указателей на строки
Data* readText(const char* fileName);
