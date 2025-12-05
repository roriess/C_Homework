#include "operationsTask2.h"
#include "testsTask2.c"

int main(void)
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
    if (flag) {
        // не успела :(
    }
}