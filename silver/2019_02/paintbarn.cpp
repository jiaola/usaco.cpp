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
        for (int j = x1; j < x2; ++j) {
            fence[j][y1]++;
            fence[j][y2]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < 1001; ++i) {
        int ps = 0;
        for (int j = 1; j <= 1001; ++j) {
            ps += fence[i][j-1];
            if (ps == K) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}