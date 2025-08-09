#include <iostream>
using namespace std;

int main() {
    // Define matrix A
    double A[3][3] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };
    double B[3] = {9, 0, -4};

    // Define L and U matrices
    double L[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    double U[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Set U first row to A first row
    for (int j = 0; j < 3; j++) {
        U[0][j] = A[0][j];
    }

    // Set L first col to A first col divided by U[0][0]
    for (int i = 1; i < 3; i++) {
        L[i][0] = A[i][0] / U[0][0];
    }

    // Find remaining values for L and U
    for (int i = 1; i < 3; i++) {

        // Caculate U
        for (int j = i; j < 3; j++) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        // Calculate L
        for (int k = i + 1; k < 3; k++) {
            L[k][i] = A[k][i];
            for (int j = 0; j < i; j++) {
                L[k][i] -= L[k][j] * U[j][i];
            }
            L[k][i] /= U[i][i];
        }
    }

    double Y[3] = {0, 0, 0};
    Y[0] = B[0] / L[0][0];

    for (int i = 1; i < 3; i++) {
        Y[i] = B[i];
        for (int k = 0; k < i; k++) {
            Y[i] -= L[i][k] * Y[k];
        }

        Y[i] /= L[i][i];
    }

    double X[3] = {0, 0, 0};
    X[2] = Y[2] / U[2][2];

    for (int i = 1; i >= 0; i--) {
        X[i] = Y[i];
        for (int k = i + 1; k < 3; k++) {
            X[i] -= U[i][k] * X[k];
        }

        X[i] /= U[i][i];
    }

    for (int i = 0; i < 3; i++) {
        cout << "X[" << i << "] = " << X[i] << endl;
    }

    return 0;
}