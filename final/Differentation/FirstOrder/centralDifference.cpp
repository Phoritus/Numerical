#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x);
}

double centralDifference(double x, double h) {
  return (f(x + h) - f(x - h)) / (2 * h);
}

double exactFirstDerivative(double x) {
    return exp(x);
}

int main() {
  cout << centralDifference(2, 0.25) << endl;
  cout << exactFirstDerivative(2) << endl;
  cout << abs(centralDifference(2, 0.25) - exactFirstDerivative(2)) << endl;
  return 0;
}