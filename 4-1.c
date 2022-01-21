/*
    Фибоначчи рекурсией (там на всякий случай еще через for и while)
*/
#include <stdlib.h>
#include <stdio.h>
int fibonacci(int n){
	if (n <= 2) return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);
}
int main(void) {
    for (int i = 1; i <= 40; i++) {
        printf("\n %d", fibonacci(i));
    }
    return 0;
}