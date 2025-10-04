#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return exp(x);
}

double backwardDifference(double x, double h) {
  return (f(x) - f(x - h)) / h;
}

double exactFirstDerivative(double x) {
    return exp(x);
}

int main() {
  cout << backwardDifference(2, 0.25) << endl;
  cout << exactFirstDerivative(2) << endl;
  cout << abs(backwardDifference(2, 0.25) - exactFirstDerivative(2)) << endl;
  return 0;
}