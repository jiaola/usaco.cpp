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
    setIO("diamond");
    int N, K; cin >> N >> K;
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int lp = 0, rp = 0;
    int m = 0;
    int lp_max = 0;
    while (rp < N) {
        if (d[lp] + K >= d[rp]) {
            int cur = rp - lp + 1;
            if (cur > m) {
                lp_max = lp;
                m = cur;
            }
            rp++;
        } else {
            lp++;
        }
    }
    d.erase(d.begin() + lp_max, d.begin() + lp_max + m);
    int ans = m;
    m = 0, lp = 0, rp = 0;
    while (rp < d.size()) {
        if (d[lp] + K >= d[rp]) {
            m = max(rp - lp + 1, m);
            rp++;
        } else {
            lp++;
        }
    }
    cout << ans + m << "\n";

    return 0;
}