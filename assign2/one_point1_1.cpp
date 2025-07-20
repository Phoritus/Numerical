#include <iostream>
#include <cmath>

using namespace std;

double g(double x) {
    return (7+x)/(x+1);
}

int main(int argc, char *argv[]) {
    double error = 1e-6;
    double x1;
    double x0 = 0; // initial x;
    double relative_error;
    int iteration = 0;
    do {
        x1 = g(x0);
        relative_error = abs((x1 - x0) / x1);

        cout << "Iteration " << ++iteration << ": x = " << x1
             << ", Error: " << relative_error << endl;
        x0 = x1;

    } while (relative_error > error);
}
