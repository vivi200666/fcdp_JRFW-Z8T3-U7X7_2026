/**
 * @file cb_05_cadena_de_caracteres_con_ptr.c
 * @brief Declare una cadena de caracteres y escriba un programa que recorra la cadena
usando un puntero, imprimiendo cada carácter y su dirección de memoria.
 * @author Viviana Jimenez
 * @date 2026-09-25
*/
#include <stdio.h>
void print_char(char *ptr_text){
    while(*ptr_text!='\0'){
        printf(" Caracter: %c , Direccion de memoria: (%p)", *ptr_text, (void *)ptr_text);
        ptr_text++;
    }

}
int main(){
    char message[]="viviana";
    print_char(message);
    return 0;
}