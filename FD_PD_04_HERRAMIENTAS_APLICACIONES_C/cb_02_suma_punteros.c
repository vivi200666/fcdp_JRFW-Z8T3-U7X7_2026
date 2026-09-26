/**
 * @file cb_02_suma_punteros.c
 * @brief Cree un programa que sume los valores de un arreglo de enteros utilizando punteros.
El programa debe mostrar el resultado final.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
#include <stdlib.h>
#define N 7
void fill_arr(int *arr, int size){
    for(int i=0; i<size;i++){
        *(arr+i)= rand()% 20 + 1;
    }
}
int sum(int *arr, int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum+=*(arr+i);
    }
    return sum;
}
int main(){
    int size=N;
    int *arr=(int*)malloc(N *sizeof(int));  
    fill_arr(arr,size);
    printf("[");
    for (int i=0; i<size; i++){
        if (i==size-1){ 
            printf("%d", *(arr+i));
        }else{
            printf("%d, ", *(arr+i));
        }
    }
    printf("]");

    printf("la suma del array es: %d", sum(arr,size));
    free(arr);
    return 0;
}