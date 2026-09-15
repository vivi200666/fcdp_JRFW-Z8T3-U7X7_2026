
/**
 * @file cb_06_ptr_array.c
 * @brief Invertir los elementos de un arreglo usando aritm´etica de punteros.
 * @author Viviana Jimenez
 * @date 2026-09-11
*/
#include <stdio.h>
void array_inverso(int *array,int size){
    int array2[size];
    int x=0;
    for(int i=0; i<size/2; i++){
       x= *(array+i);//obtiene el valor de esa posicion 
       *(array2+i)=*(array + size-1-i);       
       *(array2 + size-1-i)=x;
    }
    if (size%2!=0){
        *(array2+ size/2)=*(array+ size/2);
    }
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", *(array2+i));

        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
    
}

int main(){
    int array[7]={1,2,3,4,5,6,7};
    printf("Array estatico");
    int size= sizeof(array)/sizeof(array[0]);
    printf("[");
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
    printf("]");
    array_inverso(array, size);
    return 0;
}


