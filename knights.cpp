#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si el movimiento es seguro o no
bool validarMovimiento(int fila, int columna, vector<vector<int>>& tablero, int N) {
    return (fila >= 0 && fila < N && columna >= 0 && columna < N && tablero[fila][columna] == -1);
}

// Función para resolver el problema del caballo utilizando backtracking
bool solucionCaballo(int fila, int columna, int movimiento, vector<vector<int>>& tablero, int movFila[], int movColumna[], int N) {
    int siguienteFila, siguienteColumna;
    if (movimiento == N * N) // Si el caballo ha visitado todos los bloques
        return true;

    // Intenta todos los movimientos desde la posición actual
    for (int k = 0; k < 8; k++) {
        siguienteFila = fila + movFila[k];
        siguienteColumna = columna + movColumna[k];
        if (validarMovimiento(siguienteFila, siguienteColumna, tablero, N)) {
            tablero[siguienteFila][siguienteColumna] = movimiento;
            if (solucionCaballo(siguienteFila, siguienteColumna, movimiento + 1, tablero, movFila, movColumna, N))
                return true;
            else
                tablero[siguienteFila][siguienteColumna] = -1; // backtracking
        }
    }
    return false;
}

// Función para imprimir la solución
void imprimirSolucion(vector<vector<int>>& tablero, int N) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++)
            cout << tablero[fila][columna] << " ";
        cout << endl;
    }
}

// Función para inicializar el tablero y resolver el problema
bool resolverCaballo(int N) {
    // Crear tablero dinámico de tamaño N x N
    vector<vector<int>> tablero(N, vector<int>(N, -1));

    // Posibles movimientos del caballo en filas y columnas
    int movFila[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int movColumna[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Inicializa la posición inicial del caballo
    tablero[0][0] = 0;

    // Llama a la función recursiva para resolver el problema
    if (!solucionCaballo(0, 0, 1, tablero, movFila, movColumna, N)) {
        cout << "No se encontró solución para el recorrido del caballo" << endl;
        return false;
    } else
        // Imprime la solución
        imprimirSolucion(tablero, N);

    return true;
}

// Punto de entrada del programa
int main() {
    int N;
    cout << "Introduce el tamaño del tablero (N x N): ";
    cin >> N;

    if (N < 1) {
        cout << "El tamaño del tablero debe ser mayor que 0." << endl;
        return 1;
    }

    resolverCaballo(N);
    return 0;
}