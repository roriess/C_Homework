#include "operationsTask1.c"
#include "testsTask1.c"

int main(int argc, char* argv[])
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
        bool arr[] = { 1, 1, 0 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int maxNum = findMax(arr, size);
        printf("%d", maxNum);
    }

    return 0;
}