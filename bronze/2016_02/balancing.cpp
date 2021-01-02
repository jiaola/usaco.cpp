#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;


void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void) {
    setIO("balancing");
    int N, B;
    cin >> N >> B;
    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    int m = 100;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int a = x[i] + 1;
            int b = y[j] + 1;
            int c[4] = {0, 0, 0, 0};
            for (int k = 0; k < N; ++k) {
                if (x[k] < a && y[k] < b) {
                    c[0]++;
                } else if (x[k] < a && y[k] >= b) {
                    c[1]++;
                } else if (x[k] >= a && y[k] >= b) {
                    c[2]++;
                } else if (x[k] >= a && y[k] < b) {
                    c[3]++;
                }
            }
            m = min(m, *max_element(c, c+4));
        }
    }
    cout << m;
}