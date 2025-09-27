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
  int degree = 2;
  vector<double> sum_x(2 * degree + 1, 0.0);
  vector<double> sum_xy(degree + 1, 0.0);
  
  for (int i = 0; i < n; i++) {
    double x_pow = 1.0;
    for (int j = 0; j <= 2 * degree; j++) {
      sum_x[j] += x_pow;
      if (j <= degree) {
        sum_xy[j] += x_pow * y[i];
      }
      x_pow *= x[i];
    }
  }
  vector<vector<double>> A(degree + 1, vector<double>(degree + 1, 0.0));
  for (int i = 0; i <= degree; i++) {
    for (int j = 0; j <= degree; j++) {
      A[i][j] = sum_x[i + j];
    }
  }
  
  vector<double> b(degree + 1, 0.0);
  for (int i = 0; i <= degree; i++) {
    b[i] = sum_xy[i];
  }
  
  vector<double> coeffs = gaussianElimination(A, b);
  for (int i = 0; i < coeffs.size(); i++) {
    cout << "a[" << i << "] = " << coeffs[i] << endl;
  }

  double x_val = 65;
  double f_x = 0.0;
  double x_pow = 1.0;
  for (int i = 0; i <= degree; i++) {
    f_x += coeffs[i] * x_pow;
    x_pow *= x_val;
  }
  cout << "f(" << x_val << ") = " << f_x << endl;
  return 0;
}