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
    setIO("paintbarn");
    int N, K; cin >> N >> K;
    int fence[1001][1001] = {};
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        fence[x1][y1]++;
        fence[x2][y2]++;
        fence[x1][y2]--;
        fence[x2][y1]--;
    }
    int ans = 0;
    int ps[1002][1002];
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (i * j) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + fence[i-1][j-1];
                if (ps[i][j] == K) ans++;
            } else {
                ps[i][j] = 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}