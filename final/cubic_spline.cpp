#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Spline {
    vector<double> a, b, c, d, x;
};

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

void convertToGlobal(Spline& spline) {
    int n = spline.x.size() - 1;
    for (int i = 0; i < n; i++) {
        double xi = spline.x[i];
        double A = spline.a[i];
        double B = spline.b[i];
        double C = spline.c[i];
        double D = spline.d[i];
        double xi2 = xi * xi;
        double xi3 = xi2 * xi;
        spline.a[i] = D;
        spline.b[i] = C - 3 * D * xi;
        spline.c[i] = B - 2 * C * xi + 3 * D * xi2;
        spline.d[i] = A - B * xi + C * xi2 - D * xi3;
    }
}

Spline cubicSpline(const vector<double>& xs, const vector<double>& ys) {
    int n = xs.size() - 1;
    vector<double> h(n);
    for (int i = 0; i < n; i++)
        h[i] = xs[i + 1] - xs[i];
    vector<vector<double>> A(n + 1, vector<double>(n + 1, 0.0));
    vector<double> rhs(n + 1, 0.0);
    A[0][0] = 1.0;
    A[n][n] = 1.0;
    for (int i = 1; i < n; i++) {
        A[i][i - 1] = h[i - 1];
        A[i][i] = 2 * (h[i - 1] + h[i]);
        A[i][i + 1] = h[i];
        rhs[i] = 3 * ((ys[i + 1] - ys[i]) / h[i] - (ys[i] - ys[i - 1]) / h[i - 1]);
    }
    vector<double> c_second_deriv = gaussianElimination(A, rhs);
    vector<double> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        a[i] = ys[i];
        b[i] = (ys[i + 1] - ys[i]) / h[i] - h[i] * (2 * c_second_deriv[i] + c_second_deriv[i + 1]) / 3.0;
        c[i] = c_second_deriv[i];
        d[i] = (c_second_deriv[i + 1] - c_second_deriv[i]) / (3.0 * h[i]);
    }
    Spline spline;
    spline.a = a;
    spline.b = b;
    spline.c = c;
    spline.d = d;
    spline.x = xs;

    
    convertToGlobal(spline);
    return spline;
}

double evaluate(const Spline& spline, double X) {
    int n = spline.x.size() - 1;
    int i = n - 1;
    for (int j = 0; j < n; j++) {
        if (X >= spline.x[j] && X <= spline.x[j + 1]) {
            i = j;
            break;
        }
    }
    double X2 = X * X;
    double X3 = X2 * X;
    return spline.a[i] * X3 + spline.b[i] * X2 + spline.c[i] * X + spline.d[i];
}

int main() {
    vector<double> xs = {2, 4, 6, 8, 10};
    vector<double> ys = {9.5, 8, 10.5, 39.5, 72.5};
    Spline spline = cubicSpline(xs, ys);
    double X = 4.5;
    cout << "f(" << X << ") = " << evaluate(spline, X) << endl;
    return 0;
}