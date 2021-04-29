 #include <stdio.h>

#include <conio.h> 

typedef struct Hijo{
    char *nombre;
    char *apellido;
    float edad;

}Hijo;


// Una persona con nombre , apellido y edad.
// La persona tiene otras 2 estructuras persona dentro de si misma representando a sus hijos
typedef struct Persona{
    char *nombre;
    char *apellido;
    float edad;

    Persona hijo_1 = NULL;
    Persona hijo_2 = NULL;


}PersonaA;

// No me toma la existencia de Persona , por lo que pense que simplemente se puede almacenar otro tipo de estructura a la persona, en este caso intente con "Hijo"

typedef struct Persona{
    char *nombre;
    char *apellido;
    float edad;

    Hijo hijo_1 = NULL;
    Hijo hijo_2 = NULL;


}PersonaB;



/*
Con lo visto hasta el momento, es un problema no poder trabajar tranquilamente con los Char, ya que estos son arrays que funcionan con punteros, tampoco puedo utilizar
apropiadamente la modulacion al momento de instanciar las diferentes estructuras.
*/