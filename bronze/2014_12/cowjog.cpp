#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("cowjog");
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; ++i) {
        int x, s;
        cin >> x >> s;
        pos[i] = pair<int, int>(x, s);
    }
    sort(pos.begin(), pos.end());
    int s = pos[n-1].second;
    int ans = 1;
    for (auto it = pos.rbegin()+1; it != pos.rend(); it++) {
        if (it->second <= s) {
            ans++;
            s = it->second;
        }
    }
    cout << ans << endl;
    return 0;
}