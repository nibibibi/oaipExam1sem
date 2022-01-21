/*
    Строка. В ФУНКЦИИ реверсивный переворот нечетных слов (отправлять слова по одному)
*/
#include <stdlib.h>
#include <stdio.h>
void reverseWord(char* string, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
    char temp = string[startIndex];
    string[startIndex] = string[endIndex];
    string[endIndex] = temp;
    reverseWord(string, startIndex + 1, endIndex - 1);
    }
}
int main(void) {
    char* string = (char*)calloc(1,sizeof(char));
    if (!string) return 1;
    int strLen = 0, number = 0, leftIndex = 0, rightIndex = 0;
    while ((string[strLen++] = getchar()) != '\n') string = (char*)realloc(string, strLen + 1);
    string[strLen - 1] = '\0';
    for (int i = 0; i < strLen; i++) {
        if (string[i] != ' ' && string[i] != '\0') {
            rightIndex = i;
        }
        if (string[i] == ' ' || string[i] == '\0') {
            
            if ((string[rightIndex] != ' ') && (string[rightIndex] != '\0')) {
                if (++number % 2 == 1) reverseWord(string, leftIndex, rightIndex);
            }
            if (i == strLen - 1) break;
            leftIndex = i + 1; rightIndex = i + 1;
        }
    }
    puts(string);
    return 0;
}