#include <stdio.h>
#include <stdlib.h>

/* 
    Estrucura de nodos
*/

typedef struct nodo {
    int num;
    struct nodo *siguiente_nodo; 
}nodo ;

void mostrar_lista(nodo *lista){
    nodo *auxiliar = malloc(sizeof(nodo));
    auxiliar= lista;
    int stack=0;
    while (auxiliar != NULL){
            stack++;
            printf("%d:  %d\n", stack,auxiliar->num);
            auxiliar = auxiliar->siguiente_nodo;
    }
}
nodo *agregar_nodo_ordenadamente(nodo *lista, int numero){
    nodo *aux= malloc(sizeof(nodo));
    nodo *aux2= malloc(sizeof(nodo));
    nodo *nuevo_nodo = malloc(sizeof(nodo));
    nuevo_nodo -> num = numero;
    nuevo_nodo -> siguiente_nodo = NULL;
    // si la lista no tiene nada, se introduce directamente el nuevo nodo
    if(lista == NULL){
        lista=nuevo_nodo;
    }else{
        // apartir de aca empieza el ordenamiento
        aux= lista;
        nodo *nodo_desplazado = malloc(sizeof(nodo));
        int finalizo;
        

        
        /* VISUALIZACION DE LAS TABLA
        printf("Numero a ingresar: %d\n"   , numero);
        printf("--------------Antes-----------------\n");
        mostrar_lista(lista);
        printf("--------------+-----------------\n");
    */
        //Para la primer posicion

        if(finalizo=(numero <= aux->num)){
            nuevo_nodo->siguiente_nodo = aux;
            lista = nuevo_nodo;
        }
        
        
        while(aux->siguiente_nodo != NULL && !finalizo){
            
            //si encontro un numero mas pequeño que el mio
            if(finalizo=(numero <= aux->num)){
                printf("Estoy: %d  y mi numero es: %d\n ", aux->num , numero);
                nuevo_nodo->siguiente_nodo= aux->siguiente_nodo;
                aux->siguiente_nodo = nuevo_nodo;
                printf("Estoy en : %d \n ", aux->num );
            }
            if(finalizo=numero <= aux->siguiente_nodo->num){
                nuevo_nodo->siguiente_nodo=aux->siguiente_nodo;
                aux->siguiente_nodo= nuevo_nodo;
            }
            aux = aux->siguiente_nodo;
        }
        // Para cuando tiene que cambiar la anteultima posicion
        

        //Para agregar en el ultimo si este es mas grande que los demas
        if(numero > aux->num && !finalizo){
            aux->siguiente_nodo=nuevo_nodo;
        }
        /* VISUALIZACION DE LAS TABLA
        printf("--------------Despues-----------------\n");
        mostrar_lista(lista);
        printf("--------------+-----------------\n");
        */
    }
    return lista;
}


nodo *crear_lista(){
    nodo *lista = malloc(sizeof(nodo));
    lista = NULL;
    return lista;
}



//el orden sera de Menor a Mayor
int main(){
    nodo *lista = crear_lista();

    lista = agregar_nodo_ordenadamente(lista,3);
    lista = agregar_nodo_ordenadamente(lista,2);
    lista = agregar_nodo_ordenadamente(lista,1);
    lista = agregar_nodo_ordenadamente(lista,5);
    lista = agregar_nodo_ordenadamente(lista,8);
    lista = agregar_nodo_ordenadamente(lista,2);
    lista = agregar_nodo_ordenadamente(lista,22);
    lista = agregar_nodo_ordenadamente(lista,25);
    lista = agregar_nodo_ordenadamente(lista,21);
    lista = agregar_nodo_ordenadamente(lista,4);
    lista = agregar_nodo_ordenadamente(lista,31);
    lista = agregar_nodo_ordenadamente(lista,34);


   

    printf("---------------------------------------------\n");
    mostrar_lista(lista);

    


    return 1;
}