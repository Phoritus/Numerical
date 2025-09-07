#include <iostream>
#include <vector>
#include <map>
using namespace std;

double divided_difference(const vector<pair<double, double>>& pts, int i, int j, map<pair<int, int>, double>& memo) {
    pair<int, int> key = {i, j};

    if (memo.count(key)) {
        return memo[key];
    }
    
    if (i == j) {
        memo[key] = pts[i].second;
        return pts[i].second;
    }
    
    memo[key] = (divided_difference(pts, i + 1, j, memo) - divided_difference(pts, i, j - 1, memo)) / (pts[j].first - pts[i].first);
    return memo[key];
}

double newton_interpolate(const vector<pair<double, double>>& pts, double x, int n, map<pair<int, int>, double>& memo, int k = 0) {
    if (k >= n) return 0.0;
    double term = divided_difference(pts, 0, k, memo);
    for (int m = 0; m < k; m++) {
        term *= (x - pts[m].first);
    }
    return term + newton_interpolate(pts, x, n, memo, k + 1);
}

int main() {
    vector<pair<double, double>> all_pts = {{0, 9.81}, {20000, 9.7487}, {40000, 9.6879}, {60000, 9.6879}, {80000, 9.5682}};
    map<pair<int, int>, double> memo;
    
    vector<pair<double, double>> linear_pts = {all_pts[0], all_pts[4]};
    cout << "Linear (2 pts): " << newton_interpolate(linear_pts, 42235, 2, memo) << endl;
    
    memo.clear();
    vector<pair<double, double>> quad_pts = {all_pts[0], all_pts[2], all_pts[4]};
    cout << "Quadratic (3 pts): " << newton_interpolate(quad_pts, 42235, 3, memo) << endl;
    
    memo.clear();
    cout << "4th order (5 pts): " << newton_interpolate(all_pts, 42235, 5, memo) << endl;
    
    return 0;
}