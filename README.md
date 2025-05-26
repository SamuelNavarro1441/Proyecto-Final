<h2><b>Integrantes:</b></h2><br>
<b>
Samuel Estuardo Navarro Sandoval<br>
Mefi Alexander Minchez Orozco<br>
Moisés Isaac Bautista Sevilla<br>
Luis Adelmo Miranda Navarro<br><br>
</b>
<b>Descripcion:</b>
Este proyecto es un gestor de estudiantes en C++ que permite almacenar, consultar, modificar y eliminar estudiantes en un archivo de texto. Cada estudiante tiene un ID, un nombre y un promedio, todo estu fue utilizando estructuras. El programa usa un menu interactivo en consola que permiten el manejo de diferentes funciones en base a lo que el usuario necesite.

<h3><b>Librerias Usadas</b></h3><br>

```
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
```
<b>#include ```<iostream>```</b><br>
Permite usar la entrada y salida estandar en consola, como cout y cin.

<b>#include ```<fstream>```</b><br>
Permite trabajar con archivos, por ejemplo para leer y escribir en archivos de texto usando ifstream, ofstream y fstream.

<b>#include ```<limits>```</b><br>
Permite acceder a los limites numericos de los tipos de datos.
En este programa se usa para limpiar el buffer de entrada, esto hace que se ignoren todos los caracteres hasta el siguiente salto de linea, evitando errores cuando el usuario ingresa datos incorrectos.

<b>#include ```<cstdlib>```</b><br>
Permite usar funciones de la libreria estandar como exit(), que se usa para terminar el programa en caso de error grave.

<h3><b>Estructura</b></h3><br>
El programa solicitaba trabajar los datos con estructuras, la declaracion de los campos fue la siguiente:

```
struct Estudiante
{
    int id;    
    string nombre;    
    double promedio;
};
```

id: identificador unico y consecutivo para cada estudiante.<br>
nombre: nombre completo del estudiante.<br>
promedio: promedio del estudiante (de 0.0 a 10.0)<br>

<h3><b>Funciones principales</b></h3>

<b>menu()</b><br>
Muestra el menu principal y permite elegir entre las opciones disponibles.<br>
Valida que la opcion sea un numero entre 1 y 5.<br>

Ejemplo de uso:

```
    cout << "\n\t\tMENU" << endl;
    cout << "1. Almacenar Estudiante" << endl;
    cout << "2. Consultar Estudiante" << endl;
    cout << "3. Modificar Estudiante" << endl;
    cout << "4. Eliminar Estudiante" << endl;
    cout << "5. Calcular Promedio General" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
    getline(cin, entrada);
```

<b>almacenar()</b><br>

Permite agregar uno o varios estudiantes.<br>
El ID se asigna automaticamente y es consecutivo.<br>
El nombre se ingresa completo.<br>
El promedio se valida para que este entre 0.0 y 10.0.<br>
Los estudiantes se ordenan de mayor a menor promedio antes de guardarse en el archivo.<br>


<b>consultar()</b><br>

Permite consultar todos los estudiantes o uno especifico por ID.<br>
Si se elige "todos", muestra la lista completa.<br>
Si se elige "por ID", pide el ID y muestra los datos si existe.<br>

<b>modificar()</b><br>

Permite modificar el nombre, el promedio o ambos de un estudiante por ID.<br>
Pide el ID del estudiante a modificar.<br>
Pregunta que campo(s) desea modificar.<br>
Valida el nuevo promedio igual que en almacenar.<br>
Actualiza el archivo usando un archivo temporal.<br>

<b>eliminar()</b><br>

Permite eliminar un estudiante por ID.<br>
Pide el ID a eliminar.<br>
Copia todos los estudiantes menos el eliminado a un archivo temporal.<br>
Reemplaza el archivo original por el temporal.<br>

<b>promedio()</b><br>

Permite calcular el promedio general en base a la cantidad de estudiantes ingresados.<br>
Escribe el promedio general en la primera linea del archivo txt.<br>

Manejo de archivos<br>
Todos los datos se guardan en Proyecto.txt.<br>
Para modificar o eliminar, se usa un archivo temporal temp.txt y luego se reemplaza el original.<br>


Validaciones<br>

Todas las entradas numericas se validan para evitar errores y bucles infinitos.<br>
El promedio siempre debe estar entre 0.0 y 10.0.<br>
El ID siempre es un numero entero que se incrementa solo.<br>

<u>Extra</u><br>

Todo el codigo fue autoformateado por el editor de codigo.<br>






        
