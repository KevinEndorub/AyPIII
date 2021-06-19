#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>





// Header--Materia-------------------------------------------------------------------------------------------------------
typedef struct Materia{
    int id;
    int nota;
    char nombre_de_materia[45];
    int cuatri;
    
}Materia;

Materia* crear_materia (char nombre_de_materia_i[],int cuatri_in);


// Header--Materias-------------------------------------------------------------------------------------------------------
typedef struct Materias{
    Materia* materia;
    struct Materias* der;
    struct Materias* izq;
    

}Materias;

Materias* crear_lista_de_materias();
Materias* ingresar_materia(Materias *lista, char nombre_de_materia[], int cuatri_in);
Materias* ingresar(Materias* lista, Materias* actual);
Materias* busqueda(Materias* lista, int id);
void imprimir_materias(Materias* lista);
void imprimir_materias_estudiante(Materias* nodo);

// Header--Estudiante-------------------------------------------------------------------------------------------------------
typedef struct Estudiante {
    char nombre[25];
    char apellido[25];
    int DNI;
    int edad;
    int legajo; 
    Materias  *materias;
} Estudiante;

// Header--Estudiantes-------------------------------------------------------------------------------------------------------
typedef struct Estudiantes{
    Estudiante *estudiante;
    struct Estudiantes *siguiente;

}Estudiantes;

Estudiantes* crear_lista();

Estudiante* buscar_estudiante(Estudiantes* estudiantes, char* nombre);
Estudiantes* agregar_estudiante (Estudiantes* estudiantes, Estudiante* estudiante);
int obtenerLargoLista(Estudiantes *estudiantes);
void imprimir_estudiantes (Estudiantes* estudiantes);
Estudiantes* leer_estudiantes(Estudiantes* estudiantes);

Estudiante* crear_estudiante();
Materias* ingresar_materia_al_estudiante(Materias *lista,  Materias* materia_a_ingresar);
void agregar_materia_al_estudiante(Estudiante* estudiante, Materias* lista_de_materias, int id);
void calificar_materia(Estudiante* Estudiante,int id_materia,int nota);







//------------------------------------------------------------------------------------------------------------------------//
Estudiante* crear_estudiante(){

    Estudiante* nuevo_estudiante = malloc(sizeof(Estudiante));
    fflush(stdin);
    printf("Ingrese su Nombre: ");
    scanf("%[^\n]s",nuevo_estudiante->nombre);
    fflush(stdin);

    printf("Ingrese su apellido: ");
    scanf("%[^\n]s",nuevo_estudiante->apellido);
    fflush(stdin);
    

    printf("Ingrese su DNI: ");
    scanf("%d",&nuevo_estudiante->DNI);

    printf("Ingrese su legajo: ");
    scanf("%d",&nuevo_estudiante->legajo);

    printf("Ingrese su año de nacimiento: ");
    scanf("%d",&nuevo_estudiante->edad);
   
    
    return nuevo_estudiante;

};

Estudiantes* crear_lista(){
    Estudiantes* lista_de_ladrillos = NULL;
    return lista_de_ladrillos;
};

void imprimir_estudiante(Estudiante* estudiante_a_imprimir){
    printf("\nLegajo:%d, DNI:%d, Nombre:%s, Apellido:%s, Edad:%d\n Materias del estudiante:\n", estudiante_a_imprimir->legajo,estudiante_a_imprimir->DNI,estudiante_a_imprimir->nombre,estudiante_a_imprimir->apellido,(2021 - estudiante_a_imprimir->edad) );
    imprimir_materias_estudiante(estudiante_a_imprimir->materias);
}

Estudiante* buscar_estudiante (Estudiantes* estudiantes, char* nombre){
  
    Estudiantes *cursor = estudiantes;
    while (cursor->siguiente != NULL &&strcmp( nombre, cursor->estudiante->nombre)  ) {
        cursor = cursor->siguiente;
    }

    if(strcmp( nombre, cursor->estudiante->nombre)){

        printf("No existe el estudiante buscado\n");
        return  NULL;
    }

    return cursor->estudiante;
};

void buscar_estudiante_por_rango_de_edad (Estudiantes* estudiantes, int minimo,int maximo){
    
    Estudiantes *cursor = estudiantes;
    while (cursor != NULL ) {
        if((2021 - cursor->estudiante->edad)>=minimo &&    (2021 - cursor->estudiante->edad)<=maximo  ){
            printf("Legajo: %d,DNI: %d,Nombre: %s,Apeliido: %s,Edad %d\n",cursor->estudiante->legajo,cursor->estudiante->DNI,cursor->estudiante->nombre,cursor->estudiante->apellido,(2020 - cursor->estudiante->edad) );
        }
        cursor = cursor->siguiente;
    }
    
};

Estudiantes* recorrer (Estudiantes* estudiantes, int x){

    int contador = 1;
    Estudiantes *cursor = estudiantes;
    while (cursor->siguiente != NULL && x != contador ) {
        cursor = cursor->siguiente;
        contador++;
    }
    return cursor;
};

int obtenerLargoLista(Estudiantes *estudiantes){
    int contador= 1;
    Estudiantes *cursor = estudiantes;
    while (cursor->siguiente != NULL) {
        cursor = cursor->siguiente;
        contador++;
    }
    return contador;
}

Estudiantes* agregar_estudiante(Estudiantes* estudiantes, Estudiante* estudiante) {

    
    Estudiantes *nodoNuevo = malloc(sizeof(Estudiantes));
    nodoNuevo->estudiante = estudiante;
    nodoNuevo->siguiente = NULL;
    if (estudiantes == NULL) {
        estudiantes = nodoNuevo;
    } else if(estudiantes->estudiante->legajo > nodoNuevo->estudiante->legajo){
        nodoNuevo->siguiente = estudiantes;
        estudiantes = nodoNuevo;
    }
    else {
        Estudiantes *cursor = estudiantes;
        Estudiantes *aux;
        while (cursor!=NULL && cursor->estudiante->legajo < nodoNuevo->estudiante->legajo) {
        aux=cursor;
        cursor = cursor->siguiente;
    }
       aux->siguiente=nodoNuevo;
       nodoNuevo->siguiente=cursor;

    }
    
    return estudiantes;
}

void agregar_materia_al_estudiante(Estudiante* estudiante, Materias* lista_de_materias, int id){

    
    
    estudiante->materias = ingresar_materia_al_estudiante(estudiante->materias,busqueda(lista_de_materias,id));
    

}

void imprimir_estudiantes (Estudiantes* estudiantes){
    printf("\n");
    int largo = obtenerLargoLista(estudiantes);

    for(int x = 1;x<=largo;x++){

        Estudiantes *elemento =recorrer(estudiantes, x);

        printf("Legajo:%d, DNI:%d, Nombre:%s, Apellido:%s, Edad:%d\n", elemento->estudiante->legajo,elemento->estudiante->DNI,elemento->estudiante->nombre,elemento->estudiante->apellido,(2020 - elemento->estudiante->edad) );

    }


};

Estudiante* crear_estudiante_automatico(int DNI,int legajo, char  nombre[25], char apellido[25],int  edad){

    Estudiante* nuevo_estudiante = malloc(sizeof(Estudiante));
   
    nuevo_estudiante->DNI = DNI;
    nuevo_estudiante->legajo = legajo;
    strcpy(nuevo_estudiante->nombre,nombre);
    strcpy(nuevo_estudiante->apellido,apellido);
    nuevo_estudiante->edad = edad;
    return nuevo_estudiante;

}

Estudiantes* leer_estudiantes(Estudiantes* listita) {
    FILE *archivo = fopen("archivo_estudiantes.txt","rb");

    Estudiante* aux;
    char nombre[25];
    char apellido[25];
    int DNI;
    int edad;
    int legajo; 

    if (archivo == NULL) {
        perror("Error de apertura del archivo");
    }
        while(feof(archivo)==0){
        fscanf(archivo,"%d %d %s %s %d",&DNI,&legajo,&nombre,&apellido,&edad);
        //Por alguna razon no hace nada si no agrego estos espacios.
        printf("  ");
        aux = crear_estudiante_automatico(DNI,legajo,nombre,apellido,edad);
        listita = agregar_estudiante(listita,aux);
        
        }

    fclose(archivo);
    return listita;
}


int caracter_to_vector(char *orig, char *delim, char *args[], int max_args);

void calificar_materia(Estudiante* Estudiante,int id_materia,int nota){

    if(nota > 0 && nota<=10){
        Materias* buffer = busqueda(Estudiante->materias,id_materia);
        if(buffer != NULL){
            buffer->materia->nota=nota;
        }else{
            printf("No tiene asignada esa materia");
        }
    
    
    }else{
        printf("Del 1 al 10");
    }
}



//------------------------------------------------------------------------------------------------------------------------//
Materia* crear_materia (char nombre_de_materia_i[],int cuatri_in ){

    Materia* nueva_materia = malloc(sizeof(Materia));

    nueva_materia->id = rand()%99999+1;
    nueva_materia-> nota= 0;
    strcpy(nueva_materia-> nombre_de_materia , nombre_de_materia_i);
    nueva_materia->cuatri = cuatri_in;
    

    return nueva_materia;
};
//------------------------------------------------------------------------------------------------------------------------//



Materias* crear_lista_de_materias(){

    Materias* lista_de_materias = NULL;
    return lista_de_materias;

};

Materias* ingresar_materia(Materias *lista,   char nombre_de_materia[], int cuatri_in){

    //Creacion de la nueva materia
    Materias* materia_nueva = malloc(sizeof(Materias));
    materia_nueva->materia = crear_materia(nombre_de_materia,cuatri_in);
    materia_nueva->der = NULL;
    materia_nueva->izq = NULL;
    lista = ingresar(lista,materia_nueva);
    return lista;

};

Materias* ingresar_materia_al_estudiante(Materias *lista,  Materias* materia_a_ingresar){

    //Creacion de la nueva materia
    Materias* materia_nueva = malloc(sizeof(Materias));
    materia_nueva->materia = materia_a_ingresar->materia;
    materia_nueva->der = NULL;
    materia_nueva->izq = NULL;
    lista = ingresar(lista,materia_nueva);
    return lista;

};


Materias* ingresar(Materias* lista, Materias* nodo_nuevo){
    // Ingreso de la nueva materia a la lista de materias
    
    if(lista == NULL){
        lista = nodo_nuevo;
    } else{
            Materias *materia_anterior, *materia_aux;
            materia_anterior = NULL;
            materia_aux = lista;
            while(materia_aux != NULL)
                {
                    materia_anterior = materia_aux;
                    if (nodo_nuevo->materia->id < materia_aux->materia->id)
                        materia_aux = materia_aux->izq;
                    else
                        materia_aux = materia_aux->der;
                    }
            if (nodo_nuevo->materia->id < materia_anterior->materia->id)
                materia_anterior->izq = nodo_nuevo;
            else
                materia_anterior->der = nodo_nuevo;
        };

    
    return lista;

}

Materias* busqueda(Materias* nodo, int id){

    if(nodo == NULL){
        return NULL;
    }else{
        if(nodo->materia->id == id){
            
            return nodo;
        }else{
            if(id < nodo->materia->id ){
                return busqueda(nodo->izq,id);
            }
            else{
                return busqueda(nodo->der,id);
            }
        }
    }
    

};



void imprimir_materias_estudiante(Materias* nodo){


    if (nodo != NULL)
    {   
        imprimir_materias_estudiante(nodo->izq);
        printf("ID: %d , Nombre:  %s  ,Cuatrimestre: %d, Nota:%d \n",nodo->materia->id,nodo->materia->nombre_de_materia,nodo->materia->cuatri,nodo->materia->nota);
        imprimir_materias_estudiante(nodo->der);
        
    }


};

void imprimir_materias(Materias* nodo){


    if (nodo != NULL)
    {   
        imprimir_materias(nodo->izq);
        printf("ID: %d , Nombre:  %s  ,Cuatrimestre: %d \n",nodo->materia->id,nodo->materia->nombre_de_materia,nodo->materia->cuatri);
        imprimir_materias(nodo->der);
        
    }


};

Materias* leer_materias(Materias* listita) {
    FILE *archivo = fopen("archivo_materias.txt","rb");
    char nombre_de_materia[45];
    int cuatri;

    if (archivo == NULL) {
        perror("Error de apertura del archivo");
    }
        while(feof(archivo)==0){
        fscanf(archivo,"%s %d",&nombre_de_materia,&cuatri);
        //Por alguna razon no hace nada si no agrego estos espacios.
        printf("  ");
        
        listita = ingresar_materia(listita,nombre_de_materia,cuatri);
        
        }

    fclose(archivo);
    return listita;
}

//-------------------------------------------------------------------------------------------------------------//


int main(){
    Estudiantes* listita;
    Materias* lista_de_materias;
    lista_de_materias = crear_lista_de_materias();
    listita = crear_lista();
    listita = leer_estudiantes(listita);
    lista_de_materias = leer_materias(lista_de_materias);
    int seleccion;
    Estudiante* ladrillo_1;
    
    do{
        if(ladrillo_1 != NULL){
        printf("\n\nAlumno actual: \nNombre:%s, Apeliido:%s\n" ,ladrillo_1->nombre,ladrillo_1->apellido);
    }
    printf("\n-------------------------------------------------------------------");
    printf("\nSeleccionar con numero de opcion:\n\n");
    
    printf("Opcion 1: Agregar estudiante\n");
    printf("Opcion 2: Imprimir estudiantes\n");
    printf("Opcion 3: Buscar estudiante\n");
    printf("Opcion 4: Anotar estudiante en materia\n");
    printf("Opcion 5: Agregar materias\n");
    printf("Opcion 6: Listar materias\n");  
    printf("Opcion 7: Calificar\n");

    printf("\nOpcion 15: Salida\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d",&seleccion);
    
        switch(seleccion){

            case 1: 
                ladrillo_1 =  crear_estudiante();
                printf("%s",ladrillo_1->nombre);
                listita = agregar_estudiante(listita,ladrillo_1);
                break;
            case 2:
                imprimir_estudiantes(listita);
                break;
            case 3:  
                printf("Quiere buscar por:\n");
                printf("1) Nombre\n");
                printf("2) Rango de edad\n");
                printf("3) Mostrar estudiante actual\n");
                scanf("%d",&seleccion);

                if(seleccion==1){
                    char nombre_aux[35];
                    printf("Ingrese el nombre del estudiante\n");
                    //scanf("%s",nombre_aux);
                    fflush(stdin);
                    scanf("%[^\n]s",nombre_aux);
                    fflush(stdin);
                    ladrillo_1 = buscar_estudiante(listita,nombre_aux);
                    break;   
                }else if (seleccion == 2){
                    int edad_minima;
                    int edad_maxima;

                    printf("Ingrese edad minima\n");
                    scanf("%d",&edad_minima);

                    printf("Ingrese edad maxima\n");
                    scanf("%d",&edad_maxima);
                    buscar_estudiante_por_rango_de_edad(listita,edad_minima,edad_maxima);
                    break;   
                }else if(seleccion==3){
                    if(ladrillo_1==NULL){
                        printf("Busque un estudiante primero\n");
                        break;
                    }
                    imprimir_estudiante(ladrillo_1);
                    break;
                }else
                        {
                        printf("Opcion invalida\n");
                        break;   
                        }   
                break;   
             
            case 4:
                if(ladrillo_1 == NULL){
                    printf("Primero seleccione un estudiante");
                    break;
                }else{
                    int id;
                    imprimir_materias(lista_de_materias);
                    printf("Ingrese el id de la materia");
                    scanf("%d",&id);
                    agregar_materia_al_estudiante(ladrillo_1,lista_de_materias,id);
                }
                    break;
            
            case 5:
                
                fflush(stdin);
                
                char nombre_materia_aux[45];     
                int cuatri; 
                printf("Ingrese el nombre de la materia\n");
                scanf("%[^\n]s",nombre_materia_aux);
                fflush(stdin);
                
                printf("Ingrese el cuatrimentre en que se cursa la materia\n");
                scanf("%d",&cuatri);

                lista_de_materias = ingresar_materia(lista_de_materias,nombre_materia_aux,cuatri);
                break;
            
            case 6:
                printf("\n");
                imprimir_materias(lista_de_materias);
                break;

            case 7:  
                imprimir_materias(ladrillo_1->materias);
                int id_aux;
                int nota;
                printf("Id de materia:\n");
                scanf("%d",&id_aux);
                printf("Califiacion:\n");
                scanf("%d",&nota);

                calificar_materia(ladrillo_1,id_aux,nota);
                break;
            
            case 15:
                break;
            default:
                printf("Eleccion invalida, seleccione una opcion correctamente:\n");
                break;

            
        }
        printf("\n\n\n");
     }while(seleccion != 15);
    


    return 0;
};
