TP_FINAL_ENDO_GRILLO

Endo Kevin
Grillo Julian

Profesor: Martín Rodriguez.

Carateristicas y restricciones del proyecto:

Dar de alta y listar estudiantes.

Buscar estudiantes por nombre.

Buscar estudiantes por rango de edad.

Dar de alta y listar materias.

Anotarse en una materia.

Rendir una materia.

La navegacion por la interfaz utiliza "una sesion" por estudiante con la cual se puede interactuar, esta sesion se puede
cambiar en cualquier momento. Utilizamos esta implementacion para no pedir constantemente el nombre del estudiante
para realizar cualquier operacion.

El manejo de los estudiantes se realiza a traves de listas enlazadas. En cambio el manejo de las materias se realiza a traves de Arboles y funciones recursivas.

Se utiliza ordenamiento de datos en ambas estructuras.

El tamaño maximo de legajos es de 6 digitos. Cuando llega a los 7 digitos o mas comienzan numeros Negativos.

La prueba de ingreso de estudiantes maxima por archivo probada fue con 8484  estudiantes y no hubo ningun 
problema. Mas allá de esa cantidad, no fue testeado pero se espera una respuesta efectiva del programa.

Se leen estudiantes y materias de un archivo externo y se cargan en el sistema. Pero desde el archivo txt, no se puede cargar datos con doble valor, por ejemplo
segundos nombres,segundos apellidos, materias con muchas palabras. Ingresando manualmente desde el menu, esto no sucede.

No pudimos separar el programa en varios archivos, porque al trabajar sobre Visual studio code, siempre lanzaba errores y cuando intentamos
pasarnos a otro IDE, surgian problemas mayores por el tema de los path y los compiladores.