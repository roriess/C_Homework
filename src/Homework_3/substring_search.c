#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char s[MAX_LEN], s1[MAX_LEN];

    printf("Enter string S: ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Enter string S1: ");
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    const char* p = s;
    int count = 0;

    while ((p = strstr(p, s1)) != 0) {
        p++;
        count++;
    }

    printf("The number of occurrences of S1 in S as a substring = %d", count);
    return 0;
}