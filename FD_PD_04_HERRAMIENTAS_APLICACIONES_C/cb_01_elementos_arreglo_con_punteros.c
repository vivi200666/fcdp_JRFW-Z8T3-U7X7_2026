/**
 * @file cb_01_elementos_arreglo_con_punteros.c
 * @brief Declare un arreglo de 10 enteros. Inicialícelo con valores del 1 al 10. Imprima cada
valor utilizando aritmética de punteros (*(ptr+i)).
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
void print_arr(int *arr){
    printf("[");
    for (int i=0; i<10; i++){
        if(i==10-1){
            printf("%d", *(arr+i)); 
        }else{
            printf("%d, ", *(arr+i));
        }
        
    }
    printf("]");
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    print_arr(arr);
    return 0;
}