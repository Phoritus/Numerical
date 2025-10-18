#include <bits/stdc++.h>
using namespace std;

double lagrangePolyCombined(int n, double x, const vector<pair<double,double>>& pts) {    
    double totalSum = 0.0; 
    for (int j = 0; j < n; j++) {
        double Lj = 1.0;
        for (int i = 0; i < n; i++) {
            if (i == j) continue;
            Lj *= (pts[i].first - x) / (pts[i].first - pts[j].first);
        }   
        totalSum += pts[j].second * Lj; 
    }
    return totalSum;
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
    cout << "Linear (Combined):     " << lagrangePolyCombined(2, x, linear) << endl;
    vector<pair<double,double>> quandratic = {pts[0], pts[2], pts[4]};
    cout << "Quadratic (Combined): " << lagrangePolyCombined(3, x, quandratic) << endl;
    cout << "Polynomial (Combined): " << lagrangePolyCombined(5, x, pts) << endl;
    return 0;
}
