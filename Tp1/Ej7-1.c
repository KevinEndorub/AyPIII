#include <stdio.h>
#include <stdlib.h>

int main(){
    char frase_0[30] = "Hoy moriremos todos \n";
    char frase_1[30] = "Facultad de derechos\n";
    char frase_2[30] = "Faculta de indu\n";
    
    int ingresado;
    int salida = 1;
    while(salida)
    {
        printf("Ingrese su opcion del 1 al 4\n");
        printf("1-Opcion 1:\n");
        printf("2-Opcion 2:\n");
        printf("3-Opcion 3:\n");
        printf("4-Salir:\n");
        scanf("%d",&ingresado);

        if(ingresado == 1)
        {
            printf("%s",frase_0);
        }
        else if(ingresado == 2)
        {
            printf("%s",frase_1);
        }
        else if(ingresado == 3)
        {
            printf("%s",frase_2);
        }
        else
        {
            salida = 0;
        }
        

  
    
    }

    return 0;
};