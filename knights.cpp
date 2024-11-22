#include <iostream>
using namespace std;

// Problema: Recorrido del caballo (Knight's Tour) en un tablero de N x N

// Tamaño del tablero
#define N 8

// Función para verificar si el movimiento es seguro o no
int isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Función para resolver el problema del caballo utilizando backtracking
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]) {
    int k, next_x, next_y;
    if (movei == N * N) // Si el caballo ha visitado todos los bloques
        return true;

    // Intenta todos los movimientos desde la posición actual x, y
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == true)
                return true;
            else
                sol[next_x][next_y] = -1; // backtracking
        }
    }
    return false;
}

// Función para imprimir la solución
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << sol[x][y] << " ";
        cout << endl;
    }
}

// Función para inicializar el tablero y resolver el problema
bool solveKT() {
    int sol[N][N];

    // Inicializa la solución del tablero con -1
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Posibles movimientos del caballo en x y y
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Inicializa la posición inicial del caballo
    sol[0][0] = 0;

    // Llama a la función recursiva para resolver el problema
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false) {
        cout << "No se encontró solución para el recorrido del caballo" << endl;
        return false;
    } else
        // Imprime la solución
        printSolution(sol);

    return true;
}

// Punto de entrada del programa
int main() {
    solveKT();
    return 0;
}
