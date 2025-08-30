#include <iostream>
using namespace std;

int main() {
    double A[3][3] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };

    double X[3] = {0}, Y[3] = {0}, sum;
    double L[3][3] = {0}, U[3][3] = {0};
    double B[3] = {9, 0, -4};

    // LU Decomposition
    for (int i = 0; i < 3; i++) {
        // Find L (column i)
        for (int j = 0; j < 3; j++) {
            sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = A[j][i] - sum;
        }

        // Find U (row i)
        for (int j = i; j < 3; j++) {
            sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = (A[i][j] - sum) / L[i][i];
        }
    }

    // Forward substitution (L * Y = B)
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = (B[i] - sum) / L[i][i];
    }

    // Back substitution (U * X = Y)
    for (int i = 2; i >= 0; i--) {
        sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }

    for (int i = 0; i < 3; i++) {
        cout << X[i] << endl;
    }
}
