#include <iostream>
#include <cstring>
using namespace std;

double determinant(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    double A[3][3] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };
    double Aold[3][3];
    double B[3] = {9, 0, -4};
    double detA = determinant(A);
    double X[3];
    memcpy(Aold, A, sizeof A);

    if (detA != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[j][i] = B[j];
            }
            X[i] = determinant(A) / detA;
            memcpy(A, Aold, sizeof A);
        }
    }

    printf("x1 = %.4f\nx2 = %.4f\nx3 = %.4f",X[0],X[1],X[2]);
    return 0;
}