#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double r, double x, double n) {
    return pow(r, n) - x;
}

double fp_method_nth_root(double x, double n) {
    double a, b, f_val;
    for (int i = 0; i < 1000001;i++) {
        f_val = f(i, x, n);

        if (f_val < 0) {
            a = double(i);
        } else {
            b = double(i);
            break;
        }
    }

    double c,error,fc, fa, fb;
    do {
        fa = f(a, x, n); fb = f(b, x, n);
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c, x, n);

        if (fc * fa < 0) {
            error = abs(c - b);
            b = c;
        } else if (fc * fb < 0) {
            error = abs(c - a);
            a = c;
        }

    } while (error > 1e-6);
    return c;
}

int main(int argc, char *argv[]) {
    double result = fp_method_nth_root(1265256, 12);
    cout << result;
}
