/******************************************************************************
//actividad 8
Nombre: Kaleb Alejandro Falcon Marquez
Fecha: 17/04/2024
Programa: Suma de un vector
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion: Un programa que mediante un vector aplica algoritmos de busqueda
y ordenamiento
*******************************************************************************/
#include <iostream>
#include <random>
#include <vector>
using namespace std;

vector<int> Valores;
int limiteV;
int opcion;
int valor;

void ingresar_TAM() {
    cout << "Ingrese el tamaño de su vector: ";
    cin >> limiteV;
}

void ingreso_valor() {
    cout << "\n\t\t¿Cómo deseas ingresar los datos?" << endl;
    cout << "\t1. Manual." << endl;
    cout << "\t2. Aleatorio." << endl;

    cout << "\n\tIngrese la opción deseada: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "¿Cuántos valores deseas ingresar?: ";
            for (int i = 0; i < limiteV; i++) {
                cin >> valor;
                Valores.push_back(valor);
            }
            break;

        case 2: {
            random_device rd; // obtener un generador de números aleatorios
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 200); // rango ajustable según necesidad
            for (int i = 0; i < limiteV; i++) {
                Valores.push_back(dis(gen));
            }
            break;
        }
        default:
            cout << "Opción no válida." << endl;
    }
}

void mostrar_valor() {
    for (size_t i = 0; i < Valores.size(); i++) {
        cout << "Índice: " << i+1 << " Valor: " << Valores[i] << endl;
    }
}

void suma_vector() {
    int suma = 0;
    for (int valor : Valores) {
        suma += valor;
    }
    cout << "La suma de los datos tiene como total: " << suma << endl;
}

void editar() {
    int indice;

    mostrar_valor();

    cout << "Ingrese el índice del elemento a editar: ";
    cin >> indice;

    if (indice < 0 || indice > limiteV) {
        cout << "Índice fuera de rango." << endl;
    } else {
        int nuevo_valor;
        cout << "Ingrese el nuevo valor: ";
        cin >> nuevo_valor;
        Valores[indice - 1] = nuevo_valor;
        cout << "Elemento editado correctamente." << endl;
    }
}

void borrar_seleccion() {
    int indiceB;

    mostrar_valor();

    cout << "Ingrese el índice del elemento a borrar: ";
    cin >> indiceB;

    if (indiceB >= 1 && indiceB <= Valores.size()) {
        Valores.erase(Valores.begin() + indiceB - 1);
        cout << "Se ha borrado el elemento." << endl;
    } else {
        cout << "Índice fuera de rango." << endl;
    }
}

void borrar_todo() {
    Valores.clear();
    cout << "Se ha borrado el arreglo." << endl;
}

void ordenamiento_burbuja() {
    for (size_t i = 0; i < Valores.size() - 1; i++) {
        for (size_t j = 0; j < Valores.size() - i - 1; j++) {
            if (Valores[j] > Valores[j+1]) {
                swap(Valores[j], Valores[j+1]);
            }
        }
    }
    cout << "El vector ha sido ordenado utilizando el algoritmo de burbuja." << endl;
}

int particion(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = particion(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void ordenamiento_quicksort() {
    quickSort(Valores, 0, Valores.size() - 1);
    cout << "El vector ha sido ordenado utilizando el algoritmo Quicksort." << endl;
}

void Ordenamiento_busqueda() {
    cout << "\n\t\t¿Deseas ordenar o buscar datos?" << endl;
    cout << "\t1. Ordenar con burbuja." << endl;
    cout << "\t2. Ordenar con Quicksort." << endl;
    cout << "\t3. Buscar datos." << endl;

    cout << "\n\tIngrese la opción deseada: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            ordenamiento_burbuja();
            break;

        case 2:
            ordenamiento_quicksort();
            break;

        case 3:
            int valorbusqueda; //busqueda binaria
            cout << "Ingrese el valor a buscar: ";
            cin >> valorbusqueda;
    
            int mitad_baja = 0;
            int mitad_alta = Valores.size();
            while (mitad_baja <= mitad_alta) {
                int ubicacion = mitad_baja + (mitad_alta - mitad_baja) / 2;
                if (Valores[ubicacion] == valorbusqueda) {
                    cout << "El valor " << valorbusqueda << " se encuentra en el indice " << ubicacion + 1 << endl;
                    return;
                } else if (Valores[ubicacion] < valorbusqueda) {
                    mitad_baja = ubicacion + 1;
                } else {
                    mitad_alta = ubicacion - 1;
                }
            }
            cout << "El valor " << valorbusqueda << " no se encontro en el vector." << endl;
            break;
    }
}

void menu() {
    int opcion;
    cout << "\n\t1. Ingresar un valor." << endl;
    cout << "\t2. Mostrar valores." << endl;
    cout << "\t3. Mostrar la suma de los valores." << endl;
    cout << "\t4. Editar los valores." << endl;
    cout << "\t5. Borrar un valor." << endl;
    cout << "\t6. Vaciar todos los valores." << endl;
    cout << "\t7. Ordenamiento y búsqueda." << endl;
    cout << "\t8. Salir." << endl;

    cout << "\n\tIngrese la opción del método que desea usar: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            ingreso_valor();
            break;

        case 2:
            mostrar_valor();
            break;

        case 3:
            suma_vector();
            break;

        case 4:
            editar();
            break;

        case 5:
            borrar_seleccion();
            break;

        case 6:
            borrar_todo();
            break;

        case 7:
            Ordenamiento_busqueda();
            break;

        case 8:
            cout << "Saliendo..." << endl;
            return;

        default:
            cout << "Opción no válida." << endl;
            break;
    }
    menu();
}

int main() {
    cout << "\t-Bienvenido-" << endl;
    ingresar_TAM();
    if (limiteV < 1 || limiteV > 50) {
        cout << "Valores fuera del rango, ingresar nuevamente." << endl;
        ingresar_TAM();
    }
    menu();

    return 0;
}
