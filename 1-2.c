/*
    В массиве строк найти большее слово и вывести его.
*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n = 0; // Количество строк.
    // printf("\n Введите кол-во строк: ");
    if ((scanf("%d", &n) == 0) || (n < 1)) return -1; // Если введено что-то не то либо меньше 1 -> исключение

    char** strings = (char**) calloc(n, sizeof(char *)); // Указатель на строки.
    if (strings == 0) return -1; // Если не выделилось -> исключение

    for (int i = 0; i < n; i++) { // Для каждой строки
        rewind(stdin);
        strings[i] = (char*) calloc(1, sizeof(char)); // Выделить место.
        if (strings[i] == 0) return 1; // Не выделилось -> исключение
        int j = 0; 
        while((strings[i][j] = getchar()) != '\n') { // Получить символ
            strings[i]=(char*)realloc(strings[i], ++j + 1); // Перевыделить 
        }
        strings[i][j] = '\0';
    }
    for (int i = 0; i < n; i++) {
        printf("\n %s", strings[i]);
    }
    printf("\n");

    int lastLength = 0; // Длина последнего слова
    int longestLength = 0; // Длина самого длинного слова
    int longestIndex = 0; // Индекс последнего символа самого длинного слова
    int stringIn = -1; // Индекс строки в массиве строк в которой находится самое длинное слово
    for (int i = 0; i < n; i++) { // Для каждой строки
        int j = 0;
        while (1) {
            if ((strings[i][j] != ' ') || (strings[i][j] != '\0')) {
                lastLength++;
            }
            if (strings[i][j] == ' ' || strings[i][j] == '\0') {
                if ((lastLength > longestLength)) {
                    longestLength = lastLength;
                    longestIndex = j;
                    stringIn = i; 
                }
                lastLength = 0;
            }
            if (strings[i][j] == '\0') break;
            j++;
        }
    }
    for (int i = longestIndex - longestLength; i <= longestIndex; i++) {
        printf("%c", strings[stringIn][i]);
    }
    return 0;
}