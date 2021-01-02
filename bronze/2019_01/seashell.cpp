#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void) {
    setIO("shell");
    int N, s1, s2, g;
    int g1 = 0, g2 = 0, g3 = 0;
    int p1 = 1, p2 = 2, p3 = 3;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s1 >> s2 >> g;
        if (p1 == s1) {
            p1 = s2;
        } else if (p1 == s2) {
            p1 = s1;
        }
        if (p2 == s1) {
            p2 = s2;
        } else if (p2 == s2) {
            p2 = s1;
        }
        if (p3 == s1) {
            p3 = s2;
        } else if (p3 == s2) {
            p3 = s1;
        }
        if (g == p1) {
            g1++;
        } else if (g == p2) {
            g2++;
        } else if (g == p3) {
            g3++;
        }
    }
    int m = max({g1, g2, g3});
    cout << m;
}

