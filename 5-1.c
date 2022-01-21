/*
    В матрице найти первую седловую точку (min в строке и max в столбце) 
    вывести её на экран, 
    если седловой точки нет - вывести сообщение об этом на экран.
*/
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n = 0;
    if (scanf(" %d", &n) == 0 || n < 1) return 1;
    int** matrix = (int**)calloc(n, sizeof(int*));
    if (!matrix) return 1;
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
        if (!matrix[i]) return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rewind(stdin);
            scanf("%d", &matrix[i][j]);
        }
    }
    int row = -1;
    int column = -1;
    int value = matrix[0][0];
    for (int i = 0; i < n; i++) {
        row = i; column = 0; value = matrix[row][column];
        for (int j = 0; j < n; j++) { // Найти самое малое в строке
            if (matrix[i][j] >= value) continue;
            else value = matrix[i][j];
        }
        for (int j = 0; j < n; j++) { // Для всех элементов равных value
            if (matrix[i][j] == value) {
                for (int k = 0; k < n; k++) { // Пройтись по ряду
                    if (matrix[k][j] > value) // Если в столбце есть элемент побольше
                        k = n; // Ищем дальше
                    if (k == n - 1) { // Если проверили все
                        column = j; // Элемент в этом столбце
                        printf("Седловый элемент в %d строке %d столбце и равен %d\n", row + 1, column + 1, value);
                        k = n; 
                        j = n; // Выходим из циклов
                        i = n;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}