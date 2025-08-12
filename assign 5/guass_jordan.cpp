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
                A[i][k] -= factor * A[j][k];
            }
        }
    }
    
    for (int i = 2; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            factor = A[j][i] / A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }   
    }

    for (int i = 0; i < 3; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < 4; j++) {
            A[i][j] /= pivot;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

}
