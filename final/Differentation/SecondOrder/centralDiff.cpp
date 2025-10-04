#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x/3) + pow(x, 2);
}

double centralDiffSecond(double x, double h) {
  return (-f(x + 2*h) + 16*f(x + h) - 30*f(x) + 16*f(x - h) - f(x - 2*h)) / (12 * h * h);
}

double exactSecondDerivative(double x) {
    return (2/9.0)*exp(x/3) + 2;
}

int main() {
  cout << centralDiffSecond(-2.5, 0.1) << endl;
  cout << exactSecondDerivative(-2.5) << endl;
  cout << abs(centralDiffSecond(-2.5, 0.1) - exactSecondDerivative(-2.5)) << endl;
  return 0;
}