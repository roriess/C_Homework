#pragma once

// подсчет кол-ва запятых в одной строке для определения кол-ва столбцов таблицы
int countCommas(const char* str);

// подсчет ширины столбцов
int* spacesCount(const char* str, int columnCount);

// чтение данных из input.csv и добавление (с итоговым форматированием) в output.txt
void readAndAddText(char* newFileName, const char* oldFileName);
