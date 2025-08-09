#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
using namespace std;
using namespace Eigen;

int main() {
	
    Matrix3d A;
    A << -2, 3, 1,
         3, 4, -5,
         1, -2, 1;
    
    Vector3d B(9, 0, -4);
    
    double detA = A.determinant();
    Vector3d X;
    
    if (detA != 0) {
        for (int i = 0; i < 3; i++) {
            Matrix3d A_temp = A;  // Copy original matrix
            A_temp.col(i) = B;    // Replace column i with B vector
            X(i) = A_temp.determinant() / detA;  // Cramer's rule
        }
    }
    
    for (int i = 0; i < 3; i++) {
    	cout << X(i) << endl;
	}
    
    return 0;
}
