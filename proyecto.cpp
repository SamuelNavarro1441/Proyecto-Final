#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
using namespace std;

// Declaracion de funciones principales
void menu();
void almacenar();
void consultar();
void modificar();
void eliminar();
void promedio();

// Estructura para almacenar los datos de un estudiante
struct Estudiante
{
    int id;
    string nombre;
    double promedio;
} estudiante, estudiantes[100];

int main()
{
    menu();    // Inicia el menu principal
    cin.get(); // Espera a un enter para terminar la ejecucion
    return 0;
}

void menu()
{
    int opcion;
    string entrada;
    do
    {
        // Menu principal
        cout << "\n\t\tMENU" << endl;
        cout << "1. Almacenar Estudiante" << endl;
        cout << "2. Consultar Estudiante" << endl;
        cout << "3. Modificar Estudiante" << endl;
        cout << "4. Eliminar Estudiante" << endl;
        cout << "5. Calcular Promedio General" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        getline(cin, entrada);

        // Convierte la entrada a entero, si falla muestra mensaje
        try
        {
            opcion = stoi(entrada);
        }
        catch (...)
        {
            cout << "Entrada no valida. Por favor, ingrese un numero entre 1 y 6." << endl;
            continue;
        }

        if (opcion < 1 || opcion > 6)
        {
            cout << "Opcion no valida, intente de nuevo." << endl;
            continue;
        }
        switch (opcion)
        {
        case 1:
            almacenar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            promedio();
            break;
        case 6:
            cout << "\nPresione enter para terminar la ejecucion\n";
            break;
        }
    } while (opcion != 6);
}

void almacenar()
{
    int n = 0;
    char rpt;
    int ultimoID = 0;

    // Lee los estudiantes actuales del archivo (si existen)
    ifstream archivoLectura("Proyecto.txt");
    if (!archivoLectura.fail())
    {
        string linea;
        getline(archivoLectura, linea); // Salta la primera linea (promedio general)
        while (n < 100 && archivoLectura >> estudiantes[n].id)
        {
            archivoLectura >> ws;
            getline(archivoLectura, estudiantes[n].nombre, '\t');
            archivoLectura >> estudiantes[n].promedio;
            archivoLectura.ignore();
            ultimoID = estudiantes[n].id;
            n++;
        }
        archivoLectura.close();
    }

    do
    {
        estudiantes[n].id = n + 1; // ID consecutivo desde 1

        cout << "\nID asignado al estudiante: " << estudiantes[n].id << endl;

        cout << "Digite su nombre: ";
        getline(cin >> ws, estudiantes[n].nombre); // Lee el nombre correctamente

        // Validacion de promedio
        string entradaPromedio;
        double promedio;
        while (true)
        {
            cout << "Digite su promedio (0.0 - 10.0): ";
            getline(cin, entradaPromedio);
            try
            {
                promedio = stod(entradaPromedio);
                // Valida el rango del promedio
                if (promedio >= 0.0 && promedio <= 10.0)
                {
                    estudiantes[n].promedio = promedio;
                    break;
                }
                else
                {
                    cout << "El promedio debe estar entre 0.0 y 10.0." << endl;
                }
            }
            catch (...)
            {
                cout << "Entrada no valida. Ingrese un numero valido para el promedio." << endl;
            }
        }

        n++;
        ultimoID++;

        cout << "\nDesea agregar otro estudiante (S/N): ";
        cin >> rpt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while ((rpt == 'S' || rpt == 's') && n < 100);

    // Ordena los estudiantes por promedio de mayor a menor
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (estudiantes[j].promedio > estudiantes[max].promedio)
            {
                max = j;
            }
        }
        if (max != i)
        {
            Estudiante temp = estudiantes[i];
            estudiantes[i] = estudiantes[max];
            estudiantes[max] = temp;
        }
    }

    // Guarda los estudiantes ordenados en el archivo (sobrescribe)
    ofstream archivo("Proyecto.txt", ios::out);
    if (archivo.fail())
    {
        cout << "Error con el archivo";
        exit(1);
    }

    // Escribe el promedio general anterior si existia, o una linea vacia
    archivo << "Promedio general: " << endl;

    for (int i = 0; i < n; i++)
    {
        archivo << estudiantes[i].id << "\t" << estudiantes[i].nombre << "\t" << estudiantes[i].promedio << endl;
    }

    archivo.close();
    cout << "Estudiantes almacenados y ordenados por promedio correctamente." << endl;
}

void consultar()
{
    ifstream archivo("Proyecto.txt");
    if (archivo.fail())
    {
        cout << "Error con el archivo";
        return;
    }

    string linea;
    getline(archivo, linea); // Salta la primera linea (promedio general)

    int opcion;
    cout << "Que desea consultar?\n1. Todos los estudiantes\n2. Un estudiante por ID\nOpcion: ";
    // Valida que la opcion sea 1 o 2
    while (!(cin >> opcion) || (opcion != 1 && opcion != 2))
    {
        cout << "Entrada no valida. Ingrese 1 o 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opcion == 1)
    {
        bool hayDatos = false;
        // Lee todos los estudiantes del archivo
        while (archivo >> estudiante.id)
        {
            archivo >> ws; // Ignora espacios en blanco
            getline(archivo, estudiante.nombre, '\t');
            archivo >> estudiante.promedio;
            archivo.ignore();
            cout << "ID: " << estudiante.id << "\tNombre: " << estudiante.nombre << "\tPromedio: " << estudiante.promedio << endl;
            hayDatos = true;
        }
        if (!hayDatos)
            cout << "No hay estudiantes registrados." << endl;
    }
    else
    {
        int idConsultar;
        cout << "Digite el ID del estudiante a consultar: ";
        // Valida que el ID sea un numero
        while (!(cin >> idConsultar))
        {
            cout << "Entrada no valida. Ingrese un numero de ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool encontrado = false;
        // Busca el estudiante por ID
        while (archivo >> estudiante.id)
        {
            archivo >> ws;
            getline(archivo, estudiante.nombre, '\t');
            archivo >> estudiante.promedio;
            archivo.ignore();

            if (estudiante.id == idConsultar)
            {
                cout << "ID: " << estudiante.id << "\tNombre: " << estudiante.nombre << "\tPromedio: " << estudiante.promedio << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            cout << "No se encontro un estudiante con ese ID." << endl;
        }
    }
    archivo.close();
}

void modificar()
{
    char rpt;
    do
    {
        ifstream archivo("Proyecto.txt");
        ofstream temp("temp.txt");
        int id, idModificar;
        string nombre;
        double promedio;
        bool encontrado = false;

        if (archivo.fail() || temp.fail())
        {
            cout << "Error con el archivo";
            return;
        }

        string linea;
        getline(archivo, linea); // Salta la primera linea (promedio general)
        temp << linea << endl;   // Mantiene la primera linea en el archivo temporal

        cout << "Digite el ID del estudiante a modificar: ";
        // Valida que el ID sea un numero
        while (!(cin >> idModificar))
        {
            cout << "Entrada no valida. Ingrese un numero de ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int opcion;
        cout << "Que desea modificar?\n1. Nombre\n2. Promedio\n3. Ambos\nOpcion: ";
        // Valida que la opcion sea 1, 2 o 3
        while (!(cin >> opcion) || (opcion < 1 || opcion > 3))
        {
            cout << "Entrada no valida. Ingrese 1, 2 o 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Lee todos los registros y modifica el que coincide con el ID
        while (archivo >> id)
        {
            archivo >> ws;
            getline(archivo, nombre, '\t');
            archivo >> promedio;
            archivo.ignore();

            if (id == idModificar)
            {
                cout << "Edite los datos del estudiante con el ID: " << idModificar << endl;
                if (opcion == 1 || opcion == 3)
                {
                    cout << "Digite su nuevo nombre: ";
                    getline(cin >> ws, nombre);
                }
                if (opcion == 2 || opcion == 3)
                {
                    string entradaPromedio;
                    while (true)
                    {
                        cout << "Digite su nuevo promedio (0.0 - 10.0): ";
                        getline(cin, entradaPromedio);
                        try
                        {
                            double nuevoPromedio = stod(entradaPromedio);
                            // Valida el rango del promedio
                            if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0)
                            {
                                promedio = nuevoPromedio;
                                break;
                            }
                            else
                            {
                                cout << "El promedio debe estar entre 0.0 y 10.0." << endl;
                            }
                        }
                        catch (...)
                        {
                            cout << "Entrada no valida. Ingrese un numero valido para el promedio." << endl;
                        }
                    }
                }
                encontrado = true;
            }
            // Escribe el registro (modificado o no) en el archivo temporal
            temp << id << "\t" << nombre << "\t" << promedio << endl;
        }

        archivo.close();
        temp.close();

        // Reemplaza el archivo original por el temporal
        remove("Proyecto.txt");
        rename("temp.txt", "Proyecto.txt");

        if (!encontrado)
        {
            cout << "No se encontro un estudiante con ese ID." << endl;
        }
        else
        {
            cout << "Estudiante modificado correctamente." << endl;
        }

        cout << "\nDesea modificar otro estudiante? (S/N): ";
        cin >> rpt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (rpt == 'S' || rpt == 's');
}

void eliminar()
{
    ofstream temp("temp.txt");
    ifstream archivo("Proyecto.txt");
    string nombre;
    int id, idEliminar;
    double promedio;
    bool encontrado = false;

    if (archivo.fail() || temp.fail())
    {
        cout << "Error con el archivo";
        return;
    }

    string linea;
    getline(archivo, linea); // Salta la primera linea (promedio general)
    temp << linea << endl;   // Mantiene la primera linea en el archivo temporal

    cout << "Digite el ID del estudiante a eliminar: ";
    // Valida que el ID sea un numero
    while (!(cin >> idEliminar))
    {
        cout << "Entrada no valida. Ingrese un numero de ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Copia todos los estudiantes excepto el que se elimina
    while (archivo >> id)
    {
        archivo >> ws;
        getline(archivo, nombre, '\t');
        archivo >> promedio;
        archivo.ignore();

        if (id == idEliminar)
        {
            encontrado = true;
            cout << "Estudiante con ID " << idEliminar << " eliminado." << endl;
            continue;
        }
        temp << id << "\t" << nombre << "\t" << promedio << endl;
    }

    archivo.close();
    temp.close();

    // Reemplaza el archivo original por el temporal
    remove("Proyecto.txt");
    rename("temp.txt", "Proyecto.txt");

    if (!encontrado)
    {
        cout << "No se encontro un estudiante con ese ID." << endl;
    }
}

// Nueva funcion para calcular y actualizar el promedio general
void promedio()
{
    ifstream archivo("Proyecto.txt");
    if (archivo.fail())
    {
        cout << "Error con el archivo" << endl;
        return;
    }

    string linea;
    double suma = 0.0;
    int contador = 0;

    // Salta la primera linea (puede ser el promedio anterior)
    getline(archivo, linea);

    // Lee los estudiantes y suma sus promedios
    while (archivo >> estudiante.id)
    {
        archivo >> ws;
        getline(archivo, estudiante.nombre, '\t');
        archivo >> estudiante.promedio;
        archivo.ignore();
        suma += estudiante.promedio;
        contador++;
    }
    archivo.close();

    if (contador == 0)
    {
        cout << "No hay estudiantes registrados para calcular el promedio general." << endl;
        return;
    }

    double promedioGeneral = suma / contador;
    cout.precision(4);
    cout << "El promedio general de los estudiantes es: " << promedioGeneral << endl;

    // Escribe el promedio general en la primera linea del archivo
    ifstream archivoLectura("Proyecto.txt");
    ofstream archivoTemp("temp.txt");
    if (!archivoLectura.fail() && !archivoTemp.fail())
    {
        // Escribe el promedio general en la primera linea
        archivoTemp << "Promedio general: " << promedioGeneral << endl;

        // Salta la primera linea del archivo original
        getline(archivoLectura, linea);

        // Copia el resto de los estudiantes
        while (getline(archivoLectura, linea))
        {
            archivoTemp << linea << endl;
        }

        archivoLectura.close();
        archivoTemp.close();

        // Reemplaza el archivo original por el temporal
        remove("Proyecto.txt");
        rename("temp.txt", "Proyecto.txt");
    }
}