#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Spline {
	vector<double> a, b, c, x;
};

vector<double> gaussianElimination(vector<vector<double>> A, vector<double> rhs) {
	int n = rhs.size();
	for (int k = 0; k < n - 1; k++) {
		for (int i = k + 1; i < n; i++) {
			double factor = A[i][k] / A[i][i];
			for (int j = k; j < n; j++) {
				A[i][j] -= factor * A[k][j];
			}
		}
	}
	vector<double> x(n);
	
	for (int i = n - 1; i >= 0; i--) {
		double sum = rhs[i];
		for (int j = i + 1; j < n; j++) {
			sum -= A[i][j] * x[j];
		}
		x[i] = sum / A[i][i];
	}
	
	return x;
}

Spline quandraticSpline(vector<double> xs, vector<double> ys) {
	int n = xs.size() - 1;
	vector<double> h(n);
	for (int i = 0; i < n; i++) h[i] = xs[i + 1] - xs[i]; 
	
	vector<vector<double>> A(n, vector<double>(n, 0.0));
	vector<double> rhs(n, 0);
	
	A[0][0] = 1.0;
	rhs[0] = 0.0;
	
	for (int i = 1; i < n; i++) {
		A[i][i] = 2 * h[i];
		A[i][i - 1] = h[i - 1];
		rhs[i] = 2 * (((ys[i + 1]-ys[i])/h[i]) - (ys[i]-ys[i - 1])/h[i-1]);
	}
	
	vector<double> c = gaussianElimination(A, rhs);
	vector<double> a(n), b(n);
	
	for (int i = 0; i < n; i++) {
		a[i] = ys[i];
		b[i] = (ys[i+1] - ys[i]) / h[i] - c[i] * h[i];
	}
	
	Spline spline;
	spline.a = a; spline.x = xs;
	spline.b = b;
	spline.c = c; 
	
	return spline;

}

double evaluate(Spline& spline, double X) {
	int n = spline.x.size() - 1;
	int i = n - 1;
	for (int j = 0; j < n; j++) {
		if (X >= spline.x[j] && X <= spline.x[j+1]) {
			i = j; break;
		}
	}
	double dx = X - spline.x[i];
	return spline.a[i] + spline.b[i] * dx + spline.c[i] * dx * dx;
}

int main() {
	vector<double> xs = {2, 4, 6, 8, 10};
	vector<double> ys = {9.5, 8, 10.5, 39.5, 72.5};
	Spline spline = quandraticSpline(xs, ys);
	
	double x = 4.5;
	cout << evaluate(spline, x); 
	return 0;
}