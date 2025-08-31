#include <bits/stdc++.h>
using namespace std;

double dot(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) sum += a[i] * b[i];
    return sum;
}

vector<double> matVec(const vector<vector<double>>& A, const vector<double>& x) {
    int n = A.size();
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * x[j];
        }
    }
    return result;
}

int main() {
    // Matrix A
    vector<vector<double>> A = {
        { 5, 2, 0, 0 },
        { 2, 5, 2, 0 },
        { 0, 2, 5, 2 },
        { 0, 0, 2, 5 }
    };

    // Vector B
    vector<double> B = {12, 17, 14, 7};

    int n = A.size();
    vector<double> X(n, 0.0);   // initial guess
    vector<double> R(n, 0.0), D(n, 0.0);

    // R0 = A*X0 - B
    R = matVec(A, X);
    for (int i = 0; i < n; i++) R[i] -= B[i];
    // D0 = -R0
    for (int i = 0; i < n; i++) D[i] = -R[i];

    double tol = 1e-5;
    double error;
    int iteration = 0;

    do {
        // lambda = -(D^T R) / (D^T A D)
        vector<double> AD = matVec(A, D);
        double num = -dot(D, R);
        double den = dot(D, AD);
        double lambda = num / den;

        // X(k+1) = X(k) + lambdaD
        for (int i = 0; i < n; i++) X[i] += lambda * D[i];

        // R(k+1) = A*X - B
        R = matVec(A, X);
        for (int i = 0; i < n; i++) R[i] -= B[i];

        // Error = sqrt(R^T R)
        error = sqrt(dot(R, R));

        cout << "Iteration " << iteration+1 << ": ";
        for (auto val : X) cout << val << " ";
        cout << " | Error = " << error << endl;

        // alpha = (R^T A D) / (D^T A D)
        double alpha = dot(R, AD) / den;

        // D(k+1) = -R + alphaD
        for (int i = 0; i < n; i++) D[i] = -R[i] + alpha * D[i];

        iteration++;

    } while (error > tol);

    cout << "\nFinal solution after " << iteration << " iterations:\n";
    for (int i = 0; i < n; i++) cout << "x" << i+1 << " = " << X[i] << endl;
}
