/**
 * @file cb_mayor_menor_03.c
 * @brief Determinar el mayor y menor de tres numeros.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/

#include <stdio.h>
int major(int a,  int b, int c){
   return (a>b)? ((a>c)?a:c): ((b>c)?b:c);
}
int minor(int a,  int b, int c){
   return (a<b)? ((a<c)?a:c): ((b<c)?b:c);
}

int main(){
    printf("El numero mayor es %d ", major(52,23,23));
    printf("El numero menor es %d ", minor(52,23,23));
    return 0;
}