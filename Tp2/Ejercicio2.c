 #include <stdio.h>

#include <conio.h> 

typedef struct Perros  {
    char *nombre;
    char *raza;
    float edad;
    }Perros;

Perros set_edad(Perros perro, float edad);
Perros set_nombre_y_raza(Perros perro, char *nombre, char *raza);


int main(){
    Perros perro_1;
    perro_1 = set_edad(perro_1,20);
    perro_1 = set_nombre_y_raza(perro_1,"Juan","tonto");
    

    printf("edad: %f  nombre: %s    raza:  %s", perro_1.edad,perro_1.nombre,perro_1.raza);
    return 0;
};
Perros set_edad(Perros perro, float edad){

    perro.edad = edad;
    return perro;
 
};

Perros set_nombre_y_raza(Perros perro,char *nombre, char *raza){

    perro.nombre = nombre;
    perro.raza = raza;
    return perro;
}

/* No puedo cambiar las variables de mi estructura  mediante parametros, porque al ingresar por parametros los char,  
s
s*/