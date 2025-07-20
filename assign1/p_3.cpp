#include <iostream>
#include <cmath>

using namespace std;

double f(double r, double x, double n){
    return pow(r,n) - x;
}

double nth_root(double x, double n) {

    double a, b;
    for (int i = 0; i < 1000001; i++) {
        double f_val = f(i, x, n);

        if (f_val < 0) {
            a = double(i);
        } else {
            b = double(i);
        }
    }
    double fa = f(a, x, n);
    double fb = f(b, x, n);
    double c;
    do {
        c = (a + b) / 2;
        double fc = f(c, x, n);

        if (f(a, x, n) * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (abs(a - b) > 1e-6);

    return c;
}

int main(int argc, char *argv[]) {
    double result = nth_root(1265256, 12);
    cout << result;
}
