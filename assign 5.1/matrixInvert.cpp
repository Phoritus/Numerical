#include <iostream>
using namespace std;

int main(){

    double A[3][3] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };
    double I[3][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
    double B[3] = {9, 0, -4};
    double factor;
    double X[3] = {0, 0, 0};

    for (int j = 0;j < 2; j++) {
        for (int i = j + 1; i < 3; i++) {
            factor = A[i][j] / A[j][j];
            for (int k = 0; k < 3; k++) {
                A[i][k] -= factor * A[j][k];
                I[i][k] -= factor * I[j][k];
            }
        }
    }
    
    for (int i = 2; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            factor = A[j][i] / A[i][i];
            for (int k = 0; k < 3; k++) {
                A[j][k] -= factor * A[i][k];
                I[j][k] -= factor * I[i][k];
            }
        }   
    }

    for (int i = 0; i < 3; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < 3; j++) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            X[i] += I[i][j]*B[j];
        }
        cout << X[i] << endl;
    }
    return 0;
}
