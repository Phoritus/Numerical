#include <iostream>
#include <vector>
using namespace std;

double divided_difference(const vector<pair<double, double>>& pts, int i, int j) {
    if (i == j) return pts[i].second;
    return (divided_difference(pts, i + 1, j) - divided_difference(pts, i, j - 1)) / (pts[j].first - pts[i].first);
}

double newton_interpolate(const vector<pair<double, double>>& pts, double x, int n, int k = 0) {
    if (k >= n) return 0.0;
    double term = divided_difference(pts, 0, k);
    for (int m = 0; m < k; m++) {
        term *= (x - pts[m].first);
    }
    return term + newton_interpolate(pts, x, n, k + 1);
}

int main() {
    vector<pair<double, double>> all_pts = {{0, 9.81}, {20000, 9.7487}, {40000, 9.6879}, {60000, 9.6879}, {80000, 9.5682}};
    
    vector<pair<double, double>> linear_pts = {all_pts[0], all_pts[4]};
    cout << newton_interpolate(linear_pts, 42235, 2) << endl;
    
    vector<pair<double, double>> quad_pts = {all_pts[0], all_pts[2], all_pts[4]};
    cout << newton_interpolate(quad_pts, 42235, 3) << endl;
    
    cout << newton_interpolate(all_pts, 42235, 5) << endl;    
    
    return 0;
}