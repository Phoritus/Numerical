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

int main() {
    int a = -1, b = 2;
    cout << "Integral from " << a << " to " << b << " is: " << simpson(b, a) << endl;
    return 0;
}