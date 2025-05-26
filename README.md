Integrantes:

Samuel Estuardo Navarro Sandoval

Mefi Alexander Minchez Orozco

Moisés Isaac Bautista Sevilla

Luis Adelmo Miranda Navarro


Descripcion:
Este proyecto es un gestor de estudiantes en C++ que permite almacenar, consultar, modificar y eliminar estudiantes en un archivo de texto. Cada estudiante tiene un ID, un nombre y un promedio. El programa usa un menu interactivo en consola.

struct Estudiante

{

    int id;
    
    string nombre;
    
    double promedio;
    
};

id: identificador unico y consecutivo para cada estudiante.

nombre: nombre completo del estudiante.

promedio: promedio del estudiante (de 0.0 a 10.0)


Funciones principales

menu()

Muestra el menu principal y permite elegir entre las opciones disponibles.

Valida que la opcion sea un numero entre 1 y 5.

Ejemplo de uso:


cout << "\n\t\tMENU" << endl;

cout << "1. Almacenar Estudiante" << endl;

cout << "2. Consultar Estudiante" << endl;

cout << "3. Modificar Estudiante" << endl;

cout << "4. Eliminar Estudiante" << endl;

cout << "5. Salir" << endl;

cout << "Opcion: ";

getline(cin, entrada);


almacenar()

Permite agregar uno o varios estudiantes.

El ID se asigna automaticamente y es consecutivo.

El nombre se ingresa completo.

El promedio se valida para que este entre 0.0 y 10.0.

Los estudiantes se ordenan de mayor a menor promedio antes de guardarse en el archivo.


consultar()

Permite consultar todos los estudiantes o uno especifico por ID.

Si se elige "todos", muestra la lista completa.

Si se elige "por ID", pide el ID y muestra los datos si existe.

modificar()

Permite modificar el nombre, el promedio o ambos de un estudiante por ID.

Pide el ID del estudiante a modificar.

Pregunta que campo(s) desea modificar.

Valida el nuevo promedio igual que en almacenar.

Actualiza el archivo usando un archivo temporal.


eliminar()

Permite eliminar un estudiante por ID.

Pide el ID a eliminar.

Copia todos los estudiantes menos el eliminado a un archivo temporal.

Reemplaza el archivo original por el temporal.

Manejo de archivos

Todos los datos se guardan en Proyecto.txt.

Para modificar o eliminar, se usa un archivo temporal temp.txt y luego se reemplaza el original.


Validaciones

Todas las entradas numericas se validan para evitar errores y bucles infinitos.

El promedio siempre debe estar entre 0.0 y 10.0.

El ID siempre es un numero entero que se incrementa solo.





        
