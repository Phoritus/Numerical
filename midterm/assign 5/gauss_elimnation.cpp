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
    
    double x[3];
    
    for (int i = 2; i >= 0; i--) {
    	
        x[i] = A[i][3];  // Start with the constant term
        for (int j = i + 1; j < 3; j++) {
            x[i] -= A[i][j] * x[j];  // Subtract known variables
        }
        x[i] /= A[i][i];  // Divide by coefficient
    }

    for (int i = 0; i < 3; i++) {
    	cout << x[i] << endl;
	}

}
