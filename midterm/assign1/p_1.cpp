#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return 43 * x - 180;
}

int main(int argc, char *argv[]) {
    double y_start,z_end, y;
    for (int x = 0; x < 11; x++) {
        y = f(x);

        if (x > 0) {
            double prev_y = f(x-1);
            if (prev_y * y <= 0) {
                y_start = x - 1;
                z_end = x;
                break;
            }
        }
    }

    double best_x = y_start;
    double error_accept = 1e-6;

    for (double x = y_start; x <= z_end; x += 0.0000001) {
        y = f(x);
        if (abs(y) < error_accept) {
            best_x = x;
            break;
        }
    }
    cout << fixed << setprecision(6) << best_x;

}
