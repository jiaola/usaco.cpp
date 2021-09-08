#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("div7");
    int N; cin >> N;
    long long p[N+1]; p[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int a; cin >> a;
        p[i] = p[i-1] + a;
    }
    for (int i = 0; i < N+1; i++) {
        p[i] %= 7;
    }
    int max_pos[7] = {0};
    int min_pos[7];
    fill(min_pos, min_pos+7, N+1);
    for (int i = 0; i < N+1; ++i) {
        int r = int(p[i]);
        max_pos[r] = max(max_pos[r], i);
        min_pos[r] = min(min_pos[r], i);
    }
    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        ans = max(ans, max_pos[i] - min_pos[i]);
    }
    cout << ans << "\n";
    return 0;
}