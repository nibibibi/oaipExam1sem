/*
    Два массива вещественных чисел (при вводе должны быть отсортированы по убыванию). 
    В ФУНКЦИИ объединить их в третий массив упорядоченный по убыванию(без сортировки).
*/
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n = 0;
    if (scanf("%d", &n) == 0 || n < 1) return 1;
    double* firstArray = (double*) calloc(1, sizeof(double));
    double* secondArray = (double*) calloc(1, sizeof(double));
    double* thirdArray = (double*) calloc(1, sizeof(double));
    if (!firstArray || !secondArray || !thirdArray) return 1;
    for (int i = 0; i < n; i++) {
        printf("First array %d is: ", i + 1);
        rewind(stdin);
        firstArray = (double*) realloc(firstArray,sizeof(double));
        scanf(" %lf", &firstArray[i]);
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printf("Second array %d is: ", i + 1);
        rewind(stdin);
        secondArray = (double*) realloc(secondArray,sizeof(double));
        scanf(" %lf", &secondArray[i]);
        printf("\n");
    }
    int a = 0, b = 0;
    for (int i = 0; i < 2 * n; i++) {
        thirdArray = (double*) realloc(thirdArray,sizeof(double));
        if (a == n) thirdArray[i] = secondArray[b++];
        else if (b == n) thirdArray[i] = firstArray[a++];
        else if (firstArray[a] > secondArray[b]) thirdArray[i] = firstArray[a++];
        else thirdArray[i] = secondArray[b++];
        printf(" %lf", thirdArray[i]);
    }
    return 0;
}