#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

int grafo[MAX][MAX];    // Matriz de adyacencia
int abierto[MAX];       // Cola ABIERTO
int cerrado[MAX];       // Lista CERRADO
int padre[MAX];         // Para reconstruir camino
bool visitado[MAX];     // Para evitar repetir nodos

int frente = 0, fin = -1; // índices para la cola ABIERTO
int tamCerrado = 0;       // cantidad de nodos en CERRADO

// Agregar a ABIERTO
void encolarAbierto(int nodo) {
    if (fin < MAX - 1)
        abierto[++fin] = nodo;
}

// Quitar de ABIERTO
int desencolarAbierto() {
    if (frente <= fin)
        return abierto[frente++];
    return -1;
}

// Verifica si un nodo está en CERRADO
bool estaEnCerrado(int nodo) {
    for (int i = 0; i < tamCerrado; i++) {
        if (cerrado[i] == nodo)
            return true;
    }
    return false;
}

// Agrega nodo a CERRADO
void agregarACerrado(int nodo) {
    if (tamCerrado < MAX)
        cerrado[tamCerrado++] = nodo;
}

// Imprimir trayectoria usando el arreglo padre
void imprimirTrayectoria(int inicio, int fin) {
    if (inicio == fin) {
        cout << inicio;
    } else if (padre[fin] == -1) {
        cout << "No hay camino";
    } else {
        imprimirTrayectoria(inicio, padre[fin]);
        cout << " -> " << fin;
    }
}

// Implementación BFS al estilo del pseudocódigo
void BFS(int inicio, int objetivo, int numNodos) {
    memset(visitado, false, sizeof(visitado));
    memset(padre, -1, sizeof(padre));
    frente = 0;
    fin = -1;
    tamCerrado = 0;

    encolarAbierto(inicio);

    bool exito = false;

    while (frente <= fin && !exito) {
        int X = desencolarAbierto();

        if (!estaEnCerrado(X)) {
            agregarACerrado(X);

            if (X == objetivo) {
                exito = true;
                break;
            }

            // Expandir sucesores de X
            for (int i = 0; i < numNodos; i++) {
                if (grafo[X][i] == 1 && !visitado[i]) {
                    padre[i] = X;
                    encolarAbierto(i);
                    visitado[i] = true;
                }
            }
        }
    }
    if (exito) {
        cout << "Éxito. Camino encontrado:\n";
        imprimirTrayectoria(inicio, objetivo);
        cout << endl;
    } else {
        cout << "Fracaso. No se alcanzó el estado final.\n";
    }
}

int main() {
    int numNodos = 6;
    // Inicializar grafo (matriz de adyacencia)
    memset(grafo, 0, sizeof(grafo));
    grafo[0][1] = grafo[1][0] = 1;
    grafo[0][2] = grafo[2][0] = 1;
    grafo[1][3] = grafo[3][1] = 1;
    grafo[2][3] = grafo[3][2] = 1;
    grafo[3][4] = grafo[4][3] = 1;
    grafo[4][5] = grafo[5][4] = 1;
    int inicio = 0;
    int objetivo = 4;
    BFS(inicio, objetivo, numNodos);
    return 0;
}