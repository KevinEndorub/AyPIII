#include <stdio.h>

int main(){
    int edad ;
    char nombre[100]; 

    printf ("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf ("Ingrese su edad: ");
    scanf("%d", &edad); //si es un numero pongo &
    
    printf("Su nombre es: %s \n",nombre);
    printf("Su edad es: %d", edad);

    return 0;
};