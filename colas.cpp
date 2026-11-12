#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;
    int cantidad;

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
        cantidad = 0;
    }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;

        if (frente == nullptr) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }

        cantidad++;
        cout << "Elemento insertado correctamente.\n";
    }

    void eliminar() {
        if (frente == nullptr) {
            cout << "La cola esta vacia.\n";
            return;
        }

        Nodo* temporal = frente;

        cout << "Elemento eliminado: " << frente->dato << "\n";

        frente = frente->siguiente;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete temporal;
        cantidad--;
    }

    void mostrarFrente() {
        if (frente == nullptr) {
            cout << "La cola esta vacia.\n";
        } else {
            cout << "Primer elemento: " << frente->dato << "\n";
        }
    }

    void mostrarCola() {
        if (frente == nullptr) {
            cout << "La cola esta vacia.\n";
            return;
        }

        Nodo* actual = frente;

        cout << "Elementos de la cola: ";

        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }

        cout << "\n";
    }

    void estaVacia() {
        if (frente == nullptr) {
            cout << "La cola esta vacia.\n";
        } else {
            cout << "La cola tiene elementos.\n";
        }
    }

    void contarElementos() {
        cout << "Cantidad de elementos: " << cantidad << "\n";
    }

    ~Cola() {
        while (frente != nullptr) {
            Nodo* temporal = frente;
            frente = frente->siguiente;
            delete temporal;
        }
    }
};

int main() {
    Cola cola;
    int opcion;
    int valor;

    do {
        cout << "\n===== MENU DE COLA CON NODOS Y PUNTEROS =====\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar primer elemento\n";
        cout << "4. Mostrar toda la cola\n";
        cout << "5. Verificar si la cola esta vacia\n";
        cout << "6. Contar elementos\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor: ";
                cin >> valor;
                cola.insertar(valor);
                break;

            case 2:
                cola.eliminar();
                break;

            case 3:
                cola.mostrarFrente();
                break;

            case 4:
                cola.mostrarCola();
                break;

            case 5:
                cola.estaVacia();
                break;

            case 6:
                cola.contarElementos();
                break;

            case 7:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 7);

    return 0;
}