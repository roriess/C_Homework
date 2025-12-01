#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TWO_TO_52_POWER 4503599527370496.0

union Number {
    double value;
    uint64_t bits;
};

char findNumSign(union Number num);

double findMantissa(union Number num);

int findExponentOfNum(union Number num);