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
		for (int j = 0; j < 4; j++) {
			double sum = 0;
						
			for (int k = 0; k < 4; k++) {
				if (k != j) sum += A[j][k] * P[k];
			}
			X[j] = (B[j] - sum) / A[j][j];		
		}
		
		maxError = 0;		
		for (int k = 0; k < 4; k++) {
			maxError = max(maxError, abs(X[k] -  P[k]) / X[k]);	
		}		
		
		for (int k = 0; k < 4; k++) {
			cout << X[k] << endl;
		}
		cout << endl;
		
		for (int k = 0; k < 4; k++) P[k] = X[k];
		iteration += 1;
		
	} while (maxError > error);
	
	cout << "Iteration: " << iteration;
}
