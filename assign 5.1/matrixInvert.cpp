#include <iostream>
using namespace std;

int main(){

    double A[3][6] = {
        {-2, 3, 1, 1, 0, 0},
        {3, 4, -5, 0, 1, 0},
        {1, -2, 1, 0, 0, 1}
    };
    double A_inverse[3][3];
    double B[3] = {9, 0, -4};
    double factor;
    double X[3] = {0, 0, 0};

    for (int j = 0; j < 3; j++) {

        double pivot = A[j][j];
        for (int k = 0; k < 6; k++) {
            A[j][k] = A[j][k] / pivot;
        }

        for (int i = 0; i < 3; i++) {
            if (i != j) {
                factor = A[i][j];
                for (int k = 0; k < 6; k++) {
                    A[i][k] = A[i][k] - factor*A[j][k];
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            A_inverse[i][j-3] = A[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            X[i] += A_inverse[i][j]*B[j];
        }
        cout << X[i] << endl;
    }
}









