#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

vector<double> gaussianElimination(vector<vector<double>> A, vector<double> rhs) {
    int n = rhs.size();
    for (int k = 0; k < n - 1; k++) {
        
        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            rhs[i] -= factor * rhs[k];
        }
    }
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = rhs[i];
        for (int j = i + 1; j < n; j++) {
            sum -= A[i][j] * x[j];
        }
        
        x[i] = sum / A[i][i];
    }
    return x;
}

int main() {
    vector<double> x = {10, 15, 20, 30, 40, 50, 60, 70, 80};
    vector<double> y = {5, 9, 15, 19, 22, 30, 35, 38, 43};
    int n = x.size();

    double sum_x = 0, sum_x2 = 0, sum_y = 0, sum_xy = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_x2 += x[i] * x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }
    
    vector<vector<double>> A = {{n, sum_x}, {sum_x, sum_x2}};
    vector<double> b = {sum_y, sum_xy};

    vector<double> coefficients = gaussianElimination(A, b);
    double a0 = coefficients[0];
    double a1 = coefficients[1];

    cout << "a0 = " << a0 << endl;
    cout << "a1 = " << a1 << endl;

    double x_val = 65;
    double f_x = a0 + a1 * x_val;
    cout << "f(" << x_val << ") = " << f_x << endl;

    return 0;
}