#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x,4) - 13;
}

double fp_method(double xL, double xR, double tolerance) {
	
    double x1,error;
    x1 = (xL * f(xR) - xR * f(xL)) / (f(xR) - f(xL));
    if (f(x1) * f(xL) < 0) {
        xR = x1;
    } else if (f(x1) * f(xR) < 0) {
        xL = x1;
    }

    do {
        x1 = (xL * f(xR) - xR * f(xL)) / (f(xR) - f(xL));

        if (f(x1) * f(xL) < 0) {
            error = abs(x1 - xR);
            xR = x1;
        } else if (f(x1) * f(xR) < 0) {
            error = abs(x1 - xL);
            xL = x1;
        }
    } while (error > tolerance);

    return x1;
}

int main(int argc, char *argv[]) {
    double result = fp_method(1.5, 2, 1e-6);
    cout << result;
}
