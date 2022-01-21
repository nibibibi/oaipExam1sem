/*
    Даны две строки. В функции в большую строку записать меньшую с элемента n.
*/
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    char* string1 = (char*)calloc(1, sizeof(char));
    if(!string1) return 1;
    char* string2 = (char*)calloc(1, sizeof(char));
    if(!string2) return 2;
    int strLen1 = 0, strLen2 = 0;
    rewind(stdin);
    while ((string1[strLen1] = getchar()) != '\n') {
        string1 = (char*)realloc(string1, ++strLen1 + 1);
        if (!string1) return 1;
    }
    string1[strLen1] = '\0';
    rewind(stdin);
    while ((string2[strLen2] = getchar()) != '\n') {
        string2 = (char*)realloc(string2, ++strLen2 + 1);
        if (!string2) return 1;
    }
    string2[strLen2] = '\0';
    puts(string1);
    puts(string2);
    int n = 0;
    if (scanf("%d", &n) == 0 || n < 1) return 1;
    if (strLen1 > strLen2) {
        if (n > strLen1) return 1;
        string1 = (char*)realloc(string1, strLen2);
        for (int i = n - 1; i <= strLen2; i++) {
            string1[i] = string2[i];
        }
    } else {
        if (n < strLen2) return 1;
        string2 = (char*)realloc(string2, strLen1);
        for (int i = n - 1; i <= strLen1; i++) {
            string2[i] = string1[i];
        }
    }
    puts(string1);
    puts(string2);
    return 0;
}