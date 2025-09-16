#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char s[MAX_LEN], s1[MAX_LEN];

    printf("Enter string S: ");
    fgets(s, MAX_LEN, stdin);
    
    printf("Enter string S1: ");
    fgets(s1, MAX_LEN, stdin);


    s[strcspn(s, "\n")] = '\0';
    s1[strcspn(s1, "\n")] = '\0';

    int len = strlen(s);
    int len1 = strlen(s1);


    int count = 0;

    for (int i = 0; i <= (len - len1); i++) {
        int flag = 1;
        for (int j = 0; j < len1; j++) {
            if (s[i + j] != s1[j]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            count++;
    }

    printf("The number of occurrences of S1 in S as a substring = %d", count);
    return 0;
}