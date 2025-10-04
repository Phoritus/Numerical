#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x/3) + pow(x, 2);
}

double backwardDiffSecond(double x, double h) {
  return (2*f(x) - 5*f(x - h) + 4*f(x - 2*h) - f(x - 3*h)) / (h * h);
}

double exactSecondDerivative(double x) {
    return (2/9.0)*exp(x/3) + 2;
}

int main() {
  cout << backwardDiffSecond(-2.5, 0.1) << endl;
  cout << exactSecondDerivative(-2.5) << endl;
  cout << abs(backwardDiffSecond(-2.5, 0.1) - exactSecondDerivative(-2.5)) << endl;
  return 0;
}