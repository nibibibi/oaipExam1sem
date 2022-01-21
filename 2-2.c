/*
    В функции перемножить две матрицы циклом do...while.
*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n = 0; // Порядок матрицы
    if ((scanf("%d", &n) == 0) || (n < 1)) return 1; // Если введено что-то не то либо меньше 1 -> исключение

    int** firstMatrix = (int**) calloc(n, sizeof(int *)); // Указатель под матрицу
    if (!firstMatrix) return 1; // Если не выделилось -> исключение

    for (int i = 0; i < n; i++) { // Для каждой строки
        firstMatrix[i] = (int*) calloc(n, sizeof(int)); // Выделяется n интов
        if (!firstMatrix[i]) return 1; // Если не выделилось -> исключение
    }

    for (int i = 0; i < n; i++) { // Для каждой строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            if (scanf("%d", &firstMatrix[i][j]) == 0) { // Получить инт(если инт не получен -> исключение)
                return 1;
            }
        }
    }

    int** secondMatrix = (int**) calloc(n, sizeof(int *)); // Указатель под матрицу
    if (!secondMatrix) return 1; // Если не выделилось -> исключение

    for (int i = 0; i < n; i++) { // Для каждой строки
        secondMatrix[i] = (int*) calloc(n, sizeof(int)); // Выделяется n интов
        if (!secondMatrix[i]) return 1; // Если не выделилось -> исключение
    }

    for (int i = 0; i < n; i++) { // Для каждой строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            if (scanf("%d", &secondMatrix[i][j]) == 0) { // Получить инт(если инт не получен -> исключение)
                return 1;
            }
        }
    }

    int** thirdMatrix = (int**) calloc(n, sizeof(int *)); // Указатель под матрицу

    for (int i = 0; i < n; i++) { // Для каждой строки
        thirdMatrix[i] = (int*) calloc(n, sizeof(int)); // Выделяется n интов
        if (!thirdMatrix[i]) return 1; // Если не выделилось -> исключение
    }

    int i = 0, j = 0;
    while (i != n) {
        int k = 0;
        while (k != n) {
            thirdMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            k++;
        }
        j++;
        if (j == n) {
            j = 0;
            i++;
        }
    }
    for (int i = 0; i < n; i++) { // Для каждой строки
        printf("\n"); // Перевод строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            printf("%d ", thirdMatrix[i][j]); // Напечатать инт
        }     
    }
    return 0;
}