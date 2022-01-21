
/*
    Реверс первого и последнего слова в строке
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
    int strLen = 0;
    while ((string[strLen] = getchar()) != '\n') {
        string = (char*) realloc(string, ++strLen + 1);
    }
    string[strLen] = '\0';
    puts(string);
    int wordStart = -1, wordEnd = -1;
    for (int i = 0; i < strLen; i++) {
        if (string[i] != ' ' && string[i] != '\0') {
            if (wordStart == -1) wordStart = i;
            wordEnd = i;
        } else if (wordStart != -1) {
            printf("wordStart is %d \nwordEnd is %d \n", wordStart, wordEnd);
            reverseWord(string, wordStart, wordEnd);
            break;
        }
    }
    wordStart = -1; wordEnd = -1;
    for (int i = strLen - 1; i >= 0; i--) {
        if (string[i] != ' ' && string[i] != '\0') {
            if (wordEnd == -1) wordEnd = i;
            wordStart = i;
        } else if (wordStart != -1) {
            printf("wordStart is %d \nwordEnd is %d \n", wordStart, wordEnd);
            reverseWord(string, wordStart, wordEnd);
            break;
        }
    }
    puts(string);

    return 0;
}