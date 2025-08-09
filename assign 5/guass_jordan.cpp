#include <iostream>
using namespace std;
int main () {
    double A[3][4] = {
        {-2, 3, 1, 9},
        {3, 4, -5, 0},
        {1, -2, 1, -4}
    };
    double factor;

    // for column
    for (int j = 0; j < 3; j++) {

        double pivot = A[j][j];
        for (int k = 0; k < 4; k++) {
            A[j][k] = A[j][k] / pivot;
        }

        // for row
        for (int i = 0; i < 3; i++) {
            if (i != j) {
                factor = A[i][j];
                for (int k = 0; k < 4; k++) {
                    A[i][k] = A[i][k] - factor * A[j][k];
                }
            }
        }


    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
