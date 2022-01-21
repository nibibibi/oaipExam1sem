/*
    Ввести через указатели массив и отсортировать от n до b используя метод Шелла
*/
#include <stdlib.h>
#include <stdio.h>
void shellSort(int* array, int n) {

}
void showArray(int* array, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}
int main(void) {
    int n = 0;
    printf("\n Введите длину массива: ");
    if (scanf("%d" , &n) == 0 || n < 1) return 1;
    int* array = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) == 0) return 1;
    }
    showArray(array, n);
    shellSort(array, n);
    showArray(array, n);
    return 0;
}
