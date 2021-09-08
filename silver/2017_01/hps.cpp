#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("hps");
    int N; cin >> N;
    int h[N+1], p[N+1], s[N+1];
    h[0] = 0;
    p[0] = 0;
    s[0] = 0;
    for (int i = 0; i < N; ++i) {
        h[i+1] = h[i];
        p[i+1] = p[i];
        s[i+1] = s[i];
        char c; cin >> c;
        if (c == 'H') h[i+1]++;
        else if (c == 'P') p[i+1]++;
        else s[i+1]++;
    }
    int ans = 0;
    ans = max({h[N], p[N], s[N]});
    for (int i = 0; i <= N; ++i) {
        int max_h = max(h[i]+p[N]-p[i], h[i]+s[N]-s[i]);
        int max_s = max(s[i]+p[N]-p[i], s[i]+h[N]-h[i]);
        int max_p = max(p[i]+s[N]-s[i], p[i]+h[N]-h[i]);
        ans = max({ans, max_h, max_p, max_s});
    }
    cout << ans << "\n";
    return 0;
}