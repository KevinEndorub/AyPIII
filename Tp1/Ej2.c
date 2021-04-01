#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamano_ingresado;
    printf ("Tamanio de la lista: ");
    scanf("%d", &tamano_ingresado);

    int arreglo[tamano_ingresado];
    printf("ingrese los numeros de a uno :");
    int contador;
    int aux;
    for (contador=0; contador<=tamano_ingresado-1; contador++ )
        {
            scanf("%d", &aux);
            arreglo[contador] = aux;
        }
        

    int cantidad_de_numeros = sizeof(arreglo)/ sizeof(arreglo[0]); // Divido la cantidad de bits máxima que utiliza para guardar en memoria con la cantidad de memoria que guarda para una sola pocision.
    
    int max = 0;
    int min = arreglo[0];
    for (contador=0; contador<=cantidad_de_numeros-1; contador++) // Pude usar tamaño_ingresado
        {
            if (arreglo[contador]<min)
            {
                min = arreglo[contador];
            }
            
            if(arreglo[contador]>max)
            {
                max = arreglo[contador];
            }
        }
    printf("El numero mas alto es: %d \n", max);
    printf("El numero mas bajo es: %d", min);
    return 0;
};