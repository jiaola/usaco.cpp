#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        v[i] = make_pair(x, i+1);
    }
    sort(v.begin(), v.begin() + 2*n);
    vector<pair<int, int>> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first != v[i+n].first) {
            cnt++;
        }
        ans[i] = make_pair(v[i].second, v[i+n].second);
    }
    cout << cnt << "\n";
    for (auto &p: ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
