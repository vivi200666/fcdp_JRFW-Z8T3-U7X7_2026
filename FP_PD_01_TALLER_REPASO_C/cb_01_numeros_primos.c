/**
 * @file cb_01_numeros_primos.c
 * @brief Generar un arreglo de numeros aleatorios y contar cuantos son primos.
 * @author Viviana Jimenez
 * @date 2026-09-11
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void count(int *arr){
    
    int sum=0;
    for(int i=0; i<N; i++){
        int counter= 0;
        for (int j=1; j<=arr[i];j++){
            if(arr[i]%j==0){
                counter++;
            }
        }
        if (counter==2){
            sum+=1;
        }  
    }
    printf(" Los numeros primos que hay en el arreglo son %d", sum);
}

int main(){
    srand(time(NULL));
    printf("Arreglo");
    
    int *arr=(int*) malloc(N*sizeof(int));
    printf("[");
    for (int i=0; i<N; i++){
        arr[i]=rand() % 100+1;
        if (i==N-1){
            printf("%d", arr[i]);
        }else{
            printf("%d, ", arr[i]);
        }
        
    }
    printf("]");
    count(arr);
    free(arr);
    return 0;
}


