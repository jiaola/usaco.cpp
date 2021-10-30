#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("pairup");
    int N; cin >> N;
    pair<int, int> p[N];
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        p[i] = {y, x};
    }
    int ans = 0;
    sort(p, p+N);
    int lp = 0, rp = N-1;
    while (lp <= rp) {
        ans = max(ans, p[lp].first + p[rp].first);
        if (p[lp].second > p[rp].second) {
            p[lp].second -= p[rp--].second;
        } else if (p[lp].second < p[rp].second) {
            p[rp].second -= p[lp++].second;
        } else {
            lp++;
            rp--;
        }
    }
    cout << ans << "\n";
    return 0;
}