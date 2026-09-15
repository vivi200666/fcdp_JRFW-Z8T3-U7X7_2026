
/**
 * @file cb_05_suma_digitos.c
 * @brief Implementar una funci´on recursiva que sume los d´ıgitos de un n´umero.
 * @author Viviana Jimenez
 * @date 2026-09-11
*/
#include <stdio.h>
int sum_digits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sum_digits(n/10);
}

int main() {
    int n = 1234;
    printf("La suma es: %d\n", sum_digits(n));
    return 0;
}