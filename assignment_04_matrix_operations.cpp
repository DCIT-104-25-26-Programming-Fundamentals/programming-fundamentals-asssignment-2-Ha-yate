// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAXN = 10;

// -----------------------------------------------------------------------------
// Reads an M x N matrix from the user, element by element.
// -----------------------------------------------------------------------------
void readMatrix(int mat[MAXN][MAXN], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// Displays a matrix in a neat, aligned grid.
// -----------------------------------------------------------------------------
void displayMatrix(int mat[MAXN][MAXN], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose
// -----------------------------------------------------------------------------
void transposeMatrix(int mat[MAXN][MAXN], int rows, int cols, int result[MAXN][MAXN]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B — Addition
// -----------------------------------------------------------------------------
void addMatrices(int a[MAXN][MAXN], int b[MAXN][MAXN], int rows, int cols, int result[MAXN][MAXN]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C — Multiplication (A is M x N, B is N x P, result is M x P)
// -----------------------------------------------------------------------------
void multiplyMatrices(int a[MAXN][MAXN], int b[MAXN][MAXN], int m, int n, int p, int result[MAXN][MAXN]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int mat[MAXN][MAXN], result[MAXN][MAXN];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter elements of the matrix:" << endl;
        readMatrix(mat, rows, cols);

        transposeMatrix(mat, rows, cols, result);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(mat, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, cols, rows);
    }
    else if (choice == 2) {
        int rows, cols;
        int a[MAXN][MAXN], b[MAXN][MAXN], result[MAXN][MAXN];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter elements of Matrix A:" << endl;
        readMatrix(a, rows, cols);
        cout << "\nEnter elements of Matrix B:" << endl;
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, result);

        cout << "\nMatrix A:" << endl;
        displayMatrix(a, rows, cols);
        cout << "\nMatrix B:" << endl;
        displayMatrix(b, rows, cols);
        cout << "\nSum (A + B):" << endl;
        displayMatrix(result, rows, cols);
    }
    else if (choice == 3) {
        int m, n, p;
        int a[MAXN][MAXN], b[MAXN][MAXN], result[MAXN][MAXN];

        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
        cin >> n;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        cout << "\nEnter elements of Matrix A (" << m << "x" << n << "):" << endl;
        readMatrix(a, m, n);
        cout << "\nEnter elements of Matrix B (" << n << "x" << p << "):" << endl;
        readMatrix(b, n, p);

        multiplyMatrices(a, b, m, n, p, result);

        cout << "\nMatrix A:" << endl;
        displayMatrix(a, m, n);
        cout << "\nMatrix B:" << endl;
        displayMatrix(b, n, p);
        cout << "\nProduct (A x B):" << endl;
        displayMatrix(result, m, p);
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
