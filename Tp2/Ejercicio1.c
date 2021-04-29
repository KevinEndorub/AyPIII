#include <stdio.h>


// defino como identidad a los perror en general
// tienen  Nombre, Raza y edad a grandes rasgos

 struct  Perros {
    char *nombre;
    char *raza;
    int edad;
    };


// no puedo asignar a la estructura los char si estos tienen un cantidad fija de espacios, por lo que puse * para que asigne los punteros de lo que le estoy asignando.
int main(){
    struct Perros perro_1;
    perro_1.nombre = "Alonso" ;
    perro_1.raza = "caniche toy" ;
    perro_1.edad = 20;
    printf("%s , %s, %d", perro_1.nombre , perro_1.raza, perro_1.edad);

    return 0;
};
