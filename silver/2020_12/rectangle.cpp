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

int psum[2501][2501];

int main() {
    setIO("");
    int N; cin >> N;
    pair<int, int> arr_x[2500];
    pair<int, int> arr_y[2500];
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        arr_x[i] = {x, i};
        arr_y[i] = {y, i};
    }
    sort(arr_x, arr_x + N);
    sort(arr_y, arr_y + N);
    pair<int, int> points[N];
    for (int i = 0; i < N; ++i) {
        points[arr_x[i].second].first = i+1;
        points[arr_y[i].second].second = i+1;
    }
    for (int i = 0; i < N; ++i) {
        psum[points[i].first][points[i].second] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            pair<int, int> p1 = points[i];
            pair<int, int> p2 = points[j];
            int x1 = min(p1.first, p2.first);
            int x2 = max(p1.first, p2.first);
            int y1 = min(p1.second, p2.second);
            int y2 = max(p1.second, p2.second);
            int psum1 = psum[x1][y2] - psum[x1][y1-1];
            int psum2 = psum[N][y2] - psum[x2-1][y2] - psum[N][y1-1] + psum[x2-1][y1-1];
            ans += psum1 * psum2;
        }
    }
    cout << ans + 1 << "\n";  // add the empty box
    return 0;
}