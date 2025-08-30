#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x,2) - 7;
}

double secantMethod(double x,double x_1, double error) {
    double xi,current_error;  
    do {
        xi = x - ((f(x) * (x_1 - x)) / (f(x_1) - f(x)));
        cout << "X[i+1]: " << xi << endl;

        current_error = fabs(xi - x);
        cout << "current_error: " << current_error << endl;

        x_1 = x;
        x = xi;
        cout << "X: " << x << " X_1: " << x_1 << endl;
        cout << "--------------------" << endl;
    } while (current_error > error);

    return x;
}

int main(int argc, char *argv[]) {
    secantMethod(2, 1, 1e-6);

    return 0;

}
