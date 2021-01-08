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
    setIO("haybales");
    int N, Q;
    cin >> N >> Q;
    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    sort(h, h+N);
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        int ub = upper_bound(h, h+N, b) - h;
        int lb = lower_bound(h, h+N, a) - h;
        cout << ub - lb << endl;
    }
    return 0;
}