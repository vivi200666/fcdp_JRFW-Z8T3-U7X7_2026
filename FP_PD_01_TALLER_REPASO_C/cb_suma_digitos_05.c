
/**
 * @file cb_suma_digitos_05.c
 * @brief Implementar una funci´on recursiva que sume los d´ıgitos de un n´umero.
 * @author Viviana Jimenez
 * @date 11-09-2026
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