#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 7) + (2 * pow(x, 3)) - 1;
}

double simpson(int b, int a) {
    double h = (b - a) / 2.0;
    return (h / 3.0) * (f(a) + 4.0 * f((a + b) / 2.0) + f(b));
}

double exactIntegral(int b, int a) {
    return (pow(b, 8) / 8.0 + (2 * pow(b, 4)) / 4.0 - b) - (pow(a, 8) / 8.0 + (2 * pow(a, 4)) / 4.0 - a);
}

int main() {
    int a = -1, b = 2;
    cout << "Integral from " << a << " to " << b << " is: " << simpson(b, a) << endl;
    cout << "Exact integral from " << a << " to " << b << " is: " << exactIntegral(b, a) << endl;
    cout << "Error is: " << abs(simpson(b, a) - exactIntegral(b, a)) << endl;
    return 0;
}