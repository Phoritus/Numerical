#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 7) + (2 * pow(x, 3)) - 1;
}

double compositeSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }

    return (h / 3) * integral;
}

int main() {
    double a = -1.0; double b = 2; int n = 6;
    cout << "Integral from " << a << " to " << b << " is approximately: " << compositeSimpson(a, b, n) << endl;
}