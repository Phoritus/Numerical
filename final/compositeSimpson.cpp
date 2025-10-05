#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 7) + (2 * pow(x, 3)) - 1;
}

double compositeSimpson(double a, double b, int n) {
    double h = (b - a) / (2 * n);
    double integral = f(a) + f(b);

    for (int i = 1; i < 2 * n; i++) {
        double x = a + i * h;
        integral += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }

    return (h / 3) * integral;
}


double exactIntegral(double a, double b) {
    return (pow(b, 8) / 8.0 + (2 * pow(b, 4)) / 4.0 - b) - (pow(a, 8) / 8.0 + (2 * pow(a, 4)) / 4.0 - a);
}

int main() {
    double a = -1.0; double b = 2; int n = 12;
    cout << "Integral from " << a << " to " << b << " is approximately: " << compositeSimpson(a, b, n) << endl;
    cout << "Exact integral from " << a << " to " << b << " is: " << exactIntegral(a, b) << endl;
    cout << "Error is: " << abs(compositeSimpson(a, b, n) - exactIntegral(a, b)) << endl;
}