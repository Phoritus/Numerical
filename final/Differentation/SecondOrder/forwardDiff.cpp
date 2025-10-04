#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x/3) + pow(x, 2);
}

double forwardDiffSecond(double x, double h) {
  return (-f(x + 3 * h) + 4*f(x + 2 * h) - 5*f(x + h) + 2*(f(x))) / (h * h);
}

double exactSecondDerivative(double x) {
    return (2/9.0)*exp(x/3) + 2;
}

int main() {
  cout << forwardDiffSecond(-2.5, 0.1) << endl;
  cout << exactSecondDerivative(-2.5) << endl;
  cout << abs(forwardDiffSecond(-2.5, 0.1) - exactSecondDerivative(-2.5)) << endl;
  return 0;
}