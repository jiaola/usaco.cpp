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
    setIO("lazy");
    int N, K; cin >> N >> K;
    int p[N][N+1];
    for (int i = 0; i < N; ++i) {
        p[i][0] = 0;
        for (int j = 1; j <= N; ++j) {
            int g; cin >> g;
            p[i][j] = p[i][j - 1] + g;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int s = 0;
            int top = max(0, i-K);
            int bottom = min(N-1, i+K);
            for (int k = top; k <= bottom; ++k) {
                int d = abs(i - k);
                int first = max(0, j-(K-d));
                int last = min(N-1, j+(K-d));
                s += p[k][last+1] - p[k][first];
            }
            ans = max(ans, s);
        }
    }
    cout << ans << "\n";
    return 0;
}