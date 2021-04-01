#include <stdio.h>

int main(){
    int entero1 ;
    int entero2 ;
    int entero3 ;
    printf("Ingrese un numero entero: \n");
    scanf("%d",&entero1);
    scanf("%d",&entero2);
    scanf("%d",&entero3);

    printf("El promedio es %d", ((entero1+entero2+entero3)/3));


    return 0;
};