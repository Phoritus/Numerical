#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x,4) - 13;
}

double fp_method(double a, double b, double tolerance) {
    double c,error;

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) * f(a) < 0) {
            error = abs(c - b);
            b = c;
        } else if (f(c) * f(b) < 0) {
            error = abs(c - a);
            a = c;
        }
    } while (error > tolerance);

    return c;
}

int main(int argc, char *argv[]) {
    double result = fp_method(1.5, 2, 1e-6);
    cout << result;
}
