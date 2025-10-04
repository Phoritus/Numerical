#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x);
}

double forwardDifference(double x, double h) {
  return (f(x + h) - f(x)) / h;
}

double exactFirstDerivative(double x) {
    return exp(x);
}

int main() {
  cout << forwardDifference(2, 0.25) << endl;
  cout << exactFirstDerivative(2) << endl;
  cout << abs(forwardDifference(2, 0.25) - exactFirstDerivative(2)) << endl;
  return 0;
}