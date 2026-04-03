#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int>> x = {{1,0,0,1},{0,1,1,0}};
    bool ok = true;

    int nRobos = 0;
    for (int v : x[0]) if (v == 1) nRobos++;

    for (int i = 0; i < (int)x.size() && ok; i++) {
        int count = 0;
        for (int v : x[i]) if (v == 1) count++;

        if (count != nRobos) { ok = false; break; }
        if (i == 0) continue;

        vector<int> prev, curr;
        for (int j = 0; j < (int)x[i].size(); j++) {
            if (x[i-1][j] == 1) prev.push_back(j);
            if (x[i][j]   == 1) curr.push_back(j);
        }
        for (int h = 0; h < (int)curr.size(); h++) {
            if (abs(prev[h] - curr[h]) > 1) { ok = false; break; }
        }
    }
    cout << boolalpha << ok << endl;
    return 0;
}