/**
 * @file cb_factorial_04.c
 * @brief Calcular el factorial de un numero y verificar si es par o impar.
 * @author Viviana Jimenez
 * @date 11-09-2026
*/

#include <stdio.h>
void factorial(int n){
    int num=1;
    for(int i=1; i<=n;i++){
        num=num*i;
    }
    if(num%2==0){
        printf("El facotial del numero  %d", n);
        printf(" es %d", num);
        printf(" y es par");
    }else{
        printf("El facotial del numero %d", n);
        printf("es %d", num);
        printf(" y NO es par");
    }
}

int main(){
    factorial(5);
    return 0;
}