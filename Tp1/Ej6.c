#include <stdio.h>

int main(){
    int numerador;
    printf("Su numero: ");
    scanf("%d",&numerador);
    int denominador = 2;
    int par= numerador%denominador;
    
    if(par == 0)
        {
            printf("Su numero es par");
        }
        else {
            printf("Su numero no es par");
        }
    return 0;
};