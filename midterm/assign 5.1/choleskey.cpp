#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Define symmetric positive definite matrix A
    double A[3][3] = {
        {4, 2, 1},
        {2, 3, 0.5},
        {1, 0.5, 2}
    };
    double B[3] = {7, 5.5, 3.5};

    // Define L matrix (lower triangular)
    double L[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Cholesky decomposition: A = L * L^T
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                // Diagonal elements
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[i][k];
                }
                L[i][j] = sqrt(A[i][i] - sum);
            } else {
                // Lower triangular elements
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    // Forward substitution: L * Y = B
    double Y[3] = {0, 0, 0};
    Y[0] = B[0] / L[0][0];

    for (int i = 1; i < 3; i++) {
        Y[i] = B[i];
        for (int k = 0; k < i; k++) {
            Y[i] -= L[i][k] * Y[k];
        }
        Y[i] /= L[i][i];
    }

    // Backward substitution: L^T * X = Y
    double X[3] = {0, 0, 0};
    X[2] = Y[2] / L[2][2];

    for (int i = 1; i >= 0; i--) {
        X[i] = Y[i];
        for (int k = i + 1; k < 3; k++) {
            X[i] -= L[k][i] * X[k];  // L^T[i][k] = L[k][i]
        }
        X[i] /= L[i][i];
    }

    // Display results
    for (int i = 0; i < 3; i++) {
        cout << "X[" << i << "] = " << X[i] << endl;
    }

    return 0;
}
