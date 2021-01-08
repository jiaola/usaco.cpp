#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void) {
    setIO("paint");
    int a, b, c, d, t = 0;
    cin >> a >> b >> c >> d;
    int l = min({a, b, c, d});
    int r = max({a, b, c, d});
    for (int i = l; i <= r ; ++i) {
        if ((a <= i and i < b) or (c <= i and i < d)) {
            t++;
        }
    }
    cout << t << endl;
    return 0;
}

