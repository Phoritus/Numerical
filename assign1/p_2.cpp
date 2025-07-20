#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
    return pow(x,4) - 13;
}

double bisection_method(double a, double b, double tolerance) {
    double fa = f(a);
    double fb = f(b);
    if ((fa * fb) > 0) {
        return 0;
    }
    double c;
    do {
        c = (a + b) / 2;
        double fc = f(c);

        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (abs(a - b) > tolerance);

    return  c;
}

int main(int argc, char *argv[]) {
    double root = bisection_method(1.5, 2, 1e-6);
    cout << root;
}
