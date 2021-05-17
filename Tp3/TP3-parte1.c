#include <stdio.h>
#include <stdlib.h>

/* 
    Estrucura de nodos
*/

typedef struct nodo {
    int num;
    struct nodo *siguiente_nodo; 
}nodo ;

//creacion e inicializacion de una lista de nodos
nodo *crear_lista(){
    nodo *lista = malloc(sizeof(nodo));
    lista = NULL;
    return lista;
}

// Agregar un numero a la lista de nodos
nodo *agregar_nodo(nodo *lista, int numero){
    nodo *aux;
    nodo *nuevo_nodo = malloc(sizeof(nodo));
    nuevo_nodo -> num = numero;
    nuevo_nodo -> siguiente_nodo = NULL;
    // si la lista no tiene nada, se introduce directamente el nuevo nodo
    if(lista == NULL){
        lista=nuevo_nodo;
    }else{
        aux = lista;
        while(aux->siguiente_nodo != NULL){
            aux = aux->siguiente_nodo;
        }
        aux ->siguiente_nodo = nuevo_nodo;
    }
    return lista;
}

    // Obtencion de largo de la lista

int largolista(nodo *lista){
    int largo = 0;
    while(lista != NULL){
        largo++;
        lista = lista->siguiente_nodo;
    }
    return largo;
}
    // Obtener el elemento deseado

nodo *obtener_elemento(int numero, nodo *lista){
    nodo *nodo_buscado = malloc(sizeof(nodo)) ;
    int largo = largolista(lista);
    int numeroaux = 0;
    if (largo > numero){
        while(numeroaux != numero && lista != NULL){
            nodo_buscado = lista;
            lista = lista->siguiente_nodo;
            numeroaux++;
        }
    }else{
        // si no existe, que devuelva 0
        printf("No existe dicho elemento");
        nodo_buscado ->num = 0;
    }
   
    
    return nodo_buscado;
}
// Eliminar elemento deseado
nodo *eliminar( nodo *lista,int numero){
    
    int largo = largolista(lista);
    int numeroaux = 0;
    nodo *lista_aux= lista;
    nodo *nodo_auxiliar = malloc(sizeof(nodo)); 
    if (largo > numero  && numero > 0){
        

        while(numeroaux <= numero-1){
            nodo_auxiliar = lista_aux;
            lista_aux = lista_aux -> siguiente_nodo;
            numeroaux++;}
    
           
        
        nodo_auxiliar->siguiente_nodo = lista_aux->siguiente_nodo;
    // Para el caso que quiera borrar la primera.
    if(numero == 0){
        lista = lista->siguiente_nodo; 
    }
        //printf("Numero auxiliar: %d \nSiguiente : %d \n",nodo_auxiliar->num, nodo_auxiliar->siguiente_nodo->num);
       

    }else{
        // si no existe, que devuelva 0
        printf("No existe dicho elemento a eliminar\n");
    }
   
    
    return lista;
}
//Mostrar la lista
void mostrar_lista(nodo *lista){
    nodo *auxiliar = malloc(sizeof(nodo));
    auxiliar= lista;
    while (auxiliar != NULL){
            printf("%d\n", auxiliar->num);
            auxiliar = auxiliar->siguiente_nodo;
    }
}
int main(){
    nodo *lista = crear_lista();
    lista = agregar_nodo(lista,0);
    lista = agregar_nodo(lista,1);
    lista = agregar_nodo(lista,2);
    lista = agregar_nodo(lista,3);
    lista = agregar_nodo(lista,4);
    lista = agregar_nodo(lista,5);
    printf("El largo de la lista es: %d \n",largolista(lista));
    printf("El nodo deseado tiene el numero : %d \n",obtener_elemento(3,lista)->num);
    lista = eliminar(lista,2);
    mostrar_lista(lista);

    
    


    return 1;
}