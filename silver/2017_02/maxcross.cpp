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
    setIO("maxcross");
    int N, K, B; cin >> N >> K >> B;
    int p[N+1]; p[0] = 0;
    int l[N+1];
    fill(l, l+N+1, 0);
    for (int i = 0; i < B; ++i) {
        int x; cin >> x;
        l[x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        p[i] = p[i-1] + l[i];
    }
    int ans = N;
    for (int i = K; i <= N; i++) {
        ans = min(ans, p[i] - p[i-K]);
    }
    cout << ans << "\n";
    return 0;
}