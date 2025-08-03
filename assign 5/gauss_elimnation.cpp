#include <iostream>
using namespace std;
int main () {
    double A[3][4] = {
        {-2, 3, 1, 9},
        {3, 4, -5, 0},
        {1, -2, 1, -4}
    };
    double factor;
    for (int j = 0;j < 2; j++) {
        for (int i = j + 1; i < 3; i++) {
            factor = A[i][j] / A[j][j];
            for (int k = 0; k < 4; k++) {
                A[i][k] = A[i][k] - factor * A[j][k];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    double x3 = A[2][3] / A[2][2];
    double x2 = (A[1][3] - (A[1][2] * x3)) / A[1][1];
    double x1 = (A[0][3] - (A[0][1] * x2) - x3) / A[0][0];

    printf("x1 = %.4f\nx2 = %.4f\nx3 = %.4f",x1,x2,x3);
}