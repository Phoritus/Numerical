#include <iostream>
#include <vector>
using namespace std;

double linearSpline(vector<double> xs, vector<double> ys, double x) {
	int n = xs.size() - 1;
	int i = n - 1;
	
	for (int k = 0; k < n - 1; k++) {
		if (x >= xs[k] && x <= xs[k + 1]) {
			i = k; break;
		}
	}
	
	double slope = (ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i]);
	double result = ys[i] + slope * (x - xs[i]);
	
	return result;
}

int main() {
	vector<double> xs = {2, 4, 6, 8, 10};
	vector<double> ys = {9.5, 8.0, 10.5, 39.5, 72.5};
	
	double x = 4.5;
	cout << linearSpline(xs, ys, x) << endl;
}