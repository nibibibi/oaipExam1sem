/*
    Рекурсивно транспонировать матрицу относительно побочной диагонали.
*/
#include <stdlib.h>
#include <stdio.h>
void swap(int** matrix, int n, int row ,int column) {
    if (column < n - row - 1) {
		int tmp;
		tmp = matrix[row][column];
		matrix[row][column] = matrix[n - column - 1][n - row - 1];
		matrix[n - column - 1][n - row - 1] = tmp;
		swap(matrix, n, row, column + 1);
	}
	else {
		if (row < n) {
			swap(matrix, n, row + 1, column = 0);
		}
		else return;
	}
}

int main(void) {
    int n = 0; // Порядок матрицы
    if ((scanf("%d", &n) == 0) || (n < 1)) return 1; // Если введено что-то не то либо меньше 1 -> исключение

    int** matrix = (int**) calloc(n, sizeof(int *)); // Указатель под матрицу
    if (!matrix) return 1; // Если не выделилось -> исключение

    for (int i = 0; i < n; i++) { // Для каждой строки
        matrix[i] = (int*) calloc(n, sizeof(int)); // Выделяется n интов
        if (!matrix[i]) return 1; // Если не выделилось -> исключение
    }

    for (int i = 0; i < n; i++) { // Для каждой строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            if (scanf("%d", &matrix[i][j]) == 0) { // Получить инт(если инт не получен -> исключение)
                return 1;
            }
        }
    }

    for (int i = 0; i < n; i++) { // Для каждой строки
        printf("\n"); // Перевод строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            printf("%d ", matrix[i][j]); // Напечатать инт
        }     
    }
    int row = 0; int column = 0;
    swap(matrix, n, row, column);

    for (int i = 0; i < n; i++) { // Для каждой строки
        printf("\n"); // Перевод строки
        for (int j = 0; j < n; j++) { // Для каждого элемента в строке
            printf("%d ", matrix[i][j]); // Напечатать инт
        }     
    }
    return 0;
}