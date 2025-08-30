#include <bits/stdc++.h>
using namespace std;

int main() {
	int A[4][4] = {{5, 2, 0, 0},
				   {2, 5, 2, 0},
				   {0, 2, 5, 2},
				   {0, 0, 2, 5}};
	
	double P[4] = {0};
	double X[4] = {0};
	double B[4] = {12, 17, 14, 7};
	
	double error = 0.00001;
	int iteration = 0;
	double maxError = 0;
	do {
		maxError = 0;
		for (int j = 0; j < 4; j++) {
			double sum = 0;
						
			for (int k = 0; k < 4; k++) {
				if (k != j) sum += A[j][k] * P[k];
			}
			double temp = P[j];
			X[j] = (B[j] - sum) / A[j][j];
			P[j] = X[j];
			maxError = max(maxError, abs(X[j] -  temp) / X[j]);
		
		}
			
		for (int k = 0; k < 4; k++) {
			cout << X[k] << endl;
		}
		cout << endl;
		iteration += 1;
		
	} while (maxError > error);
	
	cout << "Iteration: " << iteration;
}
