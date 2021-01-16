#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int p[3];

int main() {
    setIO("herding");
    for (int i = 0; i < 3; ++i) {
        cin >> p[i];
    }
    sort(p, p+3);
    if (p[1] - p[0] == 1 && p[2] - p[1] == 1) {
        cout << 0 << endl;
    }
    else if (p[1] - p[0] == 2 || p[2] - p[1] == 2) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    int m = max(p[1] - p[0], p[2] - p[1]);
    cout << m - 1 << endl;
    return 0;
}