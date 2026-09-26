/**
 * @file cb_04_intercambio_de_valores_ptr.c
 * @brief Escriba una función swap(int *a, int *b) que intercambie el contenido de dos
variables usando punteros. Pruebe la funciÓn en el programa principal.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a = 5;   
    int b = 8;     
    printf("Antes del intercambio: %d, %d\n", a, b);
    swap(&a, &b);
    printf("Despues del intercambio: %d, %d\n", a, b);
    return 0;
}