/*
    Строка из пробелов и групп цифр. В функции найти сумму всех чисел в строке.
*/
#include <stdlib.h>
#include <stdio.h>
int multiply(int n,int times) {
    if (times == 0) {
        return n;
    } else {
        return multiply(n * 10, times - 1);
    }
}
int main(void) {
    char* string = (char *) calloc(1, sizeof(char));
    if (string == 0) return -1;
    rewind(stdin);
    int strLen = 0, sum = 0, valueLength = 0;
    while((string[strLen] = getchar()) != '\n') {
        string = (char*)realloc(string, ++strLen + 1);
    }
    string[strLen] = '\0';
    for (int i = strLen - 1; i >= 0; i--) {
        if (string[i] == ' ') valueLength = 0;
        else sum += multiply(string[i] - '0', valueLength++);
    }
    printf("%d \n", sum);
    return 0;
}
