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
    Vector3d X,X1;
    
    if (detA != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0;j < 3; j++) {
                X1(j) = A(j, i);  // Replace column i with vector B
                A(j, i) = B(j);
            }
            
            X(i) = A.determinant() / detA;  // Cramer's rule
            for (int j = 0; j < 3; j++) {
                A(j, i) = X1(j);  // Restore original column
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
    	cout << X(i) << endl;
	}
    
    return 0;
}

