#include <bits/stdc++.h>
using namespace std;

double lagrangeBasisRec(int j, int i, int n, double x, const vector<pair<double,double>>& pts) {
    if (i == n) return 1.0;
    if (i == j) return lagrangeBasisRec(j, i+1, n, x, pts);
    return (pts[i].first - x) / (pts[i].first - pts[j].first) 
           * lagrangeBasisRec(j, i+1, n, x, pts);
}

double lagrangePolyRec(int j, int n, double x, const vector<pair<double,double>>& pts) {
    if (j == n) return 0.0;
    double Lj = lagrangeBasisRec(j, 0, n, x, pts);
    return pts[j].second * Lj + lagrangePolyRec(j+1, n, x, pts);
}

int main() {
    vector<pair<double,double>> pts = {
        {0, 9.81},
        {20000, 9.7487},
        {40000, 9.6879},
        {60000, 9.6879},
        {80000, 9.5682}
    };

    double x = 42235;
    vector<pair<double,double>> linear = {pts[0], pts[4]};
    cout << lagrangePolyRec(0, 2, x, linear) << endl;
    
    vector<pair<double,double>> quandratic = {pts[0], pts[2], pts[4]};
    cout << lagrangePolyRec(0, 3, x, quandratic) << endl;
    
    cout << lagrangePolyRec(0, 5, x, pts) << endl;
}