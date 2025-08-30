#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x,2) - 7;
}

double df(double x) {
    return 2*x;
}

double newTonRaphson(double x, double error) {
    double xi,current_error;
    do {
        xi = x - (f(x) / df(x));
        cout << "X[i+1]: " << xi << endl;

        current_error = fabs(xi - x);
        cout << "current_error: " << current_error << endl;

        x = xi;
        cout << "X: " << x << endl;
        cout << "--------------------" << endl;
    } while (current_error > error);

    return x;
}

int main(int argc, char *argv[]) {
    cout << newTonRaphson(2, 1e-6);

    return 0;

}
